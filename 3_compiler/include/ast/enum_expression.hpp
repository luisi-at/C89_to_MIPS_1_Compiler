#ifndef ast_enumerator_expression_hpp
#define ast_enumerator_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>
#include <vector>

class EnumExpression : public Expression
{
  // inherits the vector anyway so use that
private:
  const Expression *left;
  const Expression *right;
public:
  EnumExpression(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

  const Expression *getLeft() const
  { return left; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  { /*printy printy*/  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {
    return "";
  }

};


class EnumSpecifier : public Expression
{
  // inherits the vector anyway so use that
private:
  const Expression *left;
  const Expression *right;
public:
  EnumSpecifier(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

  const Expression *getLeft() const
  { return left; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  { /*printy printy*/  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {
    return "";
  }

  // special methods for specifier

};

#endif
