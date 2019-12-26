//
//  main.cpp
//  LLVMLan
//
//  Created by 梁仕钢 on 2019/12/20.
//  Copyright © 2019 梁仕钢. All rights reserved.
//
#include "include/KaleidoscopeJIT.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace llvm;
using namespace llvm::orc;
// Lexer
enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5,
    tok_if = -6,
    tok_then = -7,
    tok_else = -8,
    tok_for = -9,
    tok_in = -10,
    tok_binary = -11,
    tok_unary = -12,
    tok_var = -13,
    tok_block_open = -14,
    tok_block_end = -15
};

static std::string IdentifierStr;
static double NumVal;
static int anonFnNum = 0;

static int getTok() {
    static int lastChar = ' ';
    while(isspace(lastChar))
        lastChar = getchar();
    if(isalpha(lastChar)) {
        IdentifierStr = lastChar;
        while (isalnum((lastChar = getchar()))) {
            IdentifierStr += lastChar;
        }
        if(IdentifierStr == "def"){
            return tok_def;
        }
        if(IdentifierStr == "extern"){
            return tok_extern;
        }
        if(IdentifierStr == "if"){
            return tok_if;
        }
        if(IdentifierStr == "then"){
            return tok_then;
        }
        if(IdentifierStr == "else"){
            return tok_else;
        }
        if(IdentifierStr == "for"){
            return tok_for;
        }
        if(IdentifierStr == "in"){
            return tok_in;
        }
        if(IdentifierStr == "binary"){
            return tok_binary;
        }
        if(IdentifierStr == "unary"){
            return tok_unary;
        }
        if(IdentifierStr == "var"){
            return tok_var;
        }
        return tok_identifier;
    }

    if(isdigit(lastChar)|| lastChar == '.'){
        std::string numStr;
        do{
            numStr += lastChar;
            lastChar = getchar();
        }while (isdigit(lastChar)|| lastChar == '.');
        NumVal = strtod(numStr.c_str(), nullptr);
        return tok_number;
    }

    if(lastChar == '#'){
        do{
            lastChar = getchar();
        }while(lastChar!=EOF && lastChar!='\n'&&lastChar!='\r');
        if(lastChar!=EOF){
            return getTok();
        }
    }

    if(lastChar == '{'){
        lastChar = getchar();
        return tok_block_open;
    }

    if(lastChar == '}'){
        lastChar = getchar();
        return tok_block_end;
    }

    if(lastChar == EOF){
        return tok_eof;
    }
    int thisChar = lastChar;
    lastChar = getchar();
    return thisChar;
}

