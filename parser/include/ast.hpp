#ifndef ast_hpp
#define ast_hpp

// include other AST classes here
#include "ast/program.hpp"
#include "ast/expression.hpp"
#include "ast/primary_expression.hpp"
#include "ast/postfix_expression.hpp"

extern const Expression *parseAST();

#endif
