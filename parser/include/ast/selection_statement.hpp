#ifndef ast_selection_statement_hpp
#define ast_selection_statement_hpp

#include "statement.hpp"

class IfSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  IfSelection(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }



  virtual void print_xml() const override
  {
    std::cout << "IF" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

class IfElseSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
  const Statement *else_statement;
public:
  IfElseSelection(const Expression *_first, const Statement *_next, const Statement *_else)
    : first_expression(_first)
    , next_statement(_next)
    , else_statement(_else)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }

      const Statement *getElse() const
      { return else_statement; }


  virtual void print_xml() const override
  {
    std::cout << "IF ELSE" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

class SwitchSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  SwitchSelection(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }



  virtual void print_xml() const override
  {
    std::cout << "SWITCH" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }


};


#endif
