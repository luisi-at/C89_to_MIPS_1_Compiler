#ifndef ast_init_declarator_hpp
#define ast_init_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class InitDeclarator : public Declarator
{
private:
  const Declarator *left;
  const Expression *right;

public:
  InitDeclarator(const Declarator *_left, const Expression *_right)
  : left(_left)
  , right(_right)
  {}

const Expression *getRight() const
{
  return right;
}

const Declarator *getLeft() const
{
  return left;
}

  virtual void print_xml() const override
  {
    //std::cout << "INIT DECLARATOR" << std::endl;
    this->getLeft()->print_xml();
    if(this->getRight()){
      this->getRight()->print_xml();
    }
  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    //std::cout << "INIT DEC CODEGEN" << std::endl;
    this->getLeft()->codegen(_context);
    //std::cout << this->getLeft()->ReturnName() << std::endl;
    this->getRight()->codegen(_context);
    //std::cout << this->getRight()->ReturnName() << std::endl;

    // search for variable name in context map
    std::string left = this->getLeft()->ReturnName();
    std::map<std::string, RegisterAllocations*>::iterator findVar;
    std::map<std::string, FunctionAttributes*>::iterator findFunc;
    std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobal;
    findVar = _context.bindings.find(left);
    findGlobal = _context.globalBindings.find(left);

    if((findGlobal != _context.globalBindings.end()) && (_context.getScopeLevel() == -1)){
      // init declarator binding only applies if the scope is negative
      //std::cout << "FOUND GLOBAL" << std::endl;
      //std::cout << _context.checkAssignment.second << std::endl;
      findVar->second->setValue(_context.getAwaitingValue());
      _context.hasGlobal = true;
    }
    else if((findGlobal == _context.globalBindings.end()) && (_context.getScopeLevel() == -1)){
      //std::cout << "GLOBAL HERE" << std::endl;
      int memRef = _context.getMemOffset();
      _context.updateMemOffset();
      GlobalRegisterAllocations *tempGlobal = new GlobalRegisterAllocations("", "", memRef);
      _context.globalBindings.emplace(left, tempGlobal);
      _context.hasGlobal = true;
    }

    if(findVar != _context.bindings.end()){
      // variable already exists in context
      // must also use allocated memory location given in context
      // update context and bind the variable if it is a constant
      findVar->second->setValue(_context.getAwaitingValue());
      // if not a constant, just add to the context

    }
    else{
      // make new value in context and bind
      // bind if constant on other side of assignment expression
      if((!_context.checkAssignment.second) && (!_context.assignFunction)){
      //std::cout << "BINDING CONSTANT--> " << _context.checkAssignment.second << std::endl;
      RegisterAllocations *tempAlloc = new RegisterAllocations("", _context.getAwaitingValue(), _context.getMemOffset());
      _context.updateMemOffset();
      _context.addBinding(left,tempAlloc);
      _context.varInUse = left;
      }
      // don't bind a constant if variable on other side
      else{
        //std::cout << "LEFT--> " << left << std::endl;
        //std::cout << "RIGHT--> " << right << std::endl;
        //std::cout << "CHECK ASSIGNMENT--> " << _context.checkAssignment.second << std::endl;
        RegisterAllocations *tempAlloc = new RegisterAllocations("", "", _context.getMemOffset());

        _context.updateMemOffset();
        _context.bindings.emplace(left,tempAlloc);
        _context.varInUse = left;
        _context.assignFunction = false;
      }
    }
    std::string right = this->getRight()->ReturnName();
    //std::cout << "RIGHT--> " << right << std::endl;
    int currentVarMem;

    // assign a constant
    //std::cout << "ASSIGNMENT CODGEN OPERATOR--> =" << std::endl;
    //std::cout << "CONST BOOL--> " << _context.checkAssignment.second << std::endl;
    //std::cout << "CONTEXT MEM OFFSET--> " << _context.getMemOffset() << std::endl;
    //std::cout << "SCOPE LEVEL" <<_context.getScopeLevel() << std::endl;
    if((_context.checkAssignment.second) && (_context.getScopeLevel() > -1)){
      findVar = _context.bindings.find(left);
      //std::cout << "SCOPE LEVEL > -1 " << left << std::endl;
      std::string regUsed = _context.popRegister("rv");
      currentVarMem = findVar->second->getCurrentMemOffset();

      // write out
      //std::cout << "THIS STORED OFFSET--> " << currentVarMem << std::endl;
      //std::cout << "RIGHT--> " << right << std::endl;
      if(right == "0"){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << "$0" << "," << currentVarMem << "($fp)"  << std::endl;
      }
      else if (!_context.operationInAssignment){
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << right << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
      }
      else{
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
      }
      _context.pushRegister(regUsed,"rv");
      _context.checkAssignment.second = false;
    }
    else if((_context.checkAssignment.second) && (_context.getScopeLevel() == -1)){
      // bind global variables
      //std::cout << "BIND GLOBAL" << std::endl;
      std::cout << left+":" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".word " << std::setw(1) << std::right << right << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".text " << std::setw(1) << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".align " << std::setw(1) << std::right << "2" << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".globl " << std::setw(1) << std::right << "main" << std::endl;

    }
    else if ((!_context.operationInAssignment) && (_context.getScopeLevel() > -1)){
      // assign a variable that is being assigned
      findVar = _context.bindings.find(left);
      //std::cout << "LEFT NAME--> " << left << std::endl;
      int memOffsetLeft = findVar->second->getCurrentMemOffset();
      //td::cout << "MEM OFFSET LEFT--> " << memOffsetLeft << std::endl;
      findVar = _context.bindings.find(right);
      if(findVar == _context.bindings.end()){
        std::string functionJumpLabel;
        //std::cout << "RIGHT--> " << right << std::endl;
        // =======================================================
        // FUNCTION ASSIGNMENTS
        // =======================================================
        // look for the function name in the functions
        // call codegen on this->getRight()
        // then assign via a an sw with memOffsetLeft
        findFunc = _context.func_attributes.find(right);
        if(findFunc != _context.func_attributes.end()){
          functionJumpLabel = findFunc->second->getFunctionLabel();
          //this->getRight()->codegen(_context); <-- don't need to do this again

          //std::cout << "POP REGISTER "<< std::endl;
          std::string regUsed = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;
          _context.pushRegister(regUsed,"rv");
          _context.checkAssignment.second = false;
        }
      }


      else{
        right = _context.varInUse;
        //std::cout << "RIGHT NAME--> " << right << std::endl;
        findVar = _context.bindings.find(right);
        int memOffsetRight = findVar->second->getCurrentMemOffset();


        std::string regUsed = _context.popRegister("rv");

        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsed << "," << memOffsetRight << "($fp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;

        _context.pushRegister(regUsed,"rv");
      }

    }
    else if(_context.getScopeLevel() > -1){
      findVar = _context.bindings.find(left);
      //std::cout << "LEFT NAME--> " << left << std::endl;
      int memOffsetLeft = findVar->second->getCurrentMemOffset();
      std::string regUsed = _context.popRegister("rv");
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;
      _context.pushRegister(regUsed,"rv");
      _context.operationInAssignment = false;
    }

  }

  virtual std::string ReturnName() const override
  {
    return "";
  }

};




#endif
