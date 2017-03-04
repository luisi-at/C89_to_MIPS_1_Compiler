#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class MultiplicativeExpression : public Expression
{
private:
  const Expression *left
  const Expression *right;
protected:
  MultiplicativeExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~UnaryExpression()
    {
        delete left;
        delete right;
    }

    virtual const char *getOperator() const =0;

    const Expression *getLeft() const
    { return left; }

    const Expression *getRight() const
    { return right; }

    virtual void print_xml() const override
    {
      // printy print
    }

};

class MultiplyMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "*"; }

public:
  MultiplyMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};

class DivideMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "/"; }

public:
  DivideMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};

class ModMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "%"; }

public:
  ModMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};
