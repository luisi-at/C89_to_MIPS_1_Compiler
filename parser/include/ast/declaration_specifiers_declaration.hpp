#ifndef ast_declaration_specifiers_declarator_hpp
#define ast_declaration_specifiers_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class DeclarationSpecifier : public Declarator
{
private:
  const Expression *specifier;
  const Declarator *declaration_specifier;

public:
  DeclarationSpecifier(const Expression *_specifier, const Declarator *_declaration_specifier)
  : specifier(_specifier)
  , declaration_specifier(_declaration_specifier)
  {}

  virtual void print_xml() const override
  {
    //printy xml
  }


};

#endif
