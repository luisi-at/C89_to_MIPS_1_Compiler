%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern const Expression *prog_root;

  int yylex(void);
  void yyerror(const char *);
}

%union{
  const Expression *expr;
  const Statement *stmt;
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
%type <expr> conditional_expression assignment_expression
%type <expr> constant_expression
%type <expr> expression
%type <stmt> labeled_statement compound_statement expression_statement
%type <stmt> selection_statement iteration_statement jump_statement
%type <stmt> statement
%type <string_value> IDENTIFIER CONSTANT STRING_LITERAL INC_OP DEC_OP
%type <string_value> LEFT_OP RIGHT_OP
%type <string_value> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%type <string_value> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%type <string_value> OR_ASSIGN XOR_ASSIGN assignment_operator '='

%start ROOT

%%

ROOT : expression { prog_root = $1; }

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
    { $$ = new ConditionalExpression ( $1, $3, $5 ); }
  ;

assignment_expression
  : conditional_expression
  | unary_expression assignment_operator assignment_expression     { $$ = new AssignmentExpression ( $1, *$2, $3 ); }
  ;

assignment_operator
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
  : assignment_expression
  | expression ',' assignment_expression   { $$ = new MainExpression( $1, $3 ); }
  ;

constant_expression
  : conditional_expression
  ;






statement
  : labeled_statement
  | compound_statement
  | expression_statement
  | selection_statement
  | iteration_statement
  | jump_statement
  ;

labeled_statement
  : IDENTIFIER ':' statement                { $$ = new IdentifierStatement( $1, $3 ); }
  | CASE constant_expression ':' statement  { $$ = new CaseStatement( $2, $4 ); }
  | DEFAULT ':' statement                   { $$ = new DefaultStatement( $3 ); }
  ;

compound_statement
  : '{' '}'
  | '{' statement_list '}'
  | '{' declaration_list '}'
  | '{' declaration_list statement_list '}'
  ;

declaration_list
  : declaration
  | declaration_list declaration
  ;

statement_list
  : statement
  | statement_list statement
  ;

expression_statement
  : ';'
  | expression ';'      { $$ = new ExpressionStatement( $1 ); }
  ;

selection_statement
  : IF '(' expression ')' statement                 { $$ = new IfSelection( $3, $5 ); }
  | IF '(' expression ')' statement ELSE statement  { $$ = new IfElseSelection( $3, $5, $7 ); }
  | SWITCH '(' expression ')' statement             { $$ = new SwitchSelection( $3, $5 ); }
  ;

iteration_statement
  : WHILE '(' expression ')' statement
  | DO statement WHILE '(' expression ')' ';'
  | FOR '(' expression_statement expression_statement ')' statement
  | FOR '(' expression_statement expression_statement expression ')' statement
  ;

jump_statement
  : GOTO IDENTIFIER
  | CONTINUE ';'
  | BREAK ';'
  | RETURN ';'
  | RETURN expression ';'
    ;


%%

const Expression *prog_root; // match variable defined earlier

const Expression *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
