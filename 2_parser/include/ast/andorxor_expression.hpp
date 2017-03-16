#ifndef ast_andorxor_expression_hpp
#define ast_andorxor_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class AndOrXorExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  AndOrXorExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~AndOrXorExpression()
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
      //std::cout << "LOGICAL EXPRESSION" << std::endl;
      this->getLeft()->print_xml();
      this->getRight()->print_xml();

    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

};

class AndExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "&"; }

public:
  AndExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

class XorExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "^"; }

public:
  XorExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

class OrExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "|"; }

public:
  OrExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

#endif
