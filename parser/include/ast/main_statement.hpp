#ifndef ast_main_statement_hpp
#define ast_main_statement_hpp

#include "statement.hpp"

#include <string>
#include <iostream>
#include <map>
#include <vector>

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

// wrapper
class StatementList : public Statement
{
private:
  const std::vector<Statement*> statements_list;
public:
  StatementList()
  {}

  void AddItem(const Statement *_item)
  {
    statements_list.push_back(_item);
  }

};

#endif
