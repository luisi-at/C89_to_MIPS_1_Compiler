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
  : statement (_statement)
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
  std::vector<const Statement*> *statements_list;
public:

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    statements_list->push_back(_item);
  }

  virtual void print_xml() const override
  {
    // statement printy
    for(std::vector<const Statement*>::iterator iter = statements_list->begin(); iter != statements_list->end(); ++iter){
      std::cout << "TRY PRINT LIST" << std::endl;
      (*iter)->print_xml();
    }
  }

};

#endif
