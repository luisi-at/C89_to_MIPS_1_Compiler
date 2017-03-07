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
    this->getStatement()->print_xml();
  }
};

// wrapper
class StatementList : public Statement
{
private:
   mutable std::vector<const Statement*> statements_list;
public:
  StatementList()
  {std::cout << "STATEMENT LIST" << std::endl;}
  virtual Statement* *AddItem(const Statement *_item) const override
  {
    std::cout << "ADD STATEMENT ITEM INSIDE" << std::endl;
    std::cout << "==============" << std::endl;

    std::cout << "==============" << std::endl;
    std::cout << _item << std::endl;
    statements_list.push_back(_item); // fails here
    std::cout << "AFTER PUSH BACK" << std::endl;
    this->print_xml();
  }

  virtual void print_xml() const override
  {
    // statement printy
    std::cout << "TRY PRINT LIST" << std::endl;
    /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
      (*iter)->print_xml();
    */
    std::cout << statements_list.size() << std::endl;
    for(int i = 0; i < statements_list.size(); i++){
      statements_list[i]->print_xml();
    }

  }




};

#endif
