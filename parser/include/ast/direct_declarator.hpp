#ifndef ast_direct_declarator_hpp
#define ast_direct_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "expression.hpp"

class BracketedDeclarator : public Declarator
{
private:
  const Declarator *local_declarator;

public:
  BracketedDeclarator(const Declarator *_local_declarator)
  : local_declarator(_local_declarator)
  {}

    virtual void print_xml() const override
    {
      //printy xml
    }
};


class ExpressionDeclarator : public Declarator
{
private:
  const Expression *declarator_identifier;
  const Declarator *left;

public:
  ExpressionDeclarator(const Declarator *_left, const Expression *_dec_id)
  : declarator_identifier(_dec_id)
  , left(_left)
  {}

    virtual void print_xml() const override
    {
      //printy xml
    }

};

/*class ParameterTypeDeclarator : public Declarator
{
private:
  std::vector<Declarator*> param_type_list;
  const Declarator *left;

public:
  ParameterTypeDeclarator(const Declarator *_left, std::vector<Declarator*> _param_type_list)
  : param_type_list(_param_type_list)
  , left(_left)
  {}

  virtual void print_xml() const override
  {
    //printy xml
  }

};

class IdentifierListDeclarator : public Declarator
{
private:
  std::vector<Expression*> identifier_list;
  const Declarator *left;

public:
  IdentifierListDeclarator(const Declarator *_left, std::vector<Declarator*> _identifier_list)
  : identifier_list(_identifier_list)
  , left(_left)
  {}

  virtual void print_xml() const override
  {
    //printy xml
  }

}; */

#endif
