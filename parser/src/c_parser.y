%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern const Expression *prog_root;

  int yylex(void);
  void yyerror(const char *);
}

%union{
  const Expression *expr;
  double number;
  std::string *string_value;
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <expr> primary_expression postfix_expression
%type <string_value> IDENTIFIER CONSTANT STRING_LITERAL INC_OP

%start ROOT

%%

ROOT : postfix_expression { prog_root = $1; }

primary_expression
  : IDENTIFIER            { $$ = new Identifier( *$1 ); }
  | CONSTANT              { $$ = new Constant( *$1 ); }
  | STRING_LITERAL        { $$ = new StringLiteral( *$1 ); }
  ;

  postfix_expression
    : primary_expression          { $$ = new PostfixEmpty( $1, "" ); }
    | postfix_expression '(' ')'  { $$ = new PostfixEmpty( $1, "" ); }
    | postfix_expression          { $$ = new PostfixEmpty( $1, "" ); }
    | postfix_expression '.' IDENTIFIER     { $$ = new PostfixPeriod( $1, *$3 ); }
    | postfix_expression PTR_OP IDENTIFIER  { $$ = new PostfixPtrOp( $1, *$3 ); }
    | postfix_expression INC_OP   { $$ = new PostfixIncOp( $1, "" ); }
    | postfix_expression DEC_OP   { $$ = new PostfixDecOp( $1, ""); }
    ;

%%

const Expression *prog_root; // match variable defined earlier

const Expression *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
