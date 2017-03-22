#ifndef ast_relational_expression_hpp
#define ast_relational_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class RelationalExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  RelationalExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~RelationalExpression()
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


    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
    }

};

class StrictLessThanExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return "<"; }

public:
  StrictLessThanExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class StrictGreaterThanExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return ">"; }

public:
  StrictGreaterThanExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class LessEqualExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return "<="; }

public:
  LessEqualExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class GreaterEqualExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return ">="; }

public:
  GreaterEqualExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

#endif
