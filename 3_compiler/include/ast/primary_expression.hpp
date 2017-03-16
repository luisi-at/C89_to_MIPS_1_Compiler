#ifndef ast_primary_expression_hpp
#define ast_primary_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>
#include <algorithm>

class Identifier : public Expression
{
private:
  mutable std::string id;
public:
  Identifier(const std::string _id) : id(_id)
  {}

  std::string GetValue() const
  {
    return id;
  }

  virtual void print_xml() const override
  {
    std::cout << this->GetValue();

  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

};


class Constant : public Expression
{
private:
  std::string value;
public:
  Constant(const std::string _value) : value(_value)
  {}

  std::string GetValue() const
  { return value ; }

  virtual void print_xml() const override
  {
    //std::cout << "IN CONST" << std::endl;
    //std::cout << "VALUE --> <" << this->GetValue() << ">";

  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

};

class StringLiteral : public Expression
{
private:
  std::string value;
public:
  StringLiteral(const std::string _value) : value(_value)
  {}

  std::string GetValue() const
  { return value ; }

  virtual void print_xml() const override
  {

  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

};

class BracketedExpression : public Expression
{
private:
  const Expression *sub_expression;
public:
  BracketedExpression(const Expression *_sub_expression) : sub_expression(_sub_expression)
  {}

  const Expression* GetValue() const
  { return sub_expression; }

  virtual void print_xml() const override
  {

  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

};

class TypeQualifierExpression : public Expression
{
private:
  const std::string type_qualifier;
public:
  TypeQualifierExpression(const std::string _type_qualifier) : type_qualifier(_type_qualifier)
  {}

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }

  virtual void codegen(Context &_context) const override
  {

  }

};

// another wrapper to access the vector, still treated as expression
class TypeQualifierExpressionList : public Expression
{
public:
  TypeQualifierExpressionList()
  {}

  virtual void print_xml() const override
  { /*printy printy*/  }


    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

};

class StorageClassSpecifierExpression : public Expression
{
private:
  const std::string storage_class;
public:
  StorageClassSpecifierExpression(const std::string _storage_class)
  : storage_class(_storage_class)
  {}

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }



    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }


};

class TypeSpecifierExpression : public Expression
{
private:
  const std::string type_class;
public:
  TypeSpecifierExpression(const std::string _type_class)
  : type_class(_type_class)
  {}

  virtual void print_xml() const override
  {
    //std::cout << "TYPE SPECIFIER EXPRESSION" << std::endl;
    //std::cout << type_class << std::endl;
  }



  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }


};

class TypeSpecifierExplicitExpression : public Expression
{
private:
  const Expression *sub_expression;
public:
  TypeSpecifierExplicitExpression(const Expression *_sub_expression)
  : sub_expression(_sub_expression)
  {}

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }

  virtual void codegen(Context &_context) const override
  {

  }

};


#endif
