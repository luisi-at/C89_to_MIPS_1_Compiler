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

  virtual void print_xml() const override
  {}

};

// wrapper again
class InitializerList : public Expression
{
public:
  InitializerList()
  {}
};

#endif
