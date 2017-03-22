#ifndef ast_initializer_expression_hpp
#define ast_initializer_expression_hpp

#include "expression.hpp"

class Initializer : public Expression
{
private:
  const Expression *left;
  const Expression *right;

public:
  Initializer(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

    const Expression *getLeft() const
    { return left; }

    const Expression *getRight() const
    { return right; }


  virtual void print_xml() const override
  {
    //std::cout << "INITIALIZER" << std::endl;
    this->getLeft()->print_xml();
    //this->getRight()->print_xml();
  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {
    return this->getLeft()->ReturnName();
  }

};


#endif
