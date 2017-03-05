#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include "statement.hpp"

class IterationStatement : public Statement
{
private:
  const Expression *left;
  const Statement *right;
protected:
  LabeledStatement(const Statement *_right)
    : right(_right)
    {}
  LabeledStatement(const Expression *_left, const Statement *_right)
    : left(_left)
    , right(_right)
    {}
public:
  virtual ~LabeledStatement()
    {
        delete left;
        delete right;
    }

    const Expression *getLeft() const
    { return left; }

    const Statement *getRight() const
    { return right; }

    virtual void print_xml() const = 0;

};
