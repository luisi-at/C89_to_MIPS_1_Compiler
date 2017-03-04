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

%type <expr> primary_expression postfix_expression unary_expression
%type <expr> multiplicative_expression additive_expression shift_expression
%type <expr> relational_expression equality_expression
%type <expr> and_expression eor_expression or_expression
%type <expr> logical_and_expression logical_or_expression
%type <string_value> IDENTIFIER CONSTANT STRING_LITERAL INC_OP DEC_OP
%type <string_value> LEFT_OP RIGHT_OP

%start ROOT

%%

ROOT : logical_or_expression { prog_root = $1; }

primary_expression
  : IDENTIFIER            { $$ = new Identifier( *$1 ); }
  | CONSTANT              { $$ = new Constant( *$1 ); }
  | STRING_LITERAL        { $$ = new StringLiteral( *$1 ); }
  ;

postfix_expression
  : primary_expression                    { $$ = new PostfixEmpty( $1, "" ); }
  | postfix_expression '(' ')'            { $$ = new PostfixEmpty( $1, "" ); }
  | postfix_expression '.' IDENTIFIER     { $$ = new PostfixPeriod( $1, *$3 ); }
  | postfix_expression PTR_OP IDENTIFIER  { $$ = new PostfixPtrOp( $1, *$3 ); }
  | postfix_expression INC_OP             { $$ = new PostfixIncOp( $1, "" ); }
  | postfix_expression DEC_OP             { $$ = new PostfixDecOp( $1, ""); }
  ;

unary_expression
  : postfix_expression          { $$ = new UnaryPostfixExpression( $1 ); }
  | INC_OP unary_expression     { $$ = new UnaryIncExpression( $2 ); }
  | DEC_OP unary_expression     { $$ = new UnaryDecExpression( $2 ); }
  ;

unary_operator
  : '&'
  | '*'
  | '+'
  | '-'
  | '~'
  | '!'
  ;

multiplicative_expression
  : unary_expression
  | multiplicative_expression '*' unary_expression    { $$ = new MultiplyMultiplicative( $1, $3); }
  | multiplicative_expression '/' unary_expression    { $$ = new DivideMultiplicative( $1, $3); }
  | multiplicative_expression '%' unary_expression    { $$ = new ModMultiplicative( $1, $3); }
  ;

additive_expression
  : multiplicative_expression
  | additive_expression '+' multiplicative_expression   { $$ = new AddAdditive( $1, $3 ); }
  | additive_expression '-' multiplicative_expression   { $$ = new SubAdditive( $1, $3 ); }
  ;

shift_expression
  : additive_expression
  | shift_expression LEFT_OP additive_expression        { $$ = new LeftOpExpression ( $1, $3 ); }
  | shift_expression RIGHT_OP additive_expression       { $$ = new RightOpExpression ( $1, $3 ); }
  ;

relational_expression
  : shift_expression
  | relational_expression '<' shift_expression          { $$ = new StrictLessThanExpression ( $1, $3 ); }
  | relational_expression '>' shift_expression          { $$ = new StrictGreaterThanExpression ( $1, $3 ); }
  | relational_expression LE_OP shift_expression        { $$ = new LessEqualExpression ( $1, $3 ); }
  | relational_expression GE_OP shift_expression        { $$ = new GreaterEqualExpression ( $1, $3 ); }
  ;

equality_expression
  : relational_expression
  | equality_expression EQ_OP relational_expression     { $$ = new EqualOpExpression ( $1, $3); }
  | equality_expression NE_OP relational_expression     { $$ = new NotEqualOpExpression ( $1, $3); }
  ;

and_expression
  : equality_expression
  | and_expression '&' equality_expression              { $$ = new AndExpression ( $1, $3 ); }
  ;

eor_expression
  : and_expression
  | eor_expression '^' and_expression                 { $$ = new XorExpression ( $1, $3 ); }
  ;

or_expression
  : eor_expression
  | or_expression '|' eor_expression                  { $$ = new OrExpression ( $1, $3 ); }
  ;

logical_and_expression
  : or_expression
  | logical_and_expression AND_OP or_expression           { $$ = new LogicalAndExpression ( $1, $3 ); }
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR_OP logical_and_expression    { $$ = new LogicalOrExpression ( $1, $3 ); }
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



%%

const Expression *prog_root; // match variable defined earlier

const Expression *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
