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

%type <fdfn> function_definition
%type <edln> external_declaration
%type <unit> this_unit


%start ROOT

%%

ROOT : this_unit { prog_root = $1; }

primary_expression
  : IDENTIFIER            { std::cout << "78--> " << *$1 << std::endl; $$ = new Identifier( *$1 ); }
  | CONSTANT              { std::cout << "79--> " << *$1 << std::endl; $$ = new Constant( *$1 ); }
  | STRING_LITERAL        { std::cout << "80" << std::endl; $$ = new StringLiteral( *$1 ); }
  ;

postfix_expression
  : primary_expression                    { std::cout << "84" << std::endl; $$ = new PostfixEmpty( $1, "" ); }
  | postfix_expression '(' ')'            { std::cout << "85" << std::endl; $$ = new PostfixEmpty( $1, "" ); }
  | postfix_expression '.' IDENTIFIER     { std::cout << "86" << std::endl; $$ = new PostfixPeriod( $1, *$3 ); }
  | postfix_expression PTR_OP IDENTIFIER  { std::cout << "87" << std::endl; $$ = new PostfixPtrOp( $1, *$3 ); }
  | postfix_expression INC_OP             { std::cout << "88" << std::endl; $$ = new PostfixIncOp( $1, "" ); }
  | postfix_expression DEC_OP             { std::cout << "89" << std::endl; $$ = new PostfixDecOp( $1, ""); }
  ;

unary_expression
  : postfix_expression          { std::cout << "93" << std::endl; $$ = new UnaryPostfixExpression( $1 ); }
  | INC_OP unary_expression     { std::cout << "94" << std::endl; $$ = new UnaryIncExpression( $2 ); }
  | DEC_OP unary_expression     { std::cout << "95" << std::endl; $$ = new UnaryDecExpression( $2 ); }
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
  | multiplicative_expression '*' unary_expression    { std::cout << "109" << std::endl; $$ = new MultiplyMultiplicative( $1, $3); }
  | multiplicative_expression '/' unary_expression    { std::cout << "110" << std::endl; $$ = new DivideMultiplicative( $1, $3); }
  | multiplicative_expression '%' unary_expression    { std::cout << "111" << std::endl; $$ = new ModMultiplicative( $1, $3); }
  ;

additive_expression
  : multiplicative_expression
  | additive_expression '+' multiplicative_expression   { std::cout << "116" << std::endl; $$ = new AddAdditive( $1, $3 ); }
  | additive_expression '-' multiplicative_expression   { std::cout << "117" << std::endl; $$ = new SubAdditive( $1, $3 ); }
  ;

shift_expression
  : additive_expression
  | shift_expression LEFT_OP additive_expression        { std::cout << "122" << std::endl; $$ = new LeftOpExpression ( $1, $3 ); }
  | shift_expression RIGHT_OP additive_expression       { std::cout << "123" << std::endl; $$ = new RightOpExpression ( $1, $3 ); }
  ;

relational_expression
  : shift_expression
  | relational_expression '<' shift_expression          { std::cout << "128" << std::endl; $$ = new StrictLessThanExpression ( $1, $3 ); }
  | relational_expression '>' shift_expression          { std::cout << "129" << std::endl; $$ = new StrictGreaterThanExpression ( $1, $3 ); }
  | relational_expression LE_OP shift_expression        { std::cout << "130" << std::endl; $$ = new LessEqualExpression ( $1, $3 ); }
  | relational_expression GE_OP shift_expression        { std::cout << "131" << std::endl; $$ = new GreaterEqualExpression ( $1, $3 ); }
  ;

equality_expression
  : relational_expression
  | equality_expression EQ_OP relational_expression     { std::cout << "136" << std::endl; $$ = new EqualOpExpression ( $1, $3); }
  | equality_expression NE_OP relational_expression     { std::cout << "137" << std::endl; $$ = new NotEqualOpExpression ( $1, $3); }
  ;

and_expression
  : equality_expression
  | and_expression '&' equality_expression              { std::cout << "142" << std::endl; $$ = new AndExpression ( $1, $3 ); }
  ;

eor_expression
  : and_expression
  | eor_expression '^' and_expression                 { std::cout << "147" << std::endl; $$ = new XorExpression ( $1, $3 ); }
  ;

or_expression
  : eor_expression
  | or_expression '|' eor_expression                  { std::cout << "152" << std::endl; $$ = new OrExpression ( $1, $3 ); }
  ;

logical_and_expression
  : or_expression
  | logical_and_expression AND_OP or_expression           { std::cout << "157" << std::endl; $$ = new LogicalAndExpression ( $1, $3 ); }
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR_OP logical_and_expression    { std::cout << "162" << std::endl; $$ = new LogicalOrExpression ( $1, $3 ); }
  ;

