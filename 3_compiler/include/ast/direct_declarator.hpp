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

    const Expression *getExpression() const{
      return local_expression;
    }

    virtual void print_xml() const override
    {
      //std::cout << "IdentifierDeclarator trace" << std::endl;
      //std::cout << "<Variable id= \"";
      this->getExpression()->print_xml();
      //std::cout << "\"/>" << std::endl;
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      
      //this->getExpression()->codegen(_context);
      std::string name = this->getExpression()->ReturnName();


      // if the scope is -1, add to the global variable map
      std::map<std::string, GlobalRegisterAllocations*>::iterator findVar;

      if(_context.getScopeLevel() == -1){
        findVar = _context.globalBindings.find(name);

        if(findVar == _context.globalBindings.end()){
          // add to the map

          std::string memRef = _context.makeGlobalOffset(name);
          GlobalRegisterAllocations *tempGlobal = new GlobalRegisterAllocations("", "", memRef);
          _context.globalBindings.emplace(name, tempGlobal);
          //_context.addGlobalBinding(name, tempGlobal); <-- doesn't work

        }

      }



    }

    virtual std::string ReturnName() const override
    {
      //std::cout << "RETURN NAME IDENTIFIER DECLARATOR" << std::endl;
      return this->getExpression()->ReturnName();
    }

};

class BracketedDeclarator : public Declarator
{
private:
  const Declarator *local_declarator;

public:
  BracketedDeclarator(const Declarator *_local_declarator)
  : local_declarator(_local_declarator)
  {}

    const Declarator *getDeclarator() const{
      return local_declarator;
    }

    virtual void print_xml() const override
    {
      //std::cout << "Bracketed trace" << std::endl;
      this->getDeclarator()->print_xml();
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      this->getDeclarator()->codegen(_context);
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

    const Expression *getExpression() const{
      return declarator_identifier;
    }

    virtual void print_xml() const override
    {
      //std::cout << "ExpressionDeclarator trace" << std::endl;
      this->getExpression()->print_xml();
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      this->getExpression()->codegen(_context);
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
      std::cout << "\" />" << std::endl;
    }

    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      this->getLeft()->codegen(_context);
    }

    virtual std::string ReturnName() const override
    {
      //std::cout << "RETURN NAME DIRECT DEC EMPTY" << std::endl;
      return this->getLeft()->ReturnName();
    }

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
    std::cout << "\" />" << std::endl;
    //std::cout << "RIGHT PARAM DECLARATOR" << std::endl;

    this->getRight()->print_xml();

  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    this->getLeft()->codegen(_context);
    this->getRight()->codegen(_context);
  }

  virtual std::string ReturnName() const override
  {
    //std::cout << "RETURN NAME DIRECT DEC PARAMS" << std::endl;
    return this->getLeft()->ReturnName();
  }

};

#endif
