#ifndef ast_unit_hpp
#define ast_unit_hpp

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>

#include "context.hpp"

class Unit
{
public:
    virtual ~Unit()
    {}

    virtual void print_xml() const = 0;

    virtual void codegen(Context &_context) const = 0;

    virtual std::string ReturnName() const = 0;
};



#endif
