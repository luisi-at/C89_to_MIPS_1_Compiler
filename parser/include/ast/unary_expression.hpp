#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

#include "expression.hpp"

#include <string.h>
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
      //std::cout << "UNARY EXPRESSION" << std::endl;
      //fprintf(stderr, "Unary Expression Print\n");
      if(strcmp(this->getOperator(), "") == 0){
        //std::cout << "UNARY EXPRESSION IF1" << std::endl;
        this->getRight()->print_xml();
      }
      else{
        //std::cout << this->getOperator() << std::endl;
        //std::cout << "UNARY EXPRESSION IF2" << std::endl;
        this->getRight()->print_xml();
      }

    }

          virtual Expression* *AddItem(const Expression *_item) const override
          {
              return 0;
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
  UnaryDecExpression(const Expression *_right)
  : UnaryExpression(_right)
  {}
};


#endif
