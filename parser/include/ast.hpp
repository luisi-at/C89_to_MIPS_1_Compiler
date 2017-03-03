#ifndef ast_hpp
#define ast_hpp

// include other AST classes here
#include "ast/expression.hpp"
#include "ast/primary_expression.hpp"
#include "ast/postfix_expression.hpp"
#include "ast/unary_expression.hpp"

extern const Expression *parseAST();

#endif
