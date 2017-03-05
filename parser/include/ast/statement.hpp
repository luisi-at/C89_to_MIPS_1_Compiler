#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <vector>

#include "expression.hpp"

class Statement
{
protected:
  std::vector<Statement*> statement_ptrs; //maybe this?
public:
    virtual ~Statement()
    {}

    virtual void print_xml() const = 0;
};



#endif
