%code requires{
  #include "ast.hpp"
  #include <cassert>

  int yylex(void);
  void yyerror(const char *);
}