// AST
namespace {
// Base Node
class ExprAST {
public:
    virtual ~ExprAST() = default;
    virtual Value *codeGen() = 0;
};
class BlockExprAST: public ExprAST {
    std::vector<std::unique_ptr<ExprAST>> exprs;
public:
    BlockExprAST(std::vector<std::unique_ptr<ExprAST>> exprs): exprs(std::move(exprs)){}
    Value *codeGen() override ;
};
class NumberExprAST: public ExprAST {
    double val;
public:
    NumberExprAST(double val):val(val){}
    Value *codeGen() override ;
};
class VariableExprAST:public ExprAST {
    std::string name;
public:
    VariableExprAST(const std::string &name):name(name){}
    std::string getName(){return name;}
    Value *codeGen() override ;
};
class BinaryExprAST:public ExprAST {
    char op;
    std::unique_ptr<ExprAST> LHS,RHS;
public:
    BinaryExprAST(char op,std::unique_ptr<ExprAST> LHS,std::unique_ptr<ExprAST> RHS):op(op),LHS(std::move(LHS)),RHS(std::move(RHS)) {}
    Value *codeGen() override ;
};
class UnaryExprAST:public ExprAST{
    char opCode;
    std::unique_ptr<ExprAST> operand;
public:
    UnaryExprAST(char opcode,std::unique_ptr<ExprAST> operand):opCode(opcode),operand(std::move(operand)){}
    Value *codeGen() override ;
};
class CallExprAST:public ExprAST {
    std::string callee;
    std::vector<std::unique_ptr<ExprAST>> args;
public:
    CallExprAST(const std::string &callee,std::vector<std::unique_ptr<ExprAST>> args):callee(callee),args(std::move(args)) {}
    Value *codeGen() override ;
};
class VarExprAST:public ExprAST {
    std::vector<std::pair<std::string,std::unique_ptr<ExprAST>>> varNames;
    std::unique_ptr<ExprAST> body;
public:
    VarExprAST(std::vector<std::pair<std::string,std::unique_ptr<ExprAST>>> varNames,std::unique_ptr<ExprAST> body)
    :varNames(std::move(varNames)),body(std::move(body)){}
    Value *codeGen() override ;

};
class IfExprAST:public ExprAST{
    std::unique_ptr<ExprAST> cond,then,elxe;
public:
    IfExprAST(std::unique_ptr<ExprAST> cond,std::unique_ptr<ExprAST> then,std::unique_ptr<ExprAST> elxe):cond(std::move(cond)),then(std::move(then)),elxe(std::move(elxe)){}
    Value *codeGen() override ;
};
class ForExprAST:public ExprAST{
    std::string varName;
    std::unique_ptr<ExprAST> start,end,step,body;
public:
    ForExprAST(const std::string &varName,std::unique_ptr<ExprAST> start,std::unique_ptr<ExprAST> end,
               std::unique_ptr<ExprAST> step,std::unique_ptr<ExprAST> body)
               :varName(varName),start(std::move(start)),end(std::move(end)),step(std::move(step)),body(std::move(body)){}
    Value *codeGen() override ;
};
class PrototypeAST {
    std::string name;
    std::vector<std::string> args;
    bool isOperator;
    unsigned precedence;
public:
    PrototypeAST(const std::string &name,std::vector<std::string> args,bool isOperator = false, unsigned prec = 0):name(name),args(std::move(args)),isOperator(isOperator),precedence(prec){}
    const std::string &getName() const {return name;}
    Function *codeGen();

    bool isUnaryOp() const { return isOperator && args.size() == 1;}
    bool isBinaryOp() const {return isOperator && args.size() == 2;}

    char getOperatorName() const {
        assert(isUnaryOp()||isBinaryOp());
        return name[name.size()-1];
    }

    unsigned getBinaryPrecedence() const {return precedence;}
};
class FunctionAST {
    std::unique_ptr<PrototypeAST> proto;
    std::unique_ptr<ExprAST> body;
public:
    FunctionAST(std::unique_ptr<PrototypeAST> proto,std::unique_ptr<ExprAST> body):proto(std::move(proto)),body(std::move(body)){}
    Function *codeGen();
    std::unique_ptr<PrototypeAST> *getProto(){
        return &proto;
    }
};
}

//Parser
static int curTok;
static int getNextTok(){
    return curTok = getTok();
}
static std::map<char, int> binopPrecedence;
static int getTokPrecedence(){
    if(!isascii(curTok))
        return -1;
    int tokPrec = binopPrecedence[curTok];
    if(tokPrec <= 0)
        return -1;
    return tokPrec;
}
std::unique_ptr<ExprAST> logError(const char *str){
    fprintf(stderr,"Error: %s\n",str);
    return nullptr;
}
std::unique_ptr<PrototypeAST> logErrorP(const char *str){
    logError(str);
    return nullptr;
}
static std::unique_ptr<ExprAST> parseExpression();

