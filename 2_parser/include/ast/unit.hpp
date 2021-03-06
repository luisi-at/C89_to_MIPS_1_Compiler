#ifndef ast_unit_hpp
#define ast_unit_hpp

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "context.hpp"

class Unit
{
public:
    virtual ~Unit()
    {}

    virtual void print_xml() const = 0;

    virtual void codegen(Context &_context) const = 0;
};



#endif
