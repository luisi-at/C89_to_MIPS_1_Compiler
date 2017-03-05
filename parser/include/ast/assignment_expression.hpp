#ifndef ast_assignment_expression_hpp
#define ast_assignment_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class AssignmentExpression : public Expression
{
private:
  const Expression *left;
  const std::string assignment_operator;
  const Expression *right;
public:
  AssignmentExpression(const Expression *_left
    , std::string _assignment_operator
    , const Expression *_right)
    : left(_left)
    , assignment_operator(_assignment_operator)
    , right(_right)
  {}

  ~AssignmentExpression(){
    delete left;
    delete right;
  }

  const Expression *getLeft() const
  { return left; }

  const std::string getOperator() const
  { return assignment_operator; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  {
    this->getLeft()->print_xml();
    std::cout << "OPERATOR COMING!" << std::endl;
    std::cout << this->getOperator() << std::endl;
    this->getRight()->print_xml();
  }
};

#endif
