#ifndef lexer_h
#define lexer_h

#include <string>

enum TokenType{
    None = 0,
    Keyword = 1,
    Identifier,
    Operator,
    Constant,
    StringLiteral,
    Invalid,
    PreProcessor,
    AddCol,
    ResetCol
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
