#ifndef ast_selection_statement_hpp
#define ast_selection_statement_hpp

#include "statement.hpp"

class IfSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  IfSelection(const Expression _*first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

  



  virtual void print_xml() const override
  {

  }
}
