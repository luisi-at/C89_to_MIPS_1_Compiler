#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "unit.hpp"
#include "expression.hpp"
#include "statement.hpp"
#include "declarator.hpp"

class FunctionDefinition : public Unit
{
private:
  const Declarator *specifiers;
  const Declarator *declarator;
  const Declarator *declaration_list;
  const Statement *compound_statement;

public:
  FunctionDefinition(const Declarator *_specifiers
  , const Declarator *_declarator
  , const Declarator *_declaration_list
  , const Statement *_compound_statement)
  : specifiers(_specifiers)
  , declarator(_declarator)
  , declaration_list(_declaration_list)
  , compound_statement(_compound_statement)
  {}

    virtual void print_xml() const override
    {
      // xml printy
    }
};


#endif
