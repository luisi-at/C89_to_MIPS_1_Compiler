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
private:
  const Declarator *specifiers;
  const Declarator *declarator;
  const Declarator *declaration_list;
  const Statement *compound_statement;

public:
  FunctionDefinition(const Declarator *_specifiers
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


    virtual void print_xml() const override
    {

        std::cout << "<Function id = \"\">" << std::endl;

        std::cout << "<Scope>" << std::endl;
        if((this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){
          std::cout << "FUNCTION_DEC1_1" << std::endl;
          this->getSpecifiers()->print_xml();
          std::cout << "FUNCTION_DEC1_2" << std::endl;
          this->getDeclarator()->print_xml();
          std::cout << "FUNCTION_DEC1_3" << std::endl;
          this->getDeclarationList()->print_xml();
          std::cout << "FUNCTION_DEC1_4" << std::endl;
          this->getStatement()->print_xml();

        }
        else if((this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){
          std::cout << "FUNCTION_DEC2_1" << std::endl;
          this->getSpecifiers()->print_xml();
          //std::cout << this->getSpecifiers() << std::endl;
          std::cout << "FUNCTION_DEC2_2" << std::endl;
          this->getDeclarator()->print_xml();
          std::cout << "FUNCTION_DEC2_3" << std::endl;
          this->getStatement()->print_xml();
        }
        else if((!this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){
          std::cout << "FUNCTION_DEC3_1" << std::endl;
          this->getDeclarator()->print_xml();
          std::cout << "FUNCTION_DEC3_2" << std::endl;
          this->getDeclarationList()->print_xml();
          std::cout << "FUNCTION_DEC3_3" << std::endl;
          this->getStatement()->print_xml();
        }
        else if((!this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){
          std::cout << "FUNCTION_DEC4_1" << std::endl;
          this->getDeclarator()->print_xml();
          std::cout << "FUNCTION_DEC4_2" << std::endl;
          this->getStatement()->print_xml();
        }

        std::cout << "</Scope>" << std::endl;

        std::cout << "</Function>" << std::endl;
    }
};


#endif
