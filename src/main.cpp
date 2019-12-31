#include <iostream>
#include "antlr/antlr4-runtime.h"
#include "antlrgen/WenyanLexer.h"
#include "antlrgen/WenyanParser.h"
#include "antlrgen/WenyanBaseListener.h"
#include "jit/KaleidoscopeJIT.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include <cctype>
#include "util.h"


using namespace antlr4;
using namespace llvm;
using namespace llvm::orc;

class PrototypeAST;

static LLVMContext theLLVMContext;
static IRBuilder<> builder(theLLVMContext);
static std::unique_ptr<Module> module;
static std::unique_ptr<Module> globalVarModule  = llvm::make_unique<Module>("llvmGV",theLLVMContext);;
static std::map<std::string,AllocaInst *> namedValues;
static std::unique_ptr<legacy::FunctionPassManager> fpm;
static std::unique_ptr<KaleidoscopeJIT> jit;
static std::map<std::string, std::unique_ptr<PrototypeAST>> functionProtos;


class PrototypeAST {
    std::string name;
    std::vector<std::string> args;
public:
    PrototypeAST(const std::string &name,std::vector<std::string> args,bool isOperator = false, unsigned prec = 0):name(name),args(std::move(args)){}
    const std::string &getName() const {return name;}
    Function *codeGen();

};

Function *PrototypeAST::codeGen() {
    std::vector<Type *> doubles(args.size(),Type::getDoubleTy(theLLVMContext));
    FunctionType *ft = FunctionType::get(Type::getDoubleTy(theLLVMContext),doubles, false);
    Function *f = Function::Create(ft,Function::ExternalLinkage,name,module.get());
    unsigned idx = 0;
    for(auto &arg : f->args())
        arg.setName(args[idx++]);
    return f;
}

static AllocaInst *CreateEntryBlockAlloca(Function *theFunction,const std::string &varName) {
    IRBuilder<> tmpB(&theFunction->getEntryBlock(),theFunction->getEntryBlock().begin());
    return tmpB.CreateAlloca(Type::getDoubleTy(theLLVMContext),0,varName.c_str());
}
Function *getFunction(std::string name){
    if(auto *f = module->getFunction(name))
        return f;
    auto fi = functionProtos.find(name);
    if(fi!=functionProtos.end())
        return fi->second->codeGen();
    return nullptr;
}

static void initializeModuleAndpassManager(void) {
    module = llvm::make_unique<Module>("llvmlan",theLLVMContext);
    module->setDataLayout(jit->getTargetMachine().createDataLayout());

    fpm = llvm::make_unique<legacy::FunctionPassManager>(module.get());
    fpm->add(createDemoteRegisterToMemoryPass());
    fpm->add(createInstructionCombiningPass());
    fpm->add(createReassociatePass());
    fpm->add(createGVNPass());
    fpm->add(createCFGSimplificationPass());
    fpm->doInitialization();
}

class TreeShapeListener : public WenyanBaseListener {
public:
    void enterProgram(WenyanParser::ProgramContext *context) override {
        WenyanBaseListener::enterProgram(context);
        std::cout<<"enterProgram"<<std::endl;
        InitializeNativeTarget();
        InitializeNativeTargetAsmPrinter();
        InitializeNativeTargetAsmParser();
        jit = llvm::make_unique<KaleidoscopeJIT>();
        initializeModuleAndpassManager();
    }

    void exitProgram(WenyanParser::ProgramContext *context) override {
        WenyanBaseListener::exitProgram(context);
        globalVarModule->print(errs(), nullptr);
        module->print(errs(), nullptr);
        std::cout<<"exitProgram"<<std::endl;
    }

    void exitBlock(WenyanParser::BlockContext *context) override {
        WenyanBaseListener::exitBlock(context);
        context->value = context->statement().back()->value;
        std::cout<<"exitBlock"<<std::endl;
    }

    void exitStatement(WenyanParser::StatementContext *context) override {
        WenyanBaseListener::enterStatement(context);
        if(context->declareNumber()){
            context->value = context->declareNumber()->value;
        }else if(context->applyStatement()){
            context->value = context->applyStatement()->value;
        } else if(context->assignStatement()){
            context->value = context->assignStatement()->value;
        } else if(context->expression()){
            context->value = context->expression()->value;
        }
        std::cout<<"exitStatement"<<std::endl;
    }

    void exitExpression(WenyanParser::ExpressionContext *context) override {
        WenyanBaseListener::enterExpression(context);
        if(context->YI3()){
            if(context->OP()[0]->getText() == "加"){
                Value *lv = context->fn?context->fn->value:context->fv->value;
                Value *rv = context->sn?context->sn->value:context->sv->value;
                context->value = builder.CreateFAdd(lv,rv,"addtmp");
            } else if(context->OP()[0]->getText() == "减"){
                Value *lv = context->fn?context->fn->value:context->fv->value;
                Value *rv = context->sn?context->sn->value:context->sv->value;
                context->value = builder.CreateFSub(lv,rv,"subtmp");
            } else if(context->OP()[0]->getText() == "乘"){
                Value *lv = context->fn?context->fn->value:context->fv->value;
                Value *rv = context->sn?context->sn->value:context->sv->value;
                context->value = builder.CreateFMul(lv,rv,"multmp");
            }
        }
        std::cout<<"exitExpr"<<std::endl;
    }

