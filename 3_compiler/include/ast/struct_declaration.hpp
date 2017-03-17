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

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {}

};

// wrapper to access vector

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

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {}

};

class StructUnionSpecifier : public Declarator
{
private:
  const Expression *left;
  const Expression *identifier;
  const Declarator *right;

public:
  StructUnionSpecifier(const Expression *_left, const Expression *_identifier, const Declarator *_right)
  : left(_left)
  , identifier(_identifier)
  , right(_right)
{}

  virtual void print_xml() const override
  {
    //printy xml
  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {}

};

#endif
