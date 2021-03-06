#ifndef ast_hpp
#define ast_hpp

#include <vector>
#include <map>

// include other AST classes here

#include "ast/context.hpp"

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
#include "ast/conditional_expression.hpp"
#include "ast/assignment_expression.hpp"
#include "ast/main_expression.hpp"
#include "ast/enum_expression.hpp"
#include "ast/initializer_expression.hpp"
#include "ast/statement.hpp"
#include "ast/labeled_statement.hpp"
#include "ast/expression_statement.hpp"
#include "ast/selection_statement.hpp"
#include "ast/iteration_statement.hpp"
#include "ast/jump_statement.hpp"
#include "ast/compound_statement.hpp"
#include "ast/main_statement.hpp"
#include "ast/declarator.hpp"
#include "ast/direct_declarator.hpp"
#include "ast/struct_declaration.hpp"
#include "ast/declaration_specifiers_declaration.hpp"
#include "ast/init_declarator.hpp"
#include "ast/main_declaration.hpp"
#include "ast/param_declarator.hpp"

#include "ast/function_definition_unit.hpp"
#include "ast/external_declaration_unit.hpp"

extern const Unit *parseAST();


#endif