static std::unique_ptr<ExprAST> parseNumberExpr() {
    auto result = llvm::make_unique<NumberExprAST>(NumVal);
    getNextTok();
    return std::move(result);
}
static std::unique_ptr<ExprAST> parseParenExpr() {
    getNextTok();
    auto v = parseExpression();
    if(!v)
        return nullptr;
    if(curTok!= ')')
        return logError("expected ')'");
    getNextTok();
    return v;
}
static std::unique_ptr<ExprAST> parseIdentifierExpr() {
    std::string idName = IdentifierStr;
    getNextTok();
    if(curTok!='(')
        return llvm::make_unique<VariableExprAST>(idName);
    getNextTok();
    std::vector<std::unique_ptr<ExprAST>> args;
    if(curTok!=')'){
        while (true) {
            if(auto arg = parseExpression())
                args.push_back(std::move(arg));
            else
                return nullptr;
            if(curTok == ')')
                break;
            if(curTok!=',')
                return logError("Expected ')' or ',' in argument list");
            getNextTok();
        }
    }
    getNextTok();
    return llvm::make_unique<CallExprAST>(idName,std::move(args));
}
static std::unique_ptr<ExprAST> parseIfExpr() {
    getNextTok();
    auto cond = parseExpression();
    if(!cond)
        return nullptr;
    if(curTok!=tok_then)
        return logError("expected then");
    getNextTok();
    std::unique_ptr<ExprAST> then;
    if(curTok == tok_block_open){
        curTok = ';';//eat '{'
        std::vector<std::unique_ptr<ExprAST>> body;
        fprintf(stderr,"enter\n");
        while (auto e = parseExpression()){
            body.push_back(std::move(e));
        }
        fprintf(stderr,"out\n");
        getNextTok();
        then = llvm::make_unique<BlockExprAST>(std::move(body));

    } else{
        then = parseExpression();
    }
    if(!then)
        return nullptr;
    if(curTok!=tok_else)
        return logError("expected else");
    getNextTok();
    std::unique_ptr<ExprAST> elxe;
    if(curTok == tok_block_open){
        curTok = ';';//eat '{'
        std::vector<std::unique_ptr<ExprAST>> body;
        fprintf(stderr,"enter\n");
        while (auto e = parseExpression()){
            body.push_back(std::move(e));
        }
        fprintf(stderr,"out\n");
        curTok = ';';
        elxe = llvm::make_unique<BlockExprAST>(std::move(body));

    } else{
        elxe = parseExpression();
    }
    if(!elxe){
        return nullptr;
    }
    return llvm::make_unique<IfExprAST>(std::move(cond),std::move(then),std::move(elxe));
}
static std::unique_ptr<ExprAST> parseForExpr() {
    getNextTok();
    if(curTok!=tok_identifier)
        return logError("excepted identifier after for");
    std::string idName = IdentifierStr;
    getNextTok();
    if(curTok!='=')
        return logError("expected '=' after for");
    getNextTok();
    auto start = parseExpression();
    if(!start)
        return nullptr;
    if(curTok!=',')
        return logError("expected ',' after for start value");
    getNextTok();
    auto end = parseExpression();
    if(!end)
        return nullptr;
    std::unique_ptr<ExprAST> step;
    if(curTok == ','){
        getNextTok();
        step = parseExpression();
        if(!step)
            return nullptr;
    }
    if(curTok!=tok_in)
        return logError("expected in after for");
    getNextTok();
    if(curTok == tok_block_open){
        curTok = ';';//eat '{'
        std::vector<std::unique_ptr<ExprAST>> body;
        while (auto e = parseExpression()){
            body.push_back(std::move(e));
        }
        curTok = ';';
        std::unique_ptr<BlockExprAST> block = llvm::make_unique<BlockExprAST>(std::move(body));
        if(!block){
            return nullptr;
        }
        return llvm::make_unique<ForExprAST>(idName,std::move(start),std::move(end),std::move(step),std::move(block));

    }
    auto body = parseExpression();
    if(!body)
        return nullptr;
    return llvm::make_unique<ForExprAST>(idName,std::move(start),std::move(end),std::move(step),std::move(body));
}
static std::unique_ptr<ExprAST> parseVarExpr() {
    getNextTok();
    std::vector<std::pair<std::string,std::unique_ptr<ExprAST>>> varNames;
    if(curTok!=tok_identifier)
        return logError("excepted identifier after var");
    while (1) {
        std::string name = IdentifierStr;
        getNextTok();
        std::unique_ptr<ExprAST> init;
        if(curTok == '='){
            getNextTok();
            init = parseExpression();
            if(!init)
                return nullptr;
        }
        varNames.push_back(std::make_pair(name,std::move(init)));
        if(curTok!=',')
            break;
        getNextTok();
        if(curTok!=tok_identifier)
            return logError("excepted identifier list after var");
    }
    if(curTok!=tok_in)
        return logError("excepted 'in' keyword after 'var'");
    getNextTok();
    auto body = parseExpression();
    if(!body)
        return nullptr;
    return llvm::make_unique<VarExprAST>(std::move(varNames),std::move(body));
}
static std::unique_ptr<ExprAST> parsePrimary(){
    switch (curTok) {
        case tok_identifier:
            return parseIdentifierExpr();
        case tok_number:
            return parseNumberExpr();
        case '(':
            return parseParenExpr();
        case tok_if:
            return parseIfExpr();
        case tok_for:
            return parseForExpr();
        case tok_var:
            return parseVarExpr();
        case tok_block_open:
            return nullptr;
        case tok_block_end:
            return nullptr;
        default:
            return logError("Unknow token when excepting an expression");
    }
}
static std::unique_ptr<ExprAST> parseUnary() {
    if(curTok == ';')
        getNextTok();
    if(!isascii(curTok)||curTok=='('||curTok==')')
        return parsePrimary();
    int opc = curTok;
    getNextTok();
    if(auto operand = parseUnary())
        return llvm::make_unique<UnaryExprAST>(opc,std::move(operand));
    return nullptr;
}
static std::unique_ptr<ExprAST> parseBinOpRHS(int exprPrex,std::unique_ptr<ExprAST> LHS){
    while (true) {
        int tokPrec = getTokPrecedence();
        if(tokPrec<exprPrex)
            return LHS;
        int binOp = curTok;
        getNextTok();
        auto RHS = parseUnary();
        if(!RHS)
            return nullptr;
        int nextPrec = getTokPrecedence();
        if(tokPrec<nextPrec){
            RHS = parseBinOpRHS(tokPrec + 1, std::move(RHS));
            if(!RHS)
                return nullptr;
        }
        LHS = llvm::make_unique<BinaryExprAST>(binOp,std::move(LHS),std::move(RHS));
    }
}
static std::unique_ptr<ExprAST> parseExpression() {
    auto LHS = parseUnary();
    if(!LHS)
        return nullptr;
    return parseBinOpRHS(0, std::move(LHS));
}
static std::unique_ptr<PrototypeAST> parsePrototype() {
    std::string fnName;
    unsigned kind = 0;
    unsigned binaryPrecedence = 30;
    switch (curTok) {
        default:
            return logErrorP("excepted function name in prototype");
        case tok_identifier:
            fnName = IdentifierStr;
            kind = 0;
            getNextTok();
            break;
        case tok_unary:
            getNextTok();
            if(!isascii(curTok))
                return logErrorP("expected unary operator");
            fnName = "unary";
            fnName += (char)curTok;
            kind = 1;
            getNextTok();
            break;
        case tok_binary:
            getNextTok();
            if(!isascii(curTok))
                return logErrorP("excepted binary operator");
            fnName = "binary";
            fnName += (char)curTok;
            kind = 2;
            getNextTok();
            if(curTok == tok_number){
                if(NumVal<1||NumVal>100)
                    return logErrorP("Invalid precedence must be 1..100");
                binaryPrecedence = (unsigned)NumVal;
                getNextTok();
            }
            break;
    }
    if(curTok!='(')
        return logErrorP("Excepted '(' in prototype");
    std::vector<std::string> argNames;
    while (getNextTok() == tok_identifier) {
        argNames.push_back(IdentifierStr);
    }
    if(curTok!=')')
        return logErrorP("Excepted ')' in prototype");
    getNextTok();
    if(kind && argNames.size()!=kind)
        return logErrorP("Invalid number of operands for operator");
    return llvm::make_unique<PrototypeAST>(fnName,std::move(argNames),kind!=0,binaryPrecedence);
}
static std::unique_ptr<FunctionAST> parseDefinition() {
    getNextTok();
    auto proto = parsePrototype();
    if(!proto)
        return nullptr;
    if(curTok == tok_block_open){
        curTok = ';';//eat '{'
        std::vector<std::unique_ptr<ExprAST>> body;
        while (auto e = parseExpression()){
            body.push_back(std::move(e));
        }
        curTok = ';';
        std::unique_ptr<BlockExprAST> block = llvm::make_unique<BlockExprAST>(std::move(body));
        if(!block){
            return nullptr;
        }
        return llvm::make_unique<FunctionAST>(std::move(proto),std::move(block));

    }
    if (auto e = parseExpression()){
        return llvm::make_unique<FunctionAST>(std::move(proto),std::move(e));
    }
    return nullptr;
}
static std::unique_ptr<FunctionAST> parseTopLevelExpr() {
    if(auto e = parseExpression()){
        auto proto = llvm::make_unique<PrototypeAST>(std::to_string(anonFnNum++),std::vector<std::string>());
        return llvm::make_unique<FunctionAST>(std::move(proto),std::move(e));
    }
    return nullptr;
}
static std::unique_ptr<PrototypeAST> parseExtern() {
    getNextTok();
    return parsePrototype();
}

