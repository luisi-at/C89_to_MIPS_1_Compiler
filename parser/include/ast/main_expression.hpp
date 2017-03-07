#ifndef ast_main_expression_hpp
#define ast_main_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class MainExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
public:
  MainExpression(const Expression *_left
    , const Expression *_right)
    : left(_left)
    , right(_right)
  {}

  ~MainExpression(){
    delete left;
    delete right;
  }

  const Expression *getLeft() const
  { return left; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  {
    this->getLeft()->print_xml();
    std::cout << ',' << std::endl;
    this->getRight()->print_xml();
  }




};

#endif
