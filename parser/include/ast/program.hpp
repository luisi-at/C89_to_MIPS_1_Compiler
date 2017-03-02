#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>


class Program
{
public:
    virtual ~Program()
    {}

    virtual void print_xml() const = 0;
};


#endif
