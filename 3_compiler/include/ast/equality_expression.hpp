#ifndef ast_equality_expression_hpp
#define ast_equality_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class EqualityExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  EqualityExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~EqualityExpression()
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
      //std::cout << "EQUALITY EXPRESSION" << std::endl;
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

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
    }

};

class EqualOpExpression : public EqualityExpression
{
protected:
  virtual const char *getOperator() const override
  { return "=="; }

public:
  EqualOpExpression(const Expression *_left, const Expression *_right)
  : EqualityExpression(_left, _right)
  {}
};

class NotEqualOpExpression : public EqualityExpression
{
protected:
  virtual const char *getOperator() const override
  { return "!="; }
public:
  NotEqualOpExpression(const Expression *_left, const Expression *_right)
  : EqualityExpression(_left, _right)
    {}
};

#endif
