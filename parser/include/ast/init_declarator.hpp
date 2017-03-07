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

  virtual void print_xml() const override
  {
    //printy xml
  }

};

// wrapper
class InitDeclaratorList : public Declarator
{
public:
  InitDeclaratorList()
  {}
};


#endif