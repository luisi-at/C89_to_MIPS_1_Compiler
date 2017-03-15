#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
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

    virtual FunctionDefinition* *AddItem(const FunctionDefinition *_item) const override
    {}

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


};


#endif
