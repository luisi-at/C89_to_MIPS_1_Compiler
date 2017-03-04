#ifndef ast_shift_expression_hpp
#define ast_shift_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class ShiftExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  ShiftExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~ShiftExpression()
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
      this->getLeft()->print_xml();
      std::cout << this->getOperator() << std::endl;
      this->getRight()->print_xml();
    }

};

class LeftOpExpression : public ShiftExpression
{
protected:
  virtual const char *getOperator() const override
  { return "<<"; }

public:
  LeftOpExpression(const Expression *_left, const Expression *_right)
  : ShiftExpression(_left, _right)
  {}

};

class RightOpExpression : public ShiftExpression
{
protected:
  virtual const char *getOperator() const override
  { return ">>"; }

public:
  RightOpExpression(const Expression *_left, const Expression *_right)
  : ShiftExpression(_left, _right)
  {}

};

#endif