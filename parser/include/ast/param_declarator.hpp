#ifndef ast_param_declarator_hpp
#define ast_param_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class ParameterDeclaration : public Declarator
{
private:
  const Declarator *specifiers;
  const Declarator *right_declarator;

public:
  ParameterDeclaration(const Declarator *_specifiers, const Declarator *_right_declarator)
  : specifiers(_specifiers)
  , right_declarator(_right_declarator)
  {}

    const Declarator *getSpecifiers() const{
      return specifiers;
    }
    const Declarator *getRightDeclarator() const{
      return right_declarator;
    }

    virtual void print_xml() const override
    {
      //std::cout << "------------PARAMETER TIME------------" << std::endl;
      this->getSpecifiers()->print_xml();
      if(this->getRightDeclarator()){
        this->getRightDeclarator()->print_xml();
      }
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }
};

#endif
