#ifndef ast_struct_declaration_hpp
#define ast_struct_declaration_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class StructDeclarator : public Declarator
{
private:
  const Declarator *left;
  const Expression *right;

public:
  StructDeclarator(const Declarator *_left, const Expression *_right)
  : left(_left)
  , right(_right)
{}

  virtual void print_xml() const override
  {
    //printy xml
  }


};

// wrapper to access vector
class StructDeclaratorList : public Declarator
{
public:
  StructDeclaratorList()
  {}
};

class StructDeclaration : public Declarator
{
private:
  const Expression *left;
  const Declarator *right;

public:
  StructDeclaration(const Expression *_left, const Declarator *_right)
  : left(_left)
  , right(_right)
{}

  virtual void print_xml() const override
  {
    //printy xml
  }


};

#endif
