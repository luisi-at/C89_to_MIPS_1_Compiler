#ifndef ast_logicalandor_expression_hpp
#define ast_logicalandor_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class LogicalAndOrExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  LogicalAndOrExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~LogicalAndOrExpression()
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

class LogicalAndExpression : public LogicalAndOrExpression
{
protected:
  virtual const char *getOperator() const override
  { return "&&"; }

public:
  LogicalAndExpression(const Expression *_left, const Expression *_right)
  : LogicalAndOrExpression(_left, _right)
  {}
};

class LogicalOrExpression : public LogicalAndOrExpression
{
protected:
  virtual const char *getOperator() const override
  { return "||"; }

public:
  LogicalOrExpression(const Expression *_left, const Expression *_right)
  : LogicalAndOrExpression(_left, _right)
  {}
};


#endif