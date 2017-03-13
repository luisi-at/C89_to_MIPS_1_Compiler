#ifndef ast_expression_statement_hpp
#define ast_expression_statement_hpp

#include "statement.hpp"

class ExpressionStatement : public Statement
{
private:
  const Expression *self_expression;

public:
  ExpressionStatement(const Expression *_in_expression)
    : self_expression(_in_expression)
    {}

  ~ExpressionStatement()
  { delete self_expression; }

  const Expression *getExpression() const
  { return self_expression; }

  virtual void print_xml() const override
  {
    //std::cout << "EXPRESSION STATEMENT" << std::endl;
    std::cout << "<Variable id= \"";
    this->getExpression()->print_xml();
    std::cout << "\"/>";
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

#endif
