%option noyywrap
%option yylineno


%{
/* C embedded into autogenerated code goes here,
need to include any header files that may be needed */

extern "C" int fileno(FILE *stream);

//#include "c_lexer.hpp"
#include "c_parser.tab.hpp"

%}

/* Definitions as defined by the C89/C90 Specification */

delim                         [ \t\r\f]
carriage_return               [\n]
whitespace                    {delim}

nondigit                      [_a-zA-Z]
digit                         [0-9]
sign                          [+-]

nonzero_digit                 [1-9]
octal_digit                   [0-7]
hexadecimal_digit             [0-9a-fA-F]
unsigned_suffix               [uU]
long_suffix                   [lL]
exponent                      [eE]
floating_suffix               [flFL]

identifier                    {nondigit}+({nondigit}+|{digit}+)*

decimal_constant              {nonzero_digit}+{digit}*
octal_constant                0{octal_digit}+
hexadecimal_constant          (0x|0X){hexadecimal_digit}+
integer_constant              ({decimal_constant}({unsigned_suffix}|{long_suffix})?)|({octal_constant}({unsigned_suffix}|{long_suffix})?)|({hexadecimal_constant}({unsigned_suffix}|{long_suffix})?)

digit_sequence                {digit}+
fractional_constant           ({digit_sequence}?\.{digit_sequence}|{digit_sequence}\.)
exponent_part                 {exponent}{sign}?{digit_sequence}
floating_constant             ({fractional_constant}{exponent_part}?{floating_suffix}?)|({digit_sequence}{exponent_part}{floating_suffix}?)

enumeration_constant          {identifier}

simple_escape_sequence        \\['"?abfnrtv]
octal_escape_sequence         \\{octal_digit}+
hexadecimal_escape_sequence   \\{hexadecimal_digit}+
escape_sequence               {simple_escape_sequence}|{octal_escape_sequence}|{hexadecimal_escape_sequence}

character_constant            (\'[^\'\\\n]+\')|(L\'[^\'\\\n]+\')

preprocessor                  #[ ]{digit_sequence}[ ]\".*\"([ ]{digit_sequence})*

/* s_char_sequence essentially takes the c_char sequence but bundles it within quotation marks */
/* this may need further investigation */

string_literal                L?\"(\\.|[^\\"\n])*\"


ellipsis                      (\.\.\.)
operator                      {single_operator}
/* are there more ^^? */

%%

{whitespace}                  { }

{preprocessor}                { }

{digit_sequence}              { yylval.string_value = new std::string(yytext); return CONSTANT; }

{hexadecimal_constant}        { yylval.string_value = new std::string(yytext); return CONSTANT; } //return constant and the value

{integer_constant}            { yylval.string_value = new std::string(yytext); return CONSTANT; }

{floating_constant}           { yylval.string_value = new std::string(yytext); return CONSTANT; }

{character_constant}          { yylval.string_value = new std::string(yytext); return CONSTANT; } //return constant and value

{string_literal}              { yylval.string_value = new std::string(yytext); return(STRING_LITERAL); } //return constant and value

{escape_sequence}             { }


auto                          { return AUTO; }
double                        { return DOUBLE; }
int                           { yylval.string_value = new std::string(yytext); return(INT); }
struct                        { return STRUCT; }
break                         { return BREAK; }
else                          { return ELSE; }
long                          { return LONG; }
switch                        { return SWITCH; }
case                          { return CASE; }
enum                          { return ENUM; }
register                      { return REGISTER; }
typedef                       { return TYPEDEF; }
char                          { return CHAR; }
extern                        { return EXTERN; }
return                        { return RETURN; }
union                         { return UNION; }
const                         { return CONST; }
float                         { return FLOAT; }
short                         { return SHORT; }
unsigned                      { return UNSIGNED; }
continue                      { return CONTINUE; }
for                           { return FOR; }
signed                        { return SIGNED; }
void                          { return VOID; }
default                       { return DEFAULT; }
goto                          { return GOTO; }
sizeof                        { return SIZEOF; }
volatile                      { return VOLATILE; }
do                            { return DO; }
if                            { return IF; }
static                        { return STATIC; }
while                         { return(WHILE); }

{identifier}                  { yylval.string_value = new std::string(yytext); return(IDENTIFIER); } //return identifier



"++"                          { return INC_OP; }
"--"                          { return DEC_OP; }
"+="                          { yylval.string_value = new std::string(yytext); return ADD_ASSIGN; }
"-="                          { yylval.string_value = new std::string(yytext); return SUB_ASSIGN; }
"*="                          { yylval.string_value = new std::string(yytext); return MUL_ASSIGN; }
"/="                          { yylval.string_value = new std::string(yytext); return DIV_ASSIGN; }
"%="                          { yylval.string_value = new std::string(yytext); return MOD_ASSIGN; }
"&="                          { yylval.string_value = new std::string(yytext); return AND_ASSIGN; }
"|="                          { yylval.string_value = new std::string(yytext); return OR_ASSIGN; }
"^="                          { yylval.string_value = new std::string(yytext); return XOR_ASSIGN; }
"<<="                         { yylval.string_value = new std::string(yytext); return LEFT_ASSIGN; }
">>="                         { yylval.string_value = new std::string(yytext); return RIGHT_ASSIGN; }
"<="                          { return LE_OP; }
">="                          { return GE_OP; }
"=="                          { return EQ_OP; }
"!="                          { return NE_OP; }
"&&"                          { return AND_OP; }
"||"                          { return OR_OP; }
"<<"                          { return LEFT_OP; }
">>"                          { return RIGHT_OP; }
"->"                          { return PTR_OP; }

"<"                           { yylval.string_value = new std::string(yytext); return('<'); }
">"                           { return('>'); }
"{"                           { yylval.string_value = new std::string(yytext); return('{'); }
"}"                           { yylval.string_value = new std::string(yytext); return('}'); }
"["                           { return('['); }
"]"                           { return(']'); }
"("                           { return('('); }
")"                           { return(')'); }
"+"                           { yylval.string_value = new std::string(yytext); return('+'); }
"-"                           { yylval.string_value = new std::string(yytext); return('-'); }
"*"                           { yylval.string_value = new std::string(yytext); return('*'); }
"/"                           { yylval.string_value = new std::string(yytext); return('/'); }
"="                           { yylval.string_value = new std::string(yytext); return ASSIGN; }
"%"                           { yylval.string_value = new std::string(yytext); return('%'); }
"."                           { return('.'); }
","                           { return(','); }
":"                           { return(':'); }
";"                           { yylval.string_value = new std::string(yytext); return(';'); }
"~"                           { return('~'); }
"&"                           { return('&'); }
"!"                           { return('!'); }
"|"                           { return('|'); }
"^"                           { return('^'); }
"?"                           { return('?'); }


{ellipsis}                    { return ELLIPSIS; }



{carriage_return}             {  }

.                             {  }
%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Token Value: %s\n", yytext);
  fprintf (stderr, "Flex Error: %s\n", yytext); /* s is the text that wasn't matched */
  exit(1);
}
