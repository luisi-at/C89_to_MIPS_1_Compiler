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
    this->getRight()->print_xml();
  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
    return 0;
  }

};

class ExpressionList : public Expression
{
private:
   mutable std::vector<const Expression*> expressions_list;
public:

  virtual Expression* *AddItem(const Expression *_item) const override
  {
    std::cout << "ADD ITEM INSIDE" << std::endl;
    std::cout << "==============" << std::endl;

    std::cout << "==============" << std::endl;
    std::cout << _item << std::endl;
    expressions_list.push_back(_item); // fails here
    std::cout << "AFTER PUSH BACK" << std::endl;
    this->print_xml();
  }

  virtual void print_xml() const override
  {
    // statement printy
    std::cout << "TRY PRINT LIST" << std::endl;
    /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
      (*iter)->print_xml();
    */
    std::cout << expressions_list.size() << std::endl;
    for(int i = 0; i < expressions_list.size(); i++){
      expressions_list[i]->print_xml();
    }

  }

};

#endif
