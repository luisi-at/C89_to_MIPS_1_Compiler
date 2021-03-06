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

    const Expression *getExpression() const{
      return specifier;
    }

    const Declarator *getDeclarator() const{
      return declaration_specifier;
    }

  virtual void print_xml() const override
  {
    //std::cout << "DECLARATION SPECIFIERS" << std::endl;
    //this->getExpression()->print_xml();
    if(this->getDeclarator()){
      this->getDeclarator()->print_xml();
    }

  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    //std::cout << "DECLARATION SPECIFIERS" << std::endl;
    this->getExpression()->codegen(_context);
    this->getDeclarator()->codegen(_context);
  }

  virtual std::string ReturnName() const override
  {
    //std::cout << "RETURN NAME DECLARATION SPECIFIERS" << std::endl;
    return this->getDeclarator()->ReturnName();
  }


};

#endif
