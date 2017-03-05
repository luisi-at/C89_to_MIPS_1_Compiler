#ifndef ast_declarator_hpp
#define ast_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "expression.hpp"

class Declarator
{
protected:
  std::vector<Declarator*> declaration_ptrs; //maybe this?
public:
    virtual ~Declarator()
    {}

    virtual void print_xml() const = 0;
};



#endif
