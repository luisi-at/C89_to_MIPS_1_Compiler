#ifndef ast_jump_statement_hpp
#define ast_jump_statement_hpp

#include "statement.hpp"

class GotoStatement : public Statement
{
private:
  const Expression *jump_identifier;
public:
  GotoStatement(const Expression *_jump_to)
  : jump_identifier(_jump_to)
  {}

    const Expression *getJump() const
    { return jump_identifier; }

    virtual void print_xml() const override
    {
      this->getJump()->print_xml();
    }

    virtual Statement* *AddItem(const Statement *_item) const override
    {
      return 0;
    }

};

class ContinueStatement : public Statement
{
private:
  const Expression *continue_point;
public:
  ContinueStatement(const Expression *_jump_to)
  : continue_point(_jump_to)
  {}

  const Expression *getJump() const
  { return continue_point; }

  virtual void print_xml() const override
  {
    //printy xml
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

class BreakStatement : public Statement
{
private:
  const Expression *break_point;
public:
  BreakStatement(const Expression *_jump_to)
  : break_point(_jump_to)
  {}

  const Expression *getJump() const
  { return break_point; }

  virtual void print_xml() const override
  {
    //printy xml
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

class ReturnStatement : public Statement
{
protected:
  const Expression *return_point;
public:
  ReturnStatement(const Expression *_jump_to)
  : return_point(_jump_to)
  {}

  const Expression *getJump() const
  { return return_point; }

  virtual void print_xml() const override
  {
    //printy xml
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

class ReturnExprStatement : public Statement
{
private:
  const Expression *return_expression;
public:
  ReturnExprStatement(const Expression *_jump_to)
  : return_expression(_jump_to)
  {}

  const Expression *getJump() const
  { return return_expression; }


  virtual void print_xml() const override
  {
    this->getJump()->print_xml();
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};


#endif