// Code Gen
static LLVMContext context;
static IRBuilder<> builder(context);
static std::unique_ptr<Module> module;
static std::map<std::string,AllocaInst *> namedValues;
static std::unique_ptr<legacy::FunctionPassManager> fpm;
static std::unique_ptr<KaleidoscopeJIT> jit;
static std::map<std::string, std::unique_ptr<PrototypeAST>> functionProtos;

Value *logErrorV(const char *str){
    logError(str);
    return nullptr;
}
static AllocaInst *CreateEntryBlockAlloca(Function *theFunction,const std::string &varName) {
    IRBuilder<> tmpB(&theFunction->getEntryBlock(),theFunction->getEntryBlock().begin());
    return tmpB.CreateAlloca(Type::getDoubleTy(context),0,varName.c_str());
}
Function *getFunction(std::string name){
    if(auto *f = module->getFunction(name))
        return f;
    auto fi = functionProtos.find(name);
    if(fi!=functionProtos.end())
        return fi->second->codeGen();
    return nullptr;
}
Value *NumberExprAST::codeGen() {
    return ConstantFP::get(context,APFloat(val));
}

Value *VariableExprAST::codeGen() {
    Value *v = namedValues[name];
    if(!v){
        return logErrorV("Unknown variable name");
    }
    return builder.CreateLoad(v,name.c_str());
}

