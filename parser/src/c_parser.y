%code requires{
  #include "ast.hpp"
  #include <cassert>

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
  | '(' expression ')'
  ;

postfix_expression
  : primary_expression
  | postfix_expression '[' expression ']'
  | postfix_expression '(' ')'
  | postfix_expression
  | postfix_expression '.' IDENTIFIER
  | postfix_expression PTR_OP IDENTIFIER
  | postfix_expression INC_OP IDENTIFIER
  | postfix_expression DEC_OP IDENTFIER
  ;

argument_expression_list
  : assignement_expression
  | argument_expression_list ',' assignement_expression
  ;

unary_expression
  : postfix_expression
  | INC_OP unary_expression
  | DEC_OP unary_expression
  |
  ;

unary_operator
    : '&'
    | '*'
    | '+'
    | '-'
    | '~'
    | '!'
    ;

cast_expression
  : unary_expression
  |
  ;

multiplicative_expression
  : cast_expression
  | multiplicative_expression '*' cast_expression
  | multiplicative_expression '/' cast_expression
  | multiplicative_expression '%' cast_expression
  ;

additive_expression
  : multiplicative_expression
  | additive_expression '+' multiplicative_expression
  | additive_expression '-' multiplicative_expression
  ;

shift_expression
  : additive_expression
  | shift_expression LEFT_OP additive_expression
  | shift_expression RIGHT_OP additive_expression
  ;

relational_expression
  : shift_expression
  | relational_expression '<' shift_expression
  | relational_expression '>' shift_expression
  | relational_expression LE_OP shift_expression
  | relational_expression GE_OP shift_expression
  ;

equality_expression
  : relational_expression
  | equality_expression EQ_OP relational_expression
  | equality_expression NE_OP relational_expression
  ;

and_expression
  : equality_expression
  | and_expression '&' equality_expression
  ;

eor_expression
  : and_expression
  | eor_expression '^' and_expression
  ;

or_expression
  : eor_expression
  | or_expression '|' eor_expression
  ;

logical_and_expression
  : or_expression
  | logical_and_expression AND_OP or_expression
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR_OP logical_and_expression
  ;

conditional_expression
  : logical_or_expression
  | logical_or_expression '?' expression ':' conditional_expression
  ;

assignement_expression
  : conditional_expression
  | unary_expression assignement_operator assignement_expression
  ;

assignement_operator
  : '='
  | MUL_ASSIGN
  | DIV_ASSIGN
  | MOD_ASSIGN
  | ADD_ASSIGN
  | SUB_ASSIGN
  | LEFT_ASSIGN
  | RIGHT_ASSIGN
  | AND_ASSIGN
  | OR_ASSIGN
  | XOR_ASSIGN
  ;

expression
  : assignement_expression
  | expression ',' assignement_expression
  ;

constant_expression
  : conditional_expression
  ;

declaration

storage_class
  : TYPEDEF
  | EXTERN
  | STATIC
  | AUTO
  | REGISTER
  ;

type_specifier
  : VOID
  | CHAR
  | SHORT
  | INT
  | LONG
  | FLOAT
  | DOUBLE
  | SIGNED
  | UNSIGNED
  ;

struct_union
    : STRUCT
    | UNION
    ;

jump_statement
    : GOTO IDENTIFIER
    | CONTINUE ';'
    | BREAK ';'
    | RETURN ';'
