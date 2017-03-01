#ifndef lexer_h
#define lexer_h

#include <string>

// to get the value, line number and column (eventually)
extern TokenContainer yylval;

extern int yylex();

extern int yylineno;

extern unsigned long yyleng;

#endif
