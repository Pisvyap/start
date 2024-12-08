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
    : varDecl // done
    | assignment
    | arrayAssignment
    | returnStatement // done
    | ifStatement // done
    | whileStatement // done
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
forStatement : 'schitaem' '(' forInit? expr? ';' forUpdate? ')' block;

// Инициализация цикла for
forInit : varDecl | assignment;

// Обновление переменной в цикле for
forUpdate : assignment;

// Выражения
expr
    : expr ('*' | '/' | '%') expr // done
    | expr ('+' | '-') expr // done
    | expr ('<' | '<=' | '>' | '>=') expr // done
    | expr ('==' | '!=') expr // done
    | '!' expr // done
    | ID
    | ID '[' expr ']'
    | INT
    | BOOL
    | '(' expr ')'
    | ID '(' argList? ')' // done
    | 'new' type '[' expr ']' // Создание массива
    | 'extern' ID '(' argList? ')' // done?
    ;

// Список аргументов
argList : expr (',' expr)*;

// Список выражений (для массивов)
exprList : expr (',' expr)*;

// Типы данных
type
    : 'chislo'
    | 'logika'
    | 'chislo' '[' ']'
    | 'logika' '[' ']'
    ;

// Лексические правила
ID : [a-zA-Z_][a-zA-Z0-9_]*;           // Идентификаторы
INT : [0-9]+;                          // Целые числа
BOOL : 'pravda' | 'lozh';               // Логические значения
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
