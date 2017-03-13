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

  const Unit* getFunction() const{
    return func_def;
  }

  const Unit* getDeclarator() const{
    return declaration;
  }

  virtual void print_xml() const override
  {
    if(this->getFunction()){
      this->getFunction()->print_xml();
    }
    if(this->getDeclarator()){
      this->getDeclarator()->print_xml();
    }
  }
};

#endif
