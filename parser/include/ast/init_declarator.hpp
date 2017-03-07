#ifndef ast_init_declarator_hpp
#define ast_init_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class InitDeclarator : public Declarator
{
private:
  const Declarator *left;
  const Expression *right;

public:
  InitDeclarator(const Declarator *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

const Expression *getRight() const
{
  return right;
}

const Declarator *getLeft() const
{
  return left;
}

  virtual void print_xml() const override
  {
    std::cout << "INIT DECLARATOR" << std::endl;
    this->getLeft()->print_xml();
    this->getRight()->print_xml();
  }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

};




#endif
