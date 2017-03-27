#ifndef ast_initializer_expression_hpp
#define ast_initializer_expression_hpp

#include "expression.hpp"

class Initializer : public Expression
{
private:
  const Expression *left;

public:
  Initializer(const Expression *_left)
  : left(_left)
  {}

    const Expression *getLeft() const
    { return left; }

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
    std::cout << "INITIALIZER" << std::endl;
    this->getLeft()->codegen(_context);

  }

  virtual std::string ReturnName() const override
  {
    return this->getLeft()->ReturnName();
  }

};


#endif
