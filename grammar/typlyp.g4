grammar typlyp;

// Основное правило программы
program : (functionDecl | externalDecl | statement)* EOF;

// Объявление функции
functionDecl : 'delo' ID '(' paramList? ')' ':' type block;

// Объявление внешней функции (например, из LLVM)
externalDecl : 'vneshnaya' ID '(' paramList? ')' ':' type ';';

// Список параметров
paramList : param (',' param)*;
param : ID ':' type;

// Блок кода
block : '{' statement* '}';

// Операторы
statement
    : varDecl
    | printStatement
    | assignment
    | arrayAssignment
    | returnStatement
    | ifStatement
    | whileStatement
    | forStatement
    | expr ';'
    ;

// Объявление переменной
varDecl : 'pust' ID ':' type ('=' expr)? ';';

// Присваивание значения переменной
assignment : ID '=' expr ';';

// Присваивание значения элементу массива
arrayAssignment : ID '[' expr ']' '=' expr ';';

// Оператор возврата
returnStatement : 'vernut' expr ';';

// Условный оператор
ifStatement : 'esli' '(' expr ')' block ('inache' block)?;

// Цикл
whileStatement : 'poka' '(' expr ')' block;

// Новый цикл for
forStatement : 'schitaem' '(' varDecl? expr? ';' assignment? ')' block;

// Вывод на экран
printStatement : expr '->' 'glaza' ';';

// Выражения
expr
    : expr ('*' | '/' | '%') expr // done
    | expr ('+' | '-') expr // done
    | expr ('<' | '<=' | '>' | '>=') expr // done
    | expr ('==' | '!=') expr // done
    | '!' expr // done
    | ID // done
    | ID '[' expr ']' // done
    | INT // done
    | BOOL // done
    | '(' expr ')' // done
    | ID '(' argList? ')' // done
    | 'new' scalarType '<' expr '>' // Создание массива done
    | 'extern' ID '(' argList? ')' // done?
    ;

// Список аргументов
argList : expr (',' expr)*;

// Список выражений (для массивов)
exprList : expr (',' expr)*;

// Правила для типов
type
    : scalarType              // ScalarType
    | arrayType               // ArrayType
    | voidType
    ;

voidType
    : 'nebytie'
    ;

scalarType
    : 'chislo'                // ChisloType
    | 'logika'                // LogikaType
    ;

arrayType
    :
    | scalarType '<' '>'      // UnknownSizeArray
    ;

// Лексические правила
BOOL : 'pravda' | 'lozh';               // Логические значения
INT : [0-9]+;                          // Целые числа
ID : [a-zA-Z_][a-zA-Z0-9_]*;           // Идентификаторы
WS : [ \t\r\n]+ -> skip;               // Пропуск пробелов и новых строк
COMMENT : '//' ~[\r\n]* -> skip;       // Однострочные комментарии
LINE_COMMENT : '/*' .*? '*/' -> skip;  // Многострочные комментарии

// Операторы
PLUS : '+'; MINUS : '-'; MULT : '*'; DIV : '/'; MOD : '%';
LT : '<'; LE : '<='; GT : '>'; GE : '>=';
EQ : '=='; NEQ : '!=';
AND : '&&'; OR : '||'; NOT : '!';
ASSIGN : '=';
LBRACKET : '['; RBRACKET : ']';
LPAREN : '('; RPAREN : ')';
LBRACE : '{'; RBRACE : '}';
SEMICOLON : ';'; COMMA : ',';
