#ifndef ast_additive_expression_hpp
#define ast_additive_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class AdditiveExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  AdditiveExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~AdditiveExpression()
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
      //std::cout << "ADDITIVE EXPRESSION" << std::endl;
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

class AddAdditive : public AdditiveExpression
{
protected:
  virtual const char *getOperator() const override
  { return "+"; }

public:
  AddAdditive(const Expression *_left, const Expression *_right)
  : AdditiveExpression(_left, _right)
  {}

};

class SubAdditive : public AdditiveExpression
{
protected:
  virtual const char *getOperator() const override
  { return "-"; }

public:
  SubAdditive(const Expression *_left, const Expression *_right)
  : AdditiveExpression(_left, _right)
  {}

};

#endif
