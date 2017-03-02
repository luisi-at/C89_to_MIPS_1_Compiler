#ifndef ast_postfix_expression_hpp
#define ast_postfix_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class PostfixExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  PostfixExpression(const Expression *_left,
    const std::string _middle, const Expression *_right)
  : left(_left)
  , right(_right)
{}
public:
  virtual ~PostfixExpression()
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
        // xml printing info here- look at spec
    }

};

class PostfixPrimary : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return ""; }

public:
  PostfixPrimary(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

};

class PostfixPeriod : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "."; }

public:
  PostfixPrimary(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

};

class PostfixPtrOp : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "->"; }

public:
  PostfixPrimary(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

};

class PostfixIncOp : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "++"; }

public:
  PostfixPrimary(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

};

class PostfixDecOp : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "--"; }

public:
  PostfixPrimary(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

};


#endif
