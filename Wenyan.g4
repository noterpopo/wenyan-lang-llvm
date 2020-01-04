grammar Wenyan;
// $antlr-format useTab false;
// $antlr-format columnLimit 160;
// $antlr-format alignColons hanging;
program: block* EOF;
block:statement+;
statement
    : declareNumber
    | declarefunction
    | ifStatement
    | forStatement
    | applyStatement
    | assignStatement
    | returnStatement
    | expression;
expression
    :OP (fn = number | fv = variable) YI3 (sn = number | sv = variable)
    | (fn = number | fv = variable) (OP (sn =number | sv = variable))*;
OP : Jia | Jian | Cheng | XiaoYu | Dengyu | Dayu;
YI3: Yi3;
fragment Jia : '加';
fragment Jian : '减';
fragment Cheng : '乘';
fragment XiaoYu : '小'Yu;
fragment Dengyu : '等'Yu;
fragment Dayu : '大'Yu;
fragment Yi3   : '以';

returnStatement: Return expression;
Return      : Nai De; // 乃得

assignStatement: XiZhi variable EndDeclare '今' expression ShiYi;
XiZhi : '昔之';
ShiYi : '是矣';
/*====================================================================================================================*/
// $antlr-format alignColons trailing;
ifStatement : ifStartState EndDeclare ifThenState ifElseState EndStatment?;
ifStartState : If expression;
ifThenState : block;
ifElseState : Else block;
If          : Ruo; // 若
EndDeclare  : Zhe; // 者
Else        : Ruo Fei; // 若非

fragment Ruo : '若';
fragment Fei : '非';
fragment Nai : '乃';
fragment De  : '得';
fragment Zhe : '者';

forStatement: ForStart number ForStart2 block ForEnd;
ForStart : Weishi;
ForStart2:Bian;
ForEnd : YunYum;
fragment Weishi : '為是';
fragment Bian : '遍';
fragment YunYum : '云云';

variable : Variable;
Variable : Left4 Character+ Right4 | Left Character+ Right;
Left     : '[';
Right    : ']';
Left4    : '「';
Right4   : '」';
/*====================================================================================================================*/
applyStatement : applyFunction;
//施「翻倍」於「大衍」
applyFunction : Apply fv = variable At? funcVars*;
funcVars: sn = number|sv =variable;
Apply         : Shi2; //施
At            : Yu; // 于

fragment Shi2 : '施';
fragment Ru   : '入';
fragment Qiu  : '求';
fragment Qu   : '取';
fragment De2  : '得';

The          : Zhi;
End          : Yun Yun; //云云
fragment Yun : '云' | '雲';
/*====================================================================================================================*/
//吾有一術。名之曰「六脈神劍」。欲行是術。必先得六數。曰「甲」。曰「乙」。曰「丙」。曰「丁」。曰「戊」。曰「己」乃行
// 是術曰。⋯⋯是謂「六脈神劍」之術也。
// $antlr-format alignColons hanging;
declarefunction
    : DeclareMethod NameAs variable variables? FunctionStart block FunctionEnd EndStatment?;
// $antlr-format alignColons trailing;
FunctionStart : Nai Xing Is Shu2 ValueIs; //是术曰
FunctionEnd   : ThisIs Variable MethodOf; //是谓「XX」之术也

//欲行是術必先得六數
variables :VarPref VariableStart (NameAs variable)+;
VarPref: Yu2 Xing Is Shu2;
VariableStart :  '必先得' IntegerDigitCN Shu;
fragment Yu2  : '欲';
fragment Xing : '行';

DeclareMethod : IHave Shu2; //吾有一术
fragment Shu2 : '術' | '术';

ThisIs       : Shi Wei; // 是谓
Is           : Shi;
Said         : Wei;
MethodOf     : Of Shu2 Ye; // 之术也
fragment Shi : '是';
fragment Of  : '之';
fragment Ye  : '也';
/*====================================================================================================================*/

EndStatment : Zhe? Ye;

IHave : (Jin | Wu | Zi | You | You2)? You Yi?; //吾有一

fragment Jin  : '今';
fragment Wu   : '吾';
fragment Zi   : '兹';
fragment You  : '有';
fragment You2 : '又';
fragment Yi   : '一';

NameAs  : Ming Zhi? Yue | Ming Zhi Yue? | Ci? Suo Wei | Wei Zhi Yue?; //名之曰
ValueIs : Yue; //曰

fragment Ming : '名';
fragment Zhi  : '之';
fragment Yue  : '曰';
fragment Ci   : '此';
fragment Suo  : '所';
fragment Wei  : '謂' | '谓';
/*====================================================================================================================*/
declareNumber
    : DeclareDigit (ValueIs expression)* (NameAs variable)+;
// $antlr-format alignColons trailing;
DeclareDigit   : IHave IntegerDigitCN* Shu;// 吾有一数
fragment Shu   : '數' | '数';
/*====================================================================================================================*/
// $antlr-format alignColons hanging;
number: Left n = digits Right | n = digits;
digits
    : IntegerDigit+   # NumberInteger
    | IntegerDigitCN+ # NumberIntegerCN
    | FloatDigit+     # NumberFloat
    | FloatDigitCN+   # NumberFloatCN;
// $antlr-format alignColons trailing;
IntegerDigit   : [0-9];
FloatDigit     : [.]| IntegerDigit;
IntegerDigitCN : [零一二三四五六七八九十百千万亿兆];
FloatDigitCN   : [点又有] | IntegerDigitCN;
/*====================================================================================================================*/
// $antlr-format alignColons hanging;
Equal   : '=' | Den Yu;
Unequal : '≠' | '!=' | Bu Den Yu;
fragment Bu  : '不';
fragment Den : '等';
fragment Yu  : '於' | '于';
/*====================================================================================================================*/
Character     : [\p{Latin}]| [\p{Han}] | [\p{Hiragana}] | [\p{Katakana}];
LineComment                : CommentStart ~[\r\n]* -> channel(HIDDEN);
PartComment                : Comment .*? Comment -> channel(HIDDEN);
WhiteSpace                 : UnicodeWhiteSpace+ -> skip;
fragment CommentStart      : ('注' | '疏' | '批') Yue;
fragment Comment           : ('注' | '疏' | '批') '毕';
fragment UnicodeWhiteSpace : [\p{White_Space}]| Delimiter;
fragment Delimiter         : [。，！]| [.,!;?];