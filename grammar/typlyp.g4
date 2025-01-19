grammar typlyp;

// TODO
// 1. Убрать в statement ; в конце (чтобы фор нормально выглядел) // DONE
// 2. Поменять присваивания на стрелочки // DONE
// 3. vernut на otdau // DONE
// 4. В форе поменять ; на | // DONE
// 5. фор  и другие двусторонние (со стрелками) // DONE
// 6. замена net и da // DONE
// 7. стрелка в функциях // DONE

// Основное правило программы
program : (functionDecl | statement)* EOF;

// Объявление функции
functionDecl : 'delo' ID '(' paramList? ')' RASSIGN type block;

// Список параметров
paramList : param (',' param)*;
param : ID 'kak' type;

// Блок кода
block : '{' statement* '}';

// Операторы
statement
    : (varDecl SEMICOLON)
    | (printStatement SEMICOLON)
    | (assignment SEMICOLON)
    | (arrayAssignment SEMICOLON)
    | (returnStatement SEMICOLON)
    | ifStatement
    | whileStatement
    | forStatement
    | expr ';'
    ;

// Объявление переменной
varDecl : (ID 'kak' type (LASSIGN expr)?)
        | ((expr RASSIGN)? ID 'kak' type);

// Присваивание значения переменной
assignment  : (ID LASSIGN expr)
            | (expr RASSIGN ID);

// Присваивание значения элементу массива
arrayAssignment : (ID LBRACKET expr RBRACKET LASSIGN expr)
                | (expr RASSIGN ID LBRACKET expr RBRACKET);

// Оператор возврата
returnStatement : 'otdau' expr;

// Условный оператор
ifStatement : ('esli' LASSIGN LPAREN expr RPAREN block ('inache' block)?)
            | (LPAREN expr RPAREN RASSIGN 'esli' block ('inache' block)?);

// Цикл
whileStatement : ('poka' LASSIGN LPAREN expr RPAREN block)
               | (LPAREN expr RPAREN RASSIGN 'poka' block);

// Новый цикл for
forStatement : (('perebor' LASSIGN LPAREN varDecl? expr? SEMICOLON assignment? RPAREN)
             | (LPAREN varDecl? DIVIDER expr? DIVIDER assignment? RPAREN RASSIGN 'perebor')) block;

// Вывод на экран
printStatement  : (expr RASSIGN 'glaza')
                | ('glaza' LASSIGN expr);

// Выражения
expr
    : expr (MULT | DIV | MOD) expr // done
    | expr (PLUS | MINUS) expr // done
    | expr (LT | LE | GT | GE) expr // done
    | expr (EQ | NEQ) expr // done
    | NOT expr // done
    | ID // done
    | ID LBRACKET expr RBRACKET // done
    | INT // done
    | BOOL // done
    | '(' expr ')' // done
    | ID '(' argList? ')' // done
    | 'new' scalarType '<' expr '>' // Создание массива done
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
BOOL : 'da' | 'net';               // Логические значения
INT : [0-9]+;                          // Целые числа
ID : [a-zA-Z_][a-zA-Z0-9_]*;           // Идентификаторы
WS : [ \t\r\n]+ -> skip;               // Пропуск пробелов и новых строк
COMMENT : '//' ~[\r\n]* -> skip;       // Однострочные комментарии
LINE_COMMENT : '/*' .*? '*/' -> skip;  // Многострочные комментарии

// Операторы
PLUS : '+'; MINUS : '-'; MULT : '*'; DIV : '/'; MOD : '%';
LT : '<'; LE : '<='; GT : '>'; GE : '>=';
EQ : '='; NEQ : '!=';
AND : '&&'; OR : '||'; NOT : '!';
LASSIGN : '<-'; RASSIGN : '->';
LBRACKET : '['; RBRACKET : ']';
LPAREN : '('; RPAREN : ')';
LBRACE : '{'; RBRACE : '}';
SEMICOLON : ';'; COMMA : ',';
DIVIDER : '|';
