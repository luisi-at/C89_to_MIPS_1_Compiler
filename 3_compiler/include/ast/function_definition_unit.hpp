#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

#include "unit.hpp"
#include "expression.hpp"
#include "statement.hpp"
#include "declarator.hpp"

class FunctionDefinition : public Unit
{
public:

  virtual void print_xml() const = 0;

  virtual FunctionDefinition* *AddItem(const FunctionDefinition *_item) const = 0;
};

class FunctionDefinitionActual : public FunctionDefinition
{
private:
  const Declarator *specifiers;
  const Declarator *declarator;
  const Declarator *declaration_list;
  const Statement *compound_statement;
  mutable std::string function_name;

public:
  FunctionDefinitionActual(const Declarator *_specifiers
  , const Declarator *_declarator
  , const Declarator *_declaration_list
  , const Statement *_compound_statement)
  : specifiers(_specifiers)
  , declarator(_declarator)
  , declaration_list(_declaration_list)
  , compound_statement(_compound_statement)
  {}

    const Declarator* getSpecifiers() const{
      return specifiers;
    }
    const Declarator* getDeclarator() const{
      return declarator;
    }
    const Declarator* getDeclarationList() const{
      return declaration_list;
    }
    const Statement* getStatement() const{
      return compound_statement;
    }
    const void setFunctionName(const std::string _thisName) const{
      function_name = _thisName;
    }
    std::string getFunctionName() const{
      return function_name;
    }

    virtual FunctionDefinition* *AddItem(const FunctionDefinition *_item) const override
    {}

    virtual void codegen(Context &_context) const override
    {
      std::string functionLabel;
      //std::cout << "CODEGEN FUNCTION DEF" << std::endl;
      // set function name/label here
      functionLabel = this->getDeclarator()->ReturnName();
      //this->setFunctionName(functionLabel);
      std::cout << "NAME--> " << functionLabel << std::endl;
      // is it from this declarator identifier?
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".align " << std::setw(10) << std::left << "2" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".globl " << std::setw(10) << std::left << "NAME" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "nomips16" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "nomicromips" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".ent " << std::setw(10) << std::left << "FUNCTION NAME" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".type " << std::setw(10) << std::left << "FUNCTION NAME, @function" << std::endl;
      // print function label here!

      if((this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".frame " << std::setw(10) << std::right << "$fp, NO!, $31" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".mask " << std::setw(10) << std::right << "MASK" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".fmask " << std::setw(10) << std::right << "FMASK" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::right << "noreorder" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::right << "nomacro" << std::endl;

      }
      else if((this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){

      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){

      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){

      }

    }

    virtual void print_xml() const override
    {

      if((this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){
        std::cout << "FUNCTION_DEC1_1" << std::endl;
        this->getSpecifiers()->print_xml();
        std::cout << "<Scope>" << std::endl;
        std::cout << "FUNCTION_DEC1_2" << std::endl;
        this->getDeclarator()->print_xml();
        std::cout << "FUNCTION_DEC1_3" << std::endl;
        this->getDeclarationList()->print_xml();
        std::cout << "FUNCTION_DEC1_4" << std::endl;
        this->getStatement()->print_xml();

      }
      else if((this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){
        std::cout << "FUNCTION_DEC2_1---> Specifiers" << std::endl;
        this->getSpecifiers()->print_xml();
        std::cout << "FUNCTION_DEC2_2---> Declarator" << std::endl;
        std::cout << "<Function id = \"";
        this->getDeclarator()->print_xml();
        //std::cout << " \"/>" << std::endl;
        std::cout << "<Scope>" << std::endl;
        std::cout << "FUNCTION_DEC2_3---> Statements" << std::endl;
        this->getStatement()->print_xml();
      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){
        std::cout << "FUNCTION_DEC3_1---> Declarator" << std::endl;
        this->getDeclarator()->print_xml();
        std::cout << "<Scope>" << std::endl;
        std::cout << "FUNCTION_DEC3_2---> Declaration List" << std::endl;
        this->getDeclarationList()->print_xml();
        std::cout << "FUNCTION_DEC3_3---> Statement" << std::endl;
        this->getStatement()->print_xml();
      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){
        std::cout << "FUNCTION_DEC4_1" << std::endl;
        this->getDeclarator()->print_xml();
        std::cout << "<Scope>" << std::endl;
        std::cout << "FUNCTION_DEC4_2" << std::endl;
        this->getStatement()->print_xml();
      }

      std::cout << "</Scope>" << std::endl;

      std::cout << "</Function>" << std::endl;
    }

    virtual std::string ReturnName() const override
    {}

};

class FunctionDefinitionList : public FunctionDefinition
{
private:
  mutable std::vector<const FunctionDefinition*> functions_list;
public:
  virtual FunctionDefinition* *AddItem(const FunctionDefinition *_item) const override
  {
    functions_list.push_back(_item);
  }

  virtual void print_xml() const override
  {
    for(int i = 0; i < functions_list.size(); i++){
      functions_list[i]->print_xml();
    }
  }

  virtual void codegen(Context &_context) const override
  {
    for(int i = 0; i < functions_list.size(); i++){
      functions_list[i]->codegen(_context);
    }
  }

  virtual std::string ReturnName() const override
  {}


};


#endif
