%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern const Program *prog_root;

  int yylex(void);
  void yyerror(const char *);
}

%token IDENTIFIER HEX_CONSTANT INT_CONSTANT FLT_CONSTANT CHAR_CONSTANT STRING_LITERAL SIZEOF

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit

%%

primary_expression
  : IDENTIFIER
  | HEX_CONSTANT
  | INT_CONSTANT
  | FLT_CONSTANT
  | CHAR_CONSTANT
  | STRING_LITERAL
  ;



const Program *prog_root; // match variable defined earlier

const Program *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
