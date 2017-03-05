#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include "statement.hpp"

class WhileIteration : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  WhileIteration(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }

  virtual void print_xml() const override
  {
    //printy xml
  }
};

class DoWhileIteration : public Statement
{
private:
  const Statement *first_statement;
  const Expression *loop_expression;
public:
  DoWhileIteration(const Statement *_first, const Expression *_loop)
    : first_statement(_first)
    , loop_expression(_loop)
    {}

      const Statement *getFirst() const
      { return first_statement; }

      const Expression *getLoop() const
      { return loop_expression; }



  virtual void print_xml() const override
  {
    //printy xml
  }
};

class ForNoExprIteration : public Statement
{
private:
  const Statement *first_statement;
  const Statement *second_statement;
  const Statement *third_statement;
public:
  ForNoExprIteration(const Statement *_first
    , const Statement *_second
    , const Statement *_third
    , const Expression *_loop)
    : first_statement(_first)
    , second_statement(_second)
    , third_statement(_third)
    {}

  const Statement *getFirst() const
  { return first_statement; }

  const Statement *getSecond() const
  { return second_statement; }

  const Statement *getThird() const
  { return third_statement; }


  virtual void print_xml() const override
  {
    //printy xml
  }
};

class ForExprIteration : public Statement
{
private:
  const Statement *first_statement;
  const Statement *second_statement;
  const Statement *third_statement;
  const Expression *loop_expression;
public:
  ForExprIteration(const Statement *_first
    , const Statement *_second
    , const Statement *_third
    , const Expression *_loop)
    : first_statement(_first)
    , second_statement(_second)
    , third_statement(_third)
    , loop_expression(_loop)
    {}

  const Statement *getFirst() const
  { return first_statement; }

  const Statement *getSecond() const
  { return second_statement; }

  const Statement *getThird() const
  { return third_statement; }

  const Expression *getLoopExpr() const
  { return loop_expression; }

  virtual void print_xml() const override
  {
    //printy xml
  }
};


#endif
