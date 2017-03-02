#ifndef ast_primary_expression_hpp
#define ast_primary_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class Identifier : public Expression
{
private:
  std::string id;
public:
  Identifier(const std::string _id) : id(_id)
  {}

  std::string GetValue() const
  { return id ; }

  virtual void print_xml() const override
  { std::cout << "<" << this->GetValue() << ">";  }
};

class Constant : public Expression
{
private:
  std::string value;
public:
  Constant(const std::string _value) : value(_value)
  {}

  std::string GetValue() const
  { return value ; }

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }
};

class StringLiteral : public Expression
{
private:
  std::string value;
public:
  StringLiteral(const std::string _value) : value(_value)
  {}

  std::string GetValue() const
  { return value ; }

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }
};

class BracketedExpression : public Expression
{
private:
  const Expression *sub_expression;
public:
  BracketedExpression(const Expression *_sub_expression) : sub_expression(_sub_expression)
  {}

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }
};

#endif