Value *BlockExprAST::codeGen() {
    for(int i=0;i<exprs.size()-1;++i){
        exprs[i]->codeGen();
    }
    return exprs[exprs.size()-1]->codeGen();
}

Value *UnaryExprAST::codeGen() {
    Value *operandV = operand->codeGen();
    if(!operandV)
        return nullptr;
    Function *f = getFunction(std::string("unary")+opCode);
    if(!f)
        return logErrorV("Unknown unary operator");
    return builder.CreateCall(f,operandV,"unop");
}

Value *BinaryExprAST::codeGen() {
    if(op == '='){
        VariableExprAST *LHSE = dynamic_cast<VariableExprAST*>(LHS.get());
        if(!LHSE)
            return logErrorV("destination of '=' must be a variable");
        Value *val = RHS->codeGen();
        if(!val)
            return nullptr;
        Value *variable = namedValues[LHSE->getName()];
        if(!variable)
            return logErrorV("unknown variable name");
        builder.CreateStore(val,variable);
        return val;
    }
    Value *r = RHS->codeGen();
    Value *l = LHS->codeGen();
    if(!l||!r){
        return nullptr;
    }
    switch (op){
        case '+':
        {
            return builder.CreateFAdd(l,r,"addtmp");
        }
        case '-':
        {
            return builder.CreateFSub(l,r,"subtmp");
        }
        case '*':
        {
            return builder.CreateFMul(l,r,"multmp");
        }
        case '<':
        {
            l = builder.CreateFCmpULT(l,r,"cmptmp");
            return builder.CreateUIToFP(l,Type::getDoubleTy(context),"booltmp");
        }
        default:
            break;
    }
    Function *f = getFunction(std::string("binary")+op);
    assert(f&&"binary operator not found;");
    Value *ops[2] = {l,r};
    return builder.CreateCall(f,ops,"binop");
}

Value *CallExprAST::codeGen() {
    Function *calleeF = getFunction(callee);
    if(!calleeF)
        return logErrorV("Unknown function referenced");
    if(calleeF->arg_size()!=args.size())
        return logErrorV("Incorrect argument passed");
    std::vector<Value *> argsV;
    for(unsigned i=0,e = args.size();i!=e;++i){
        argsV.push_back(args[i]->codeGen());
        if(!argsV.back())
            return nullptr;
    }
    return builder.CreateCall(calleeF,argsV,"calltmp");
}