    void enterIfStatement(WenyanParser::IfStatementContext *context) override {
        WenyanBaseListener::enterIfStatement(context);
        std::cout<<"enterIf"<<std::endl;
    }

    void enterForStatement(WenyanParser::ForStatementContext *context) override {
        WenyanBaseListener::enterForStatement(context);
        std::cout<<"enterFor"<<std::endl;
    }

    void enterVariable(WenyanParser::VariableContext *context) override {
        WenyanBaseListener::enterVariable(context);
        std::cout<<"enterVariable"<<std::endl;
        std::string name;
        chineseConvertPy(context->getText(), name);
        Value *v = namedValues[name];
        if(!v){
            return;
        }
        context->value = builder.CreateLoad(v,name.c_str());

    }


    void enterApplyFunction(WenyanParser::ApplyFunctionContext *context) override {
        WenyanBaseListener::enterApplyFunction(context);
        std::cout<<"enterApplyFun"<<std::endl;
    }

    void enterDeclarefunction(WenyanParser::DeclarefunctionContext *context) override {
        WenyanBaseListener::enterDeclarefunction(context);
        std::cout<<"enterDecfun"<<std::endl;
        // gen Proto
        std::vector<std::string> argNames;
        std::vector<WenyanParser::VariableContext *> vars=context->variables()->variable();
        for(int i=0;i<vars.size();++i){
            std::string argName;
            chineseConvertPy(vars[i]->getText(), argName);
            argNames.push_back(argName);
        }
        std::string fnName;
        chineseConvertPy(context->variable()->getText(), fnName);
        std::unique_ptr<PrototypeAST> proto = llvm::make_unique<PrototypeAST>(fnName,std::move(argNames));
        functionProtos[fnName] = std::move(proto);
        Function *theFunction = getFunction(fnName);
        if(!theFunction)
            return;
        BasicBlock *bb = BasicBlock::Create(theLLVMContext,"entry",theFunction);
        builder.SetInsertPoint(bb);
        namedValues.clear();
        for(auto &arg:theFunction->args()){
            AllocaInst *alloca = CreateEntryBlockAlloca(theFunction,arg.getName());
            builder.CreateStore(&arg,alloca);
            namedValues[arg.getName()] = alloca;
        }
        context->theFunction = theFunction;
    }

    void exitDeclarefunction(WenyanParser::DeclarefunctionContext *context) override {
        WenyanBaseListener::exitDeclarefunction(context);
        if(Value *retVal = context->block()->value){
            builder.CreateRet(retVal);
            verifyFunction(*context->theFunction);
            fpm->run(*context->theFunction);
            return;
        }
        context->theFunction->eraseFromParent();
    }


    void enterVariables(WenyanParser::VariablesContext *context) override {
        WenyanBaseListener::enterVariables(context);
        std::cout<<"enterFuncVariables"<<std::endl;
    }

    void enterDeclareNumber(WenyanParser::DeclareNumberContext *context) override {
        WenyanBaseListener::enterDeclareNumber(context);
        std::cout<<"enterDecNum"<<std::endl;
    }

    void enterNumber(WenyanParser::NumberContext *context) override {
        WenyanBaseListener::enterNumber(context);
        std::cout<<"enterNumber"<<std::endl;
        context->value = ConstantFP::get(Type::getDoubleTy(theLLVMContext),chineseNum2num(context->getText()));
    }

    void enterNumberInteger(WenyanParser::NumberIntegerContext *context) override {
        WenyanBaseListener::enterNumberInteger(context);
        std::cout<<"enterNumberInteger"<<std::endl;
    }

    void enterAssignStatement(WenyanParser::AssignStatementContext *context) override {
        WenyanBaseListener::enterAssignStatement(context);
        std::cout<<"enterAssign"<<std::endl;
    }
};

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("/Users/popo/CLionProjects/LLVMLan/example/example.wy",std::ios::binary);
    if(!stream.is_open()){
        std::cout<<"open"<<std::endl;
    }
    // stackoverflow magic ,i dont know how it work!
//skip BOM
    stream.seekg(2);

//read as raw bytes
    std::stringstream ss;
    ss << stream.rdbuf();
    std::string bytes = ss.str();

//make sure len is divisible by 2
    int len = bytes.size();
    if(len % 2) len--;

    std::wstring sw;
    for(size_t i = 0; i < len;)
    {
        //little-endian
        int lo = bytes[i++] & 0xFF;
        int hi = bytes[i++] & 0xFF;
        sw.push_back(hi << 8 | lo);
    }

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    std::string utf8 = convert.to_bytes(sw);
    stream.close();
    std::cout<<utf8<<std::endl;
    ANTLRInputStream input(utf8);
    WenyanLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    WenyanParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return 0;
}
