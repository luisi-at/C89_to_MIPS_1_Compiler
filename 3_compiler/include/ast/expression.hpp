#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "unit.hpp"

class Expression : public Unit
{
public:
    virtual ~Expression()
    {}

    virtual void print_xml() const = 0;

    virtual void codegen(Context &_context) const = 0;

    virtual std::string ReturnName() const = 0;

    virtual Expression* *AddItem(const Expression *_item) const = 0;

};


#endif
