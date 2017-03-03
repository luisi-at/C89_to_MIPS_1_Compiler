#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class UnaryExpression : public Expression
{
private:
  const Expression *right;
protected:
  UnaryExpression(const Expression *_right)
    : right(_right)
{}
public:
  virtual ~UnaryExpression()
    {
        delete right;
    }

    virtual const char *getOperator() const =0;

    const Expression *getRight() const
    { return right; }

    virtual void print_xml() const override
    {
      fprintf(stderr, "Unary Expression Print") << std::endl;
      std::cout << this->getOperator() << std::endl;
      this->getRight()->print_xml();
    }

};

class UnaryPostfixExpression
  : public UnaryExpression
{
protected:
  virtual const char *getOperator() const override
  { return ""; }

public:
  UnaryPostfixExpression(const Expression *_right)
    :UnaryExpression(_right)
  {}

};

class UnaryIncExpression
  : public UnaryExpression
{
protected:
  virtual const char *getOperator() const override
  { return "++"; }

public:
  UnaryIncExpression(const Expression *_right)
  : UnaryExpression(_right)
  {}
};


class UnaryDecExpression
  : public UnaryExpression
{
protected:
  virtual const char *getOperator() const override
  { return "--"; }

public:
  UnaryDecExpression(const std::string _left, const Expression *_right)
  : UnaryExpression(_left, _right)
  {}
};


#endif
