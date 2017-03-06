#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

class Expression
{
protected:
  std::vector<Expression*> expression_list;
public:
    virtual ~Expression()
    {}

    virtual void print_xml() const = 0;
};


#endif
