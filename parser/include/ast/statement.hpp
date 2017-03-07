#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <vector>

#include "unit.hpp"
#include "expression.hpp"

class Statement : public Unit
{
public:
    virtual ~Statement()
    {}

    virtual void print_xml() const = 0;

    virtual Statement* *AddItem(const Statement *_item) const = 0;

};



#endif
