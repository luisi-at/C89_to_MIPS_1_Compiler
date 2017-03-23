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
      //std::cout << "LOGICAL AND OR" << std::endl;
      this->getLeft()->print_xml();
      this->getRight()->print_xml();

    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      if(this->getOperator() == "&&"){
        _context.opUsedInIf.first = "&&";
        // essentially just carries out what is in the brackets that number of times
        // leave the if statement or the loop to deal with the labelling and the nops
        // both branch commands are dependent opposite to what is in the sub expression
        this->getLeft()->codegen(_context);
        this->getRight()->codegen(_context);
      }
      else if(this->getOperator() == "||"){
        // both branch commands are opposite to what corresponds to the sub expression
        _context.opUsedInIf.first = "||";
        this->getLeft()->codegen(_context);
        this->getRight()->codegen(_context);
      }

    }

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
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
