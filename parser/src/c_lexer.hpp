#ifndef lexer_h
#define lexer_h

#include <string>

enum TokenType{
    AUTO = 0,
    DOUBLE = 1,
    INT,
    STRUCT,
    BREAK,
    ELSE,
    LONG,
    SWITCH,
    CASE,
    ENUM,
    REGISTER,
    TYPEDEF,
    CHAR,
    EXTERN,
    RETURN,
    UNION,
    CONST,
    FLOAT,
    SHORT,
    UNSIGNED,
    CONTINUE,
    FOR,
    SIGNED,
    VOID,
    DEFAULT,
    GOTO,
    SIZEOF,
    VOLATILE,
    DO,
    IF,
    STATIC,
    WHILE,
    IDENTIFIER,
    INC_OP,
    DEC_OP,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MUL_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    AND_ASSIGN,
    OR_ASSIGN,
    XOR_ASSIGN,
    LEFT_ASSIGN,
    RIGHT_ASSIGN,
    LE_OP,
    GE_OP,
    EQ_OP,
    NE_OP,
    AND_OP,
    OR_OP,
    LEFT_OP,
    RIGHT_OP,
    PTR_OP,
    ELLIPSIS,
    CONSTANT,
    STRING_LITERAL
};






// to get the value, line number and column (eventually)
struct TokenContainer{
  std::string *value;
  int lineNumber;
  int columnNumber;
};

extern TokenContainer yylval;

extern int yylex();

extern int yylineno;

extern unsigned long yyleng;

#endif
