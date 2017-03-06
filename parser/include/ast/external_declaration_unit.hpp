#ifndef ast_external_declaration_hpp
#define ast_external_declaration_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "unit.hpp"
#include "function_definition_unit.hpp"
#include "declarator.hpp"

class ExternalDeclaration : public Unit
{
private:
  const FunctionDefinition *func_def;
  const Declarator *declaration;

public:

  ExternalDeclaration(const FunctionDefinition *_func_def
  , const Declarator *_declaration)
  : func_def(_func_def)
  , declaration(_declaration)
{}

  virtual void print_xml() const override
  {
    // xml printy
  }
};

#endif
