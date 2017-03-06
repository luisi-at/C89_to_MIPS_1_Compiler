#ifndef ast_unit_hpp
#define ast_unit_hpp

#include <string>
#include <iostream>
#include <vector>

class Unit{
public:
    virtual ~Unit()
    {}

    virtual void print_xml() const = 0;
};

#endif
