#ifndef ast_main_declaration_declarator_hpp
#define ast_main_declaration_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class MainDeclaration : public Declarator
{
private:
  const Declarator *specifiers;
  const Declarator *init_list;

public:
  MainDeclaration(const Declarator *_specifiers, const Declarator *_init_list)
  : specifiers(_specifiers)
  , init_list(_init_list)
  {}

  virtual void print_xml() const override
  {
    //printy xml
  }


};

class DeclarationList : public Declarator
{
public:
  DeclarationList()
  {}
};

#endif
