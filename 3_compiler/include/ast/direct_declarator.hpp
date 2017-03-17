#ifndef ast_direct_declarator_hpp
#define ast_direct_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class IdentifierDeclarator : public Declarator
{
private:
  const Expression *local_expression;

public:
  IdentifierDeclarator(const Expression *_local_expression)
  : local_expression(_local_expression)
  {}

    const Expression *getExpr() const{
      return local_expression;
    }

    virtual void print_xml() const override
    {
      //std::cout << "IdentifierDeclarator trace" << std::endl;
      //std::cout << "<Variable id= \"";
      this->getExpr()->print_xml();
      //std::cout << "\"/>" << std::endl;
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

    virtual std::string ReturnName() const override
    {}

};

class BracketedDeclarator : public Declarator
{
private:
  const Declarator *local_declarator;

public:
  BracketedDeclarator(const Declarator *_local_declarator)
  : local_declarator(_local_declarator)
  {}

    const Declarator *getDecl() const{
      return local_declarator;
    }

    virtual void print_xml() const override
    {
      std::cout << "Bracketed trace" << std::endl;
      this->getDecl()->print_xml();
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

    virtual std::string ReturnName() const override
    {}

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

    const Expression *getExpr() const{
      return declarator_identifier;
    }

    virtual void print_xml() const override
    {
      //std::cout << "ExpressionDeclarator trace" << std::endl;
      this->getExpr()->print_xml();
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

    virtual std::string ReturnName() const override
    {}


};

class EmptyDeclarator : public Declarator
{
private:
  const Declarator *left;

public:
  EmptyDeclarator(const Declarator *_left)
  : left(_left)
  {}

    const Declarator *getLeft() const{
      return left;
    }

    virtual void print_xml() const override
    {
      //std::cout << "EmptyDeclarator trace" << std::endl;
      this->getLeft()->print_xml();
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

    }

    virtual std::string ReturnName() const override
    {}

};

class ParameterTypeDeclarator : public Declarator
{
private:
  const Declarator *left;
  const Declarator *right;

public:
  ParameterTypeDeclarator(const Declarator *_left, const Declarator *_right)
  : left(_left)
  , right(_right)
  {}

  const Declarator *getLeft() const
  {
    return left;
  }

  const Declarator *getRight() const
  {
    return right;
  }

  virtual void print_xml() const override
  {
    //std::cout << "PARAM TYPE DECLARATOR" << std::endl;
    //std::cout << "LEFT PARAM DECLARATOR" << std::endl;
    this->getLeft()->print_xml();
    std::cout << " \"/>" << std::endl;
    //std::cout << "RIGHT PARAM DECLARATOR" << std::endl;

    this->getRight()->print_xml();

  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {}

};

#endif
