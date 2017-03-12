#ifndef ast_conditional_expression_hpp
#define ast_conditional_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class ConditionalExpression : public Expression
{
private:
  const Expression *left;
  const Expression *middle;
  const Expression *right;
public:
  ConditionalExpression(const Expression *_left
    , const Expression *_middle
    , const Expression *_right)
    : left(_left)
    , middle(_middle)
    , right(_right)
  {}

  ~ConditionalExpression(){
    delete left;
    delete middle;
    delete right;
  }

  const Expression *getLeft() const
  { return left; }

  const Expression *getMiddle() const
  { return middle; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  {
    //std::cout << "CONDITIONAL EXPRESSION" << std::endl;
    this->getLeft()->print_xml();
    this->getMiddle()->print_xml();
    this->getRight()->print_xml();
  }

      virtual Expression* *AddItem(const Expression *_item) const override
      {
          return 0;
      }
};

#endif