conditional_expression
  : logical_or_expression
  | logical_or_expression '?' expression ':' conditional_expression
    { std::cout << "168" << std::endl; $$ = new ConditionalExpression ( $1, $3, $5 ); }
  ;

assignment_expression
  : conditional_expression
  | unary_expression assignment_operator assignment_expression     { std::cout << "173" << std::endl; $$ = new AssignmentExpression ( $1, *$2, $3 ); }
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
  | expression ',' assignment_expression   { std::cout << "191" << std::endl; $$ = new MainExpression( $1, $3 ); }
  ;

constant_expression
  : conditional_expression
  ;

declaration
  : declaration_specifiers ';'                      { std::cout << "199" << std::endl; $$ = new MainDeclaration( $1, NULL); }
  | declaration_specifiers init_declarator_list ';' { std::cout << "200" << std::endl; $$ = new MainDeclaration( $1, $2); }
  ;

declaration_specifiers
  : type_specifier                        { std::cout << "205" << std::endl; }
  | type_specifier declaration_specifiers { std::cout << "206" << std::endl; $$ = new DeclarationSpecifier( $1, $2 ); }
  ;

init_declarator_list
  : init_declarator                       { std::cout << "210" << std::endl; $$ = new InitDeclarationList(); $$->AddItem( $1 ); }
  | init_declarator ',' init_declarator   { std::cout << "211" << std::endl; $$->AddItem( $3 ); }
  ;

init_declarator
  : declarator                            { std::cout << "215" << std::endl; $$ = new InitDeclarator( $1, NULL ); }
  | declarator ASSIGN initializer         { std::cout << "216" << std::endl; $$ = new InitDeclarator( $1, $3 ); }
  ;

