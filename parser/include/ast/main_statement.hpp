#ifndef ast_main_statement_hpp
#define ast_main_statement_hpp

#include "statement.hpp"

#include <string>
#include <iostream>
#include <map>

class MainStatement : public Statement
{
private:
  const Statement *statement;
public:
  MainStatement(const Statement *_statement)
  :
  {}

  ~MainStatement(){
    delete statement;
  }

  const Statement *getStatement() const
  { return statement; }

  virtual void print_xml() const override
  {
    // statement printy
  }
};

#endif