Value *IfExprAST::codeGen() {
    Value *condV = cond->codeGen();
    if(!condV)
        return nullptr;
    condV = builder.CreateFCmpONE(condV,ConstantFP::get(context,APFloat(0.0)),"ifcond");
    Function *theFunction = builder.GetInsertBlock()->getParent();
    BasicBlock *thenBB = BasicBlock::Create(context,"then",theFunction);
    BasicBlock *elseBB = BasicBlock::Create(context,"else");
    BasicBlock *mergeBB = BasicBlock::Create(context,"ifcont");
    builder.CreateCondBr(condV,thenBB,elseBB);
    builder.SetInsertPoint(thenBB);
    Value *thenV = then->codeGen();
    if(!thenV)
        return nullptr;
    builder.CreateBr(mergeBB);
    thenBB = builder.GetInsertBlock();
    theFunction->getBasicBlockList().push_back(elseBB);
    builder.SetInsertPoint(elseBB);
    Value *elseV = elxe->codeGen();
    if(!elseV)
        return nullptr;
    builder.CreateBr(mergeBB);
    elseBB = builder.GetInsertBlock();
    theFunction->getBasicBlockList().push_back(mergeBB);
    builder.SetInsertPoint(mergeBB);
    PHINode *pn = builder.CreatePHI(Type::getDoubleTy(context),2,"iftmp");
    pn->addIncoming(thenV,thenBB);
    pn->addIncoming(elseV,elseBB);
    return pn;
}

Value *ForExprAST::codeGen() {
    Function *theFunction = builder.GetInsertBlock()->getParent();
    AllocaInst *alloca = CreateEntryBlockAlloca(theFunction,varName);
    Value *startV = start->codeGen();
    if(!startV)
        return nullptr;
    builder.CreateStore(startV,alloca);
    BasicBlock *loopBB = BasicBlock::Create(context,"loop",theFunction);
    builder.CreateBr(loopBB);
    builder.SetInsertPoint(loopBB);
    AllocaInst * oldVal = namedValues[varName];
    namedValues[varName] = alloca;

    if(!body->codeGen())
        return nullptr;
    Value *stepV = nullptr;
    if(step){
        stepV = step->codeGen();
        if(!stepV)
            return nullptr;
    }else{
        stepV = ConstantFP::get(context,APFloat(1.0));
    }
    Value *endV = end->codeGen();
    if(!endV)
        return nullptr;
    Value *curVar = builder.CreateLoad(alloca,varName.c_str());
    Value *nextVar = builder.CreateFAdd(curVar,stepV,"nextVar");
    builder.CreateStore(nextVar,alloca);
    endV = builder.CreateFCmpONE(endV,ConstantFP::get(context,APFloat(0.0)),"loopcond");
    BasicBlock *loopEndBB = builder.GetInsertBlock();
    BasicBlock *afterBB = BasicBlock::Create(context,"afterloop",theFunction);
    builder.CreateCondBr(endV,loopBB,afterBB);
    builder.SetInsertPoint(afterBB);
    if(oldVal)
        namedValues[varName] = oldVal;
    else
        namedValues.erase(varName);
    return Constant::getNullValue(Type::getDoubleTy(context));
}

Value *VarExprAST::codeGen() {
    std::vector<AllocaInst*> oldBindings;
    Function *theFunction = builder.GetInsertBlock()->getParent();
    for (unsigned i =0,e= varNames.size();i!=e;++i){
        const std::string &varName = varNames[i].first;
        ExprAST *init = varNames[i].second.get();
        Value *initVal;
        if(init){
            initVal = init->codeGen();
            if(!initVal)
                return nullptr;
        } else{
            initVal = ConstantFP::get(context,APFloat(0.0));
        }

        AllocaInst *alloca = CreateEntryBlockAlloca(theFunction,varName);
        builder.CreateStore(initVal,alloca);
        oldBindings.push_back(namedValues[varName]);
        namedValues[varName] = alloca;
    }
    Value *bodyV = body->codeGen();
    if(!bodyV)
        return nullptr;
    for(unsigned i =0,e=varNames.size();i!=e;++i){
        namedValues[varNames[i].first] = oldBindings[i];
    }
    return bodyV;
}
Function *PrototypeAST::codeGen() {
    std::vector<Type *> doubles(args.size(),Type::getDoubleTy(context));
    FunctionType *ft = FunctionType::get(Type::getDoubleTy(context),doubles, false);
    Function *f = Function::Create(ft,Function::ExternalLinkage,name,module.get());
    unsigned idx = 0;
    for(auto &arg : f->args())
        arg.setName(args[idx++]);
    return f;
}