type_specifier
  : VOID                      { std::cout << "220" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | CHAR                      { std::cout << "221" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | SHORT                     { std::cout << "222" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | INT                       { std::cout << "223" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | LONG                      { std::cout << "224" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | FLOAT                     { std::cout << "225" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | DOUBLE                    { std::cout << "226" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | SIGNED                    { std::cout << "227" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  | UNSIGNED                  { std::cout << "228" << std::endl; $$ = new TypeSpecifierExpression( *$1 ); }
  ;


declarator
  : direct_declarator
  ;

direct_declarator
  : IDENTIFIER                                    { std::cout << "237--> " << *$1  << std::endl; $$ = new IdentifierDeclarator( new Identifier( *$1 ) ); }
  | '(' declarator ')'                            { std::cout << "238" << std::endl; $$ = new BracketedDeclarator( $2 ); }
  | direct_declarator '[' constant_expression ']' { std::cout << "239" << std::endl; $$ = new ExpressionDeclarator( $1, $3 ); }
  | direct_declarator '[' ']'                     { std::cout << "240" << std::endl; $$ = new ExpressionDeclarator( $1, NULL );}
  | direct_declarator '(' identifier_list ')'     { std::cout << "241" << std::endl; $$ = new ExpressionDeclarator( $1, $3 ); }
  | direct_declarator '(' parameter_list  ')'     { std::cout << "242 FUNCTION WITH PARAMS" << std::endl; $$ = new ParameterTypeDeclarator( $1, $3 ); }
  | direct_declarator '(' ')'                     { std::cout << "243" << std::endl; $$ = new EmptyDeclarator( $1 );}
  ;

parameter_list
  : parameter_declaration                         { std::cout << "247 PARAM LIST!" << std::endl; $$ = new ParamDeclarationList(); $$->AddItem( $1 ); }
  | parameter_list ',' parameter_declaration      { $$->AddItem( $3 ); }
  ;

parameter_declaration
  : declaration_specifiers declarator             { std::cout << "252 PARAMS!" << std::endl; $$ = new ParameterDeclaration( $1, $2 ); }
  | declaration_specifiers                        { $$ = new ParameterDeclaration( $1, NULL ); }
  ;

identifier_list
  : IDENTIFIER                      { std::cout << "257" << std::endl; $$ = new ExpressionList(); $$->AddItem(new Identifier( *$1 ) ); }
  | identifier_list ',' IDENTIFIER  { std::cout << "258" << std::endl; $$->AddItem(new Identifier( *$3 ) ); }
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
  : IDENTIFIER ':' statement                { std::cout << "260" << std::endl; $$ = new IdentifierStatement( new Identifier( *$1 ), $3 ); }
  | CASE constant_expression ':' statement  { std::cout << "261" << std::endl; $$ = new CaseStatement( $2, $4 ); }
  | DEFAULT ':' statement                   { std::cout << "262" << std::endl; $$ = new DefaultStatement( $3 ); }
  ;

compound_statement
  : '{' '}'                                   { std::cout << "266" << std::endl; $$ = new CompoundStatement( NULL, NULL ); }
  | '{' statement_list '}'                    { std::cout << "267" << std::endl; $$ = new CompoundStatement( $2, NULL ); }
  | '{' declaration_list '}'                  { std::cout << "268" << std::endl; $$ = new CompoundStatement( NULL, $2 ); }
  | '{' declaration_list statement_list '}'   { std::cout << "269" << std::endl; $$ = new CompoundStatement( $3, $2 ); }
  ;

declaration_list
  : declaration                   { std::cout << "273" << std::endl; $$ = new DeclarationList(); $$->AddItem( $1 ); }
  | declaration_list declaration  { std::cout << "274" << std::endl; $$->AddItem( $2 ); }
  ;

statement_list
  : statement                   { std::cout << "278" << std::endl; $$ = new StatementList(); $$->AddItem( $1 ); }
  | statement_list statement    { std::cout << "279" << std::endl; $$->AddItem( $2 ); }
  ;

expression_statement
  : ';'                 { std::cout << "283" << std::endl; $$ = new ExpressionStatement( NULL ); }
  | expression ';'      { std::cout << "284" << std::endl; $$ = new ExpressionStatement( $1 ); }
  ;


selection_statement
  : IF '(' expression ')' statement                 { std::cout << "289" << std::endl; $$ = new IfSelection( $3, $5 ); }
  | IF '(' expression ')' statement ELSE statement  { std::cout << "290" << std::endl; $$ = new IfElseSelection( $3, $5, $7 ); }
  | SWITCH '(' expression ')' statement             { std::cout << "291" << std::endl; $$ = new SwitchSelection( $3, $5 ); }
  ;

iteration_statement
  : WHILE '(' expression ')' statement                                          { std::cout << "295" << std::endl; $$ = new WhileIteration( $3, $5 ); }
  | DO statement WHILE '(' expression ')' ';'                                   { std::cout << "296" << std::endl; $$ = new DoWhileIteration( $2, $5 ); }
  | FOR '(' expression_statement expression_statement ')' statement             { std::cout << "297" << std::endl; $$ = new ForNoExprIteration( $3, $4, $6 ); }
  | FOR '(' expression_statement expression_statement expression ')' statement  { std::cout << "298" << std::endl; $$ = new ForExprIteration( $3, $4, $7, $5); }
  ;

jump_statement
  : GOTO IDENTIFIER ';'     { std::cout << "302" << std::endl; $$ = new GotoStatement( new Identifier( *$2 ) ); }
  | CONTINUE ';'            { std::cout << "303" << std::endl; $$ = new ContinueStatement( NULL ); }
  | BREAK ';'               { std::cout << "304" << std::endl; $$ = new BreakStatement( NULL ); }
  | RETURN ';'              { std::cout << "305" << std::endl; $$ = new ReturnStatement( NULL ); }
  | RETURN expression ';'   { std::cout << "306" << std::endl; $$ = new ReturnExprStatement( $2 ); }


this_unit
  : external_declaration            { std::cout << "311" << std::endl; }
  | this_unit external_declaration  { std::cout << "312" << std::endl; }
  ;

external_declaration
  : function_definition { std::cout << "315" << std::endl; $$ = new ExternalDeclaration( $1, NULL ); }
  | declaration         { std::cout << "316" << std::endl; $$ = new ExternalDeclaration( NULL, $1 ); }
  | declaration function_definition { std::cout << "332" << std::endl; $$ = new ExternalDeclaration( $2, $1 ); }
  ;

function_definition
  : declaration_specifiers declarator declaration_list compound_statement { std::cout << "320" << std::endl; $$ = new FunctionDefinition( $1, $2, $3, $4 ); }
  | declaration_specifiers declarator compound_statement                  { std::cout << "321" << std::endl; $$ = new FunctionDefinition( $1, $2, NULL, $3 ); }
  | declarator declaration_list compound_statement                        { std::cout << "322" << std::endl; $$ = new FunctionDefinition( NULL, $1, $2, $3 ); }
  | declarator compound_statement                                         { std::cout << "323" << std::endl; $$ = new FunctionDefinition( NULL, $1, NULL, $2 ); }
  ;



%%

const Unit *prog_root; // match variable defined earlier

const Unit *parseAST()
{
  prog_root = 0;
  yyparse();
  return prog_root;
}
