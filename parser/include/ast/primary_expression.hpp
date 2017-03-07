#ifndef ast_primary_expression_hpp
#define ast_primary_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class Identifier : public Expression
{
private:
  const std::string id;
public:
  Identifier(const std::string _id) : id(_id)
  {}

  std::string GetValue() const
  { return id ; }

  virtual void print_xml() const override
  { std::cout << "<" << this->GetValue() << ">";  }
      
      virtual Expression* *AddItem(const Expression *_item) const override
      {
          return 0;
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
  { std::cout << "<" << this->GetValue() << ">"; }
    
    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
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
  { std::cout << "<" << this->GetValue() << ">"; }
    
    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }
};

class BracketedExpression : public Expression
{
private:
  const Expression *sub_expression;
public:
  BracketedExpression(const Expression *_sub_expression) : sub_expression(_sub_expression)
  {}

  virtual void print_xml() const override
  { /*xml printy stuff in here */ }
    
    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
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
  { /*xml printy stuff in here */ }
    
    
    
    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
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
};

//wrapper
class IdentifierList : public Expression
{
public:
  IdentifierList()
  {}

  virtual void print_xml() const override
  {
    //printy xml
  }
    
    
    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }
    
    

};

#endif
