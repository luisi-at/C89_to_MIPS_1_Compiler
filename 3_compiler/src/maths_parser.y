%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_TIMES T_PLUS T_DIVIDE T_MINUS T_LBRACKET T_RBRACKET T_LOG T_EXP T_SQRT T_NUMBER T_VARIABLE

%left T_PLUS T_MINUS
%left T_TIMES T_DIVIDE
%left T_LOG T_EXP T_SQRT

%type <expr> EXPR TERM FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT : EXPR { g_root = $1; }

EXPR : T_LOG EXPR      { $$ = new LogFunction($2); }

EXPR : T_EXP EXPR      { $$ = new ExpFunction($2); }

EXPR : T_SQRT EXPR     { $$ = new SqrtFunction($2); }

EXPR : EXPR T_MINUS EXPR { $$ = new SubOperator($1, $3); }

EXPR:  EXPR T_PLUS  EXPR { $$ = new AddOperator($1, $3); }

EXPR : EXPR T_TIMES EXPR { $$ = new MulOperator($1, $3); }

EXPR : EXPR T_DIVIDE EXPR { $$ = new DivOperator($1, $3); }

EXPR : TERM                 { $$ = $1; }

TERM : FACTOR               { $$ = $1; }

FACTOR : T_NUMBER           { $$ = new Number( $1 ); }
       | T_VARIABLE         { $$ = new Variable( *$1 ); }
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }


FUNCTION_NAME : T_LOG { $$ = new std::string("log"); }
              | T_EXP { $$ = new std::string("exp"); }
              | T_SQRT { $$ = new std::string("sqrt") }

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
