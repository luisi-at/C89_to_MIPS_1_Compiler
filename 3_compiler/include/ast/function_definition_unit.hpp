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
  mutable int allocated_stack;

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
    const void setAllocatedStack(const int _counted) const{
      allocated_stack = _counted;
    }
    int getAllocatedStack() const{
      return allocated_stack;
    }

    virtual FunctionDefinition* *AddItem(const FunctionDefinition *_item) const override
    {}

    virtual void codegen(Context &_context) const override
    {
      std::string functionLabel;
      std::string functionProgramLabel;
      int stackAllocation = 0;
      int topNextFunc = 0;
      _context.resetScopeLevel();
      //std::cout << "CODEGEN FUNCTION DEF" << std::endl;
      // set function name/label here
      functionLabel = this->getDeclarator()->ReturnName();
      this->setFunctionName(functionLabel);
      functionProgramLabel = _context.makeFunctionLabel();
      if(functionLabel != "main"){
        _context.notJustMain = true;
        stackAllocation = stackAllocation + 8;
      }
      if(functionLabel == "main"){
        stackAllocation = stackAllocation - 4;
      }

      // get the current offset
      stackAllocation = stackAllocation + _context.getFrameOffset();
      topNextFunc = stackAllocation;
      stackAllocation = stackAllocation + (4* this->getStatement()->statementCount());
      _context.setFrameOffset(stackAllocation);

      /*if((_context.notJustMain) && (functionLabel == "main")){
        stackAllocation = (stackAllocation * 2);
      }*/
      this->setAllocatedStack(stackAllocation);

      // add function label to map in context detailing functions
      FunctionAttributes* tempFuncAtt = new FunctionAttributes(functionProgramLabel);
      _context.func_attributes.emplace(functionLabel, tempFuncAtt);


      _context.setRegisterCount(stackAllocation);
      std::cout << functionProgramLabel+"= ." << std::endl;
      if(!_context.hasGlobal){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".align " << std::setw(10) << std::left << "2" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".globl " << std::setw(10) << std::left << functionLabel << std::endl;
      }
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "nomips16" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "nomicromips" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".ent " << std::setw(10) << std::left << functionLabel << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".type " << std::setw(10) << std::left << functionLabel + ", " << "@function" << std::endl;


      std::cout << functionLabel << ":" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".frame " << std::setw(4) << std::right << "$fp," << stackAllocation << ",$31" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".mask " << std::setw(4) << std::right << "0x40000000,-4" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".fmask " << std::setw(5) << std::right << "0x00000000,0" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(5) << std::right << "noreorder" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(5) << std::right << "nomacro" << std::endl;

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << "$sp,$sp,-" << stackAllocation  << std::endl;
      if(_context.notJustMain){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(3) << std::right << "$31," << stackAllocation - 4 << "($sp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(3) << std::right << "$fp," << stackAllocation - 8 << "($sp)"  << std::endl;
      }
      else{
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(3) << std::right << "$fp," << stackAllocation - 4 << "($sp)"  << std::endl;
      }
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "move " << std::setw(3) << std::right << "$fp,"<< "$sp"  << std::endl;
      if((_context.hasGlobal) && (functionLabel != "main")){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(3) << std::right << "$28,%hi(__gnu_local_gp)" << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(3) << std::right << "$28," << "$28,%lo(__gnu_local_gp)"  << std::endl;
      }
      else if((_context.hasGlobal) && functionLabel == "main")){

      }



      std::cout << "#====== ASSEMBLY COMING ======" << std::endl;

      if((this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){

      }
      else if((this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){


        this->getStatement()->codegen(_context);


      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (this->getDeclarationList()) && (this->getStatement())){

      }
      else if((!this->getSpecifiers()) && (this->getDeclarator()) && (!this->getDeclarationList()) && (this->getStatement())){

      }

      if(_context.innerScopeReturn.first){
        std::cout << _context.innerScopeReturn.second << ":" << std::endl;
      }
      std::cout << "#====== ASSEMBLY ENDING ======" << std::endl;

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "move " << std::setw(4) << std::left << "$sp,$fp" << std::endl;
      if(_context.notJustMain){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(3) << std::right << "$31," << stackAllocation - 4 << "($sp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(3) << std::right << "$fp," << stackAllocation - 8 << "($sp)"  << std::endl;
      }
      else{
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::left << "$fp," << stackAllocation - 4 << "($sp)" << std::endl;
      }
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::left << "$sp,$sp," << stackAllocation << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "j " << std::setw(4) << std::left << "$31" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::endl;


      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "macro" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".set " << std::setw(10) << std::left << "reorder" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".end " << std::setw(10) << std::left << functionLabel << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".size " << std::setw(10) << std::left << functionLabel + "," + " " ".-" + functionLabel << std::endl;

      _context.setMemOffset(topNextFunc - 4);

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
