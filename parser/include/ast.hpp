#ifndef ast_hpp
#define ast_hpp

// include other AST classes here
#include "ast/expression.hpp"
#include "ast/primary_expression.hpp"
#include "ast/postfix_expression.hpp"
#include "ast/unary_expression.hpp"
#include "ast/multiplicative_expression.hpp"
#include "ast/additive_expression.hpp"
#include "ast/shift_expression.hpp"
#include "ast/relational_expression.hpp"
#include "ast/equality_expression.hpp"
#include "ast/andorxor_expression.hpp"
#include "ast/logicalandor_expression.hpp"

extern const Expression *parseAST();

#endif