Function *FunctionAST::codeGen() {
    auto &p = *proto;
    functionProtos[proto->getName()] = std::move(proto);
    Function *theFunction = getFunction(p.getName());
    if(!theFunction)
        return nullptr;
    if(p.isBinaryOp())
        binopPrecedence[p.getOperatorName()] = p.getBinaryPrecedence();
    BasicBlock *bb = BasicBlock::Create(context,"entry",theFunction);
    builder.SetInsertPoint(bb);
    namedValues.clear();
    for(auto &arg:theFunction->args()){
        AllocaInst *alloca = CreateEntryBlockAlloca(theFunction,arg.getName());
        builder.CreateStore(&arg,alloca);
        namedValues[arg.getName()] = alloca;
    }
    if(Value *retVal = body->codeGen()){
        builder.CreateRet(retVal);
        verifyFunction(*theFunction);
        fpm->run(*theFunction);
        return theFunction;
    }
    theFunction->eraseFromParent();
    return nullptr;
}

//top-level parsing
static void initializeModuleAndpassManager(void) {
    module = llvm::make_unique<Module>("llvmlan",context);
    module->setDataLayout(jit->getTargetMachine().createDataLayout());

    fpm = llvm::make_unique<legacy::FunctionPassManager>(module.get());
    fpm->add(createDemoteRegisterToMemoryPass());
    fpm->add(createInstructionCombiningPass());
    fpm->add(createReassociatePass());
    fpm->add(createGVNPass());
    fpm->add(createCFGSimplificationPass());
    fpm->doInitialization();
}
static void handleDefinition(){
    if(auto fnAst = parseDefinition()){
        if(auto *fnIR = fnAst->codeGen()){
            fprintf(stderr, "Parsed a function definition.\n");
            fnIR->print(errs());
            fprintf(stderr,"\n");
            jit->addModule(std::move(module));
            initializeModuleAndpassManager();
        }
    }else{
        getNextTok();
    }
}
static void handleExtern(){
    if(auto protoAST = parseExtern()){
        if(auto *fnIR = protoAST->codeGen()){
            fprintf(stderr, "Parsed an exten.\n");
            fnIR->print(errs());
            fprintf(stderr,"\n");
            functionProtos[protoAST->getName()] = std::move(protoAST);
        }
    }else{
        getNextTok();
    }
}
static void handleTopLevelExpression(){
    if(auto fnAST = parseTopLevelExpr()){
        auto fnName = (fnAST->getProto()->get())->getName();
        if(fnAST->codeGen()){
            auto h = jit->addModule(std::move(module));
            initializeModuleAndpassManager();
            auto exprSymbol = jit->findSymbol(fnName);
            assert(exprSymbol && "Function not found");
            double (*fp)() = (double (*)())(intptr_t)cantFail(exprSymbol.getAddress());
            fprintf(stderr,"Evaluated to %f\n",fp());

            jit->removeModule(h);
        }
    }else{
        getNextTok();
    }
}

static void mainLoop(){
    while (true) {
        fprintf(stderr, "ready>");
        switch (curTok) {
            case tok_eof:
                return;
            case ';':
                getNextTok();
                break;
            case tok_def:
                handleDefinition();
                break;
            case tok_extern:
                handleExtern();
                break;
            case tok_block_open:
                getNextTok();
                break;
            case tok_block_end:
                getNextTok();
                break;
            default:
                handleTopLevelExpression();
                break;
        }
    }
}

//===----------------------------------------------------------------------===//
// "Library" functions that can be "extern'd" from user code.
//===----------------------------------------------------------------------===//

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

/// putchard - putchar that takes a double and returns 0.
extern "C" DLLEXPORT double putchard(double X) {
    fputc((char)X, stderr);
    return 0;
}

/// printd - printf that takes a double prints it as "%f\n", returning 0.
extern "C" DLLEXPORT double printd(double X) {
    fprintf(stderr, "%f\n", X);
    return 0;
}


int main() {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    binopPrecedence['='] = 2;
    binopPrecedence['<'] = 10;
    binopPrecedence['+'] = 20;
    binopPrecedence['-'] = 20;
    binopPrecedence['*'] = 40;

    fprintf(stderr, "ready>");
    getNextTok();

    jit = llvm::make_unique<KaleidoscopeJIT>();
    initializeModuleAndpassManager();

    mainLoop();
    return 0;
}
