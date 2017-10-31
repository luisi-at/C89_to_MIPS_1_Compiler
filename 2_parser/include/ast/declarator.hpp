#ifndef ast_declarator_hpp
#define ast_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "unit.hpp"

class Declarator : public Unit
{
protected:
  std::vector<Declarator*> declaration_ptrs; //maybe this?
public:
    virtual ~Declarator()
    {}

    virtual void print_xml() const = 0;

    virtual void codegen(Context &_context) const = 0;

    virtual Declarator* *AddItem(const Declarator *_item) const = 0;


};



#endif
