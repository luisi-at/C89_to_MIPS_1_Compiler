%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern const Unit *prog_root;

  int yylex(void);
  void yyerror(const char *);


}

%union{
  const Expression *expr;
  const Statement *stmt;
  const Declarator *dltr;
  const FunctionDefinition *fdfn;
  const ExternalDeclaration *edln;
  const Unit *unit;

  double number;
  std::string *string_value;
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF

%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN ASSIGN

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
%type <expr> type_specifier initializer
%type <expr> identifier_list

%type <stmt> expression_statement jump_statement selection_statement statement
%type <stmt> iteration_statement labeled_statement
%type <stmt> compound_statement
%type <stmt> statement_list

%type <dltr> declaration_specifiers declaration init_declarator
%type <dltr> direct_declarator declarator init_declarator_list
%type <dltr> declaration_list parameter_declaration parameter_list

%type <string_value> IDENTIFIER CONSTANT STRING_LITERAL INC_OP DEC_OP
%type <string_value> LEFT_OP RIGHT_OP
%type <string_value> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%type <string_value> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%type <string_value> OR_ASSIGN XOR_ASSIGN assignment_operator  ';'
%type <string_value> '{' '}' '+'
%type <string_value> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED

%type <fdfn> function_definition function_definition_list
%type <edln> external_declaration
%type <unit> this_unit


%start ROOT

%%

ROOT : this_unit { prog_root = $1; }

primary_expression
  : IDENTIFIER            { $$ = new Identifier( *$1 ); }
  | CONSTANT              { $$ = new Constant( *$1 ); }
  | STRING_LITERAL        { $$ = new StringLiteral( *$1 ); }
  | '(' expression ')'
  ;

postfix_expression
  : primary_expression
  | postfix_expression '(' ')'            { $$ = new PostfixEmpty( $1, NULL ); }
  | postfix_expression '.' IDENTIFIER     { $$ = new PostfixPeriod( $1, new Identifier(*$3) ); }
  | postfix_expression PTR_OP IDENTIFIER  { $$ = new PostfixPtrOp( $1, new Identifier(*$3 ) ); }
  | postfix_expression INC_OP             { $$ = new PostfixIncOp( $1, NULL ); }
  | postfix_expression DEC_OP             { $$ = new PostfixDecOp( $1, NULL); }
  ;

unary_expression
  : postfix_expression
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
  | relational_expression '<' shift_expression          { std::cout << "LE!" << std::endl; $$ = new StrictLessThanExpression ( $1, $3 ); }
  | relational_expression '>' shift_expression          { $$ = new StrictGreaterThanExpression ( $1, $3 ); }
  | relational_expression LE_OP shift_expression        { $$ = new LessEqualExpression ( $1, $3 ); }
  | relational_expression GE_OP shift_expression        { $$ = new GreaterEqualExpression ( $1, $3 ); }
  ;

equality_expression
  : relational_expression
  | equality_expression EQ_OP relational_expression     { $$ = new EqualOpExpression ( $1, $3 ); }
  | equality_expression NE_OP relational_expression     { $$ = new NotEqualOpExpression ( $1, $3 ); }
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
  : ASSIGN
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

declaration
  : declaration_specifiers ';'                      { $$ = new MainDeclaration( $1, NULL); }
  | declaration_specifiers init_declarator_list ';' { $$ = new MainDeclaration( $1, $2); }
  ;

declaration_specifiers
  : type_specifier                        { }
  | type_specifier declaration_specifiers { $$ = new DeclarationSpecifier( $1, $2 ); }
  ;

init_declarator_list
  : init_declarator                       { $$ = new InitDeclarationList(); $$->AddItem( $1 ); }
  | init_declarator ',' init_declarator   { $$->AddItem( $3 ); }
  ;

init_declarator
  : declarator                            { $$ = new InitDeclarator( $1, NULL ); }
  | declarator ASSIGN initializer         { $$ = new InitDeclarator( $1, $3 ); }
  ;

type_specifier
  : VOID                      { $$ = new TypeSpecifierExpression( *$1 ); }
  | CHAR                      { $$ = new TypeSpecifierExpression( *$1 ); }
  | SHORT                     { $$ = new TypeSpecifierExpression( *$1 ); }
  | INT                       { $$ = new TypeSpecifierExpression( *$1 ); }
  | LONG                      { $$ = new TypeSpecifierExpression( *$1 ); }
  | FLOAT                     { $$ = new TypeSpecifierExpression( *$1 ); }
  | DOUBLE                    { $$ = new TypeSpecifierExpression( *$1 ); }
  | SIGNED                    { $$ = new TypeSpecifierExpression( *$1 ); }
  | UNSIGNED                  { $$ = new TypeSpecifierExpression( *$1 ); }
  ;


declarator
  : direct_declarator
  ;

direct_declarator
  : IDENTIFIER                                    { $$ = new IdentifierDeclarator( new Identifier( *$1 ) ); }
  | '(' declarator ')'                            { $$ = new BracketedDeclarator( $2 ); }
  | direct_declarator '[' constant_expression ']' { $$ = new ExpressionDeclarator( $1, $3 ); }
  | direct_declarator '[' ']'                     { $$ = new ExpressionDeclarator( $1, NULL );}
  | direct_declarator '(' identifier_list ')'     { $$ = new ExpressionDeclarator( $1, $3 ); }
  | direct_declarator '(' parameter_list  ')'     { $$ = new ParameterTypeDeclarator( $1, $3 ); }
  | direct_declarator '(' ')'                     { $$ = new EmptyDeclarator( $1 );}
  ;

parameter_list
  : parameter_declaration                         { $$ = new ParamDeclarationList(); $$->AddItem( $1 ); }
  | parameter_list ',' parameter_declaration      { $$->AddItem( $3 ); }
  ;

parameter_declaration
  : declaration_specifiers declarator             { $$ = new ParameterDeclaration( $1, $2 ); }
  | declaration_specifiers                        { $$ = new ParameterDeclaration( $1, NULL ); }
  ;

identifier_list
  : IDENTIFIER                      { $$ = new ExpressionList(); $$->AddItem(new Identifier( *$1 ) ); }
  | identifier_list ',' IDENTIFIER  { $$->AddItem(new Identifier( *$3 ) ); }
  ;

initializer
  : assignment_expression                         { $$ = new Initializer( $1, NULL ); }
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
  : IDENTIFIER ':' statement                { $$ = new IdentifierStatement( new Identifier( *$1 ), $3 ); }
  | CASE constant_expression ':' statement  { $$ = new CaseStatement( $2, $4 ); }
  | DEFAULT ':' statement                   { $$ = new DefaultStatement( $3 ); }
  ;

compound_statement
  : '{' '}'                                   { $$ = new CompoundStatement( NULL, NULL ); }
  | '{' statement_list '}'                    { $$ = new CompoundStatement( $2, NULL ); }
  | '{' declaration_list '}'                  { $$ = new CompoundStatement( NULL, $2 ); }
  | '{' declaration_list statement_list '}'   { $$ = new CompoundStatement( $3, $2 ); }
  ;

declaration_list
  : declaration                   { $$ = new DeclarationList(); $$->AddItem( $1 ); }
  | declaration_list declaration  { $$->AddItem( $2 ); }
  ;

statement_list
  : statement                   { $$ = new StatementList(); $$->AddItem( $1 ); }
  | statement_list statement    { $$->AddItem( $2 ); }
  ;

expression_statement
  : ';'                 { $$ = new ExpressionStatement( NULL ); }
  | expression ';'      { $$ = new ExpressionStatement( $1 ); }
  ;


selection_statement
  : IF '(' expression ')' statement                 { $$ = new IfSelection( $3, $5 ); }
  | IF '(' expression ')' statement ELSE statement  { $$ = new IfElseSelection( $3, $5, $7 ); }
  | SWITCH '(' expression ')' statement             { $$ = new SwitchSelection( $3, $5 ); }
  ;

iteration_statement
  : WHILE '(' expression ')' statement                                          { $$ = new WhileIteration( $3, $5 ); }
  | DO statement WHILE '(' expression ')' ';'                                   { $$ = new DoWhileIteration( $2, $5 ); }
  | FOR '(' expression_statement expression_statement ')' statement             { $$ = new ForNoExprIteration( $3, $4, $6 ); }
  | FOR '(' expression_statement expression_statement expression ')' statement  { $$ = new ForExprIteration( $3, $4, $7, $5); }
  ;

jump_statement
  : GOTO IDENTIFIER ';'     { $$ = new GotoStatement( new Identifier( *$2 ) ); }
  | CONTINUE ';'            { $$ = new ContinueStatement( NULL ); }
  | BREAK ';'               { $$ = new BreakStatement( NULL ); }
  | RETURN ';'              { $$ = new ReturnStatement( NULL ); }
  | RETURN expression ';'   { $$ = new ReturnExprStatement( $2 ); }


this_unit
  : external_declaration            { }
  | this_unit external_declaration  { }
  ;

external_declaration
  : function_definition_list        { $$ = new ExternalDeclaration( $1, NULL ); }
  | declaration                     { $$ = new ExternalDeclaration( NULL, $1 ); }
  | declaration function_definition { $$ = new ExternalDeclaration( $2, $1 ); }
  ;

function_definition_list
  : function_definition                             { $$ = new FunctionDefinitionList(); $$->AddItem( $1 ); }
  | function_definition_list function_definition    { $$->AddItem( $2 ); }

function_definition
  : declaration_specifiers declarator declaration_list compound_statement { $$ = new FunctionDefinitionActual( $1, $2, $3, $4 ); }
  | declaration_specifiers declarator compound_statement                  { $$ = new FunctionDefinitionActual( $1, $2, NULL, $3 ); }
  | declarator declaration_list compound_statement                        { $$ = new FunctionDefinitionActual( NULL, $1, $2, $3 ); }
  | declarator compound_statement                                         { $$ = new FunctionDefinitionActual( NULL, $1, NULL, $2 ); }
  ;



%%

const Unit *prog_root; // match variable defined earlier

const Unit *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
