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
  const std::string right;
protected:
  PostfixExpression(const Expression *_left, const std::string _right)
  : left(_left)
  , right(_right)
{}
public:
  virtual ~PostfixExpression()
    {
        delete left;
    }

    virtual const char *getOperator() const =0;

    const Expression *getLeft() const
    { return left; }

    virtual void print_xml() const override
    {
      //std::cout << "left" << std::endl;
      //std::cout << "POSTFIX EXPRESSION" << std::endl;
      this->getLeft()->print_xml();
      std::cout << getOperator();
      if(right != ""){
        std::cout << right;
      }
    }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

};

class PostfixEmpty
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return ""; }

public:
  PostfixEmpty(const Expression *_left, const std::string _right)
    :PostfixExpression(_left, _right)
  {}

};

class PostfixPeriod
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "."; }

public:
  PostfixPeriod(const Expression *_left, const std::string _right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixPtrOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "->"; }

public:
  PostfixPtrOp(const Expression *_left, const std::string _right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixIncOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "++"; }

public:
  PostfixIncOp(const Expression *_left, const std::string _right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixDecOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "--"; }

public:
  PostfixDecOp(const Expression *_left, const std::string _right)
  :PostfixExpression(_left, _right)
  {}

};


#endif
