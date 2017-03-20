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
    //std::cout << "ASSIGNMENT EXPRESSION" << std::endl;
    //this->getLeft()->print_xml();
    //this->getRight()->print_xml();
  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    // get the string values to store in the context
    std::string leftString = this->getLeft()->ReturnName();
    std::string rightString = this->getRight()->ReturnName();
    // check to see if the right returned string contains a hash
    // if so, split at the hash and remove the hash
    // this means that variable names can now appear in the value field of the context
    // search through the keys of the map to find any matches
    // if there are matches, map the variable name to a register

  }

  virtual std::string ReturnName() const override
  {
    // separate the return strings with a hash to make one string
    return this->getLeft()->ReturnName() + "#" + this->getRight()->ReturnName();

  }

};

#endif
