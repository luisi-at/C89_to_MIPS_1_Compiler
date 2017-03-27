#ifndef ast_multiplicative_expression_hpp
#define ast_multiplicative_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class MultiplicativeExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  MultiplicativeExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~MultiplicativeExpression()
    {
        delete left;
        delete right;
    }

    virtual const char *getOperator() const =0;

    const Expression *getLeft() const
    { return left; }

    const Expression *getRight() const
    { return right; }

    virtual void print_xml() const override
    {
      //std::cout << "MULTIPLICATIVE EXPRESSION" << std::endl;
      this->getLeft()->print_xml();
      this->getRight()->print_xml();

    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {

      _context.operationInAssignment = true;

      this->getRight()->codegen(_context); // as the right side is a unary expression and must be done first
      bool isRightConst = _context.checkAssignment.second;
      this->getLeft()->codegen(_context); // left side is a multiplicative expression
      bool isLeftConst = _context.checkAssignment.second;

      int inLineConstFold; // used to hold constants after being folded, may need to type check (look for "")

      bool globalExistsLeft = false;
      bool globalExistsRight = false;
      bool localExistsLeft = false;
      bool localExistsRight = false;

      std::map<std::string, RegisterAllocations*>::iterator findVar;
      std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobal;

      std::string left = this->getLeft()->ReturnName();
      std::string right = this->getRight()->ReturnName();

      int currentVarMem;
      std::string globalVarMemLeft;
      std::string globalVarMemRight;

      if((!isLeftConst) && (isRightConst)){
        // check if the left side exists in the context:
        findGlobal = _context.globalBindings.find(left);
        if(findGlobal != _context.globalBindings.end()){
          globalVarMemLeft = findGlobal->second->getCurrentMemOffset();
          globalExistsLeft = true;
        }

        findVar = _context.bindings.find(left);
        if(findVar != _context.bindings.end()){
          // get memory location
           currentVarMem = findVar->second->getCurrentMemOffset();
        }
        else{
          // variable does not exist, implement somewhat undefined behaviour
          RegisterAllocations *tempAlloc = new RegisterAllocations("", "0xDEADBEEF", _context.getMemOffset());

          _context.updateMemOffset();
          _context.bindings.emplace(left,tempAlloc);
          _context.varInUse = left; // need this?
        }
      }

      else if((isLeftConst) && (!isRightConst)){
        // check if the left side exists in the context:
        findGlobal = _context.globalBindings.find(right);
        if(findGlobal != _context.globalBindings.end()){
          globalVarMemRight = findGlobal->second->getCurrentMemOffset();
          globalExistsRight = true;
        }

        findVar = _context.bindings.find(right);
        if(findVar != _context.bindings.end()){
          // get memory location
           currentVarMem = findVar->second->getCurrentMemOffset();
        }
        else{
          // local nor variable does not exist, implement somewhat undefined behaviour
          RegisterAllocations *tempAlloc = new RegisterAllocations("", "0xDEADBEEF", _context.getMemOffset());

          _context.updateMemOffset();
          _context.bindings.emplace(left,tempAlloc);
          _context.varInUse = left; // need this?
        }

      }
      else if((!isLeftConst) && (!isRightConst)){
        findGlobal = _context.globalBindings.find(right);
        if(findGlobal != _context.globalBindings.end()){
          globalVarMemRight = findGlobal->second->getCurrentMemOffset();
          globalExistsRight = true;
        }
        findGlobal = _context.globalBindings.find(left);
        if(findGlobal != _context.globalBindings.end()){
          globalVarMemLeft = findGlobal->second->getCurrentMemOffset();
          globalExistsLeft = true;
        }

      }


      if(this->getOperator() == "*"){

        if((!globalExistsLeft) && (!globalExistsRight)){

          // check if a constant on the right
          if((!isLeftConst) && (isRightConst)){
            // load the left and load immediate right
            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();

            // load the word
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << right  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");

          }
          // check if both constants
          else if((isLeftConst) && (isRightConst)){
            // constant fold and load immediate value
            int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
            int rightValue = std::stoi(right, nullptr, 0);
            std::string regUsed = _context.popRegister("rv");

            inLineConstFold = leftValue * rightValue;

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
            _context.pushRegister(regUsed, "rv");

          }
          else if((isLeftConst) && (!isRightConst)){
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            // load the word
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedSecond << "," << regUsedFirst  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }
          // both variables
          else{
            // load value from left register
            // load value from right register
            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            //std::cout << "RIGHT--> " << right << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            std::string regUsedSecond = _context.popRegister("rv");
            findVar = _context.bindings.find(left);
            int memOffsetLeft = findVar->second->getCurrentMemOffset();
            findVar = _context.bindings.find(right);
            int memOffsetRight = findVar->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << memOffsetLeft << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << memOffsetRight << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");

          }
        }
        else if((globalExistsLeft) && (!globalExistsRight)){
          if((!isLeftConst) && (isRightConst)){

            //findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            //currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << right  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }

          else if((!isLeftConst) && (!isRightConst)){

            findVar = _context.bindings.find(right);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");
          }

        }
        else if((!globalExistsLeft) && (globalExistsRight)){
          if((isLeftConst) && (!isRightConst)){

            //findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            //currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemRight = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }

          else if((!isLeftConst) && (!isRightConst)){

            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemRight = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");
          }
        }
        else if((globalExistsLeft) && (globalExistsRight)){

          findGlobal = _context.globalBindings.find(left);
          globalVarMemLeft = findGlobal->second->getCurrentMemOffset();
          std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobalRight;
          findGlobalRight = _context.globalBindings.find(right);
          globalVarMemRight = findGlobalRight->second->getCurrentMemOffset();

          std::string regUsedFirst = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
          std::string regUsedSecond = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

          regUsedFirst = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mult " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }
      else if(this->getOperator() == "/"){
        if((!globalExistsLeft) && (!globalExistsRight)){

          // check if a constant on the right
          if((!isLeftConst) && (isRightConst)){
            // load the left and load immediate right
            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();

            // load the word
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << right  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");

          }
          // check if both constants
          else if((isLeftConst) && (isRightConst)){
            // constant fold and load immediate value
            int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
            int rightValue = std::stoi(right, nullptr, 0);
            std::string regUsed = _context.popRegister("rv");

            inLineConstFold = leftValue / rightValue;

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
            _context.pushRegister(regUsed, "rv");

          }
          else if((isLeftConst) && (!isRightConst)){
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            // load the word
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedSecond << "," << regUsedFirst  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }
          // both variables
          else{
            // load value from left register
            // load value from right register
            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            //std::cout << "RIGHT--> " << right << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            std::string regUsedSecond = _context.popRegister("rv");
            findVar = _context.bindings.find(left);
            int memOffsetLeft = findVar->second->getCurrentMemOffset();
            findVar = _context.bindings.find(right);
            int memOffsetRight = findVar->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << memOffsetLeft << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << memOffsetRight << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");

          }
        }
        else if((globalExistsLeft) && (!globalExistsRight)){
          if((!isLeftConst) && (isRightConst)){

            //findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            //currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << right  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }

          else if((!isLeftConst) && (!isRightConst)){

            findVar = _context.bindings.find(right);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");
          }

        }
        else if((!globalExistsLeft) && (globalExistsRight)){
          if((isLeftConst) && (!isRightConst)){

            //findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            //currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemRight = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            _context.pushRegister(regUsedSecond, "rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            _context.pushRegister(regUsedFirst, "rv");
          }

          else if((!isLeftConst) && (!isRightConst)){

            findVar = _context.bindings.find(left);
            //std::cout << "LEFT--> " << left << std::endl;
            std::string regUsedFirst = _context.popRegister("rv");
            currentVarMem = findVar->second->getCurrentMemOffset();
            globalVarMemRight = findGlobal->second->getCurrentMemOffset();

            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
            std::string regUsedSecond = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

            _context.pushRegister(regUsedSecond, "rv");
            _context.pushRegister(regUsedFirst, "rv");
          }
        }
        else if((globalExistsLeft) && (globalExistsRight)){

          findGlobal = _context.globalBindings.find(left);
          globalVarMemLeft = findGlobal->second->getCurrentMemOffset();
          std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobalRight;
          findGlobalRight = _context.globalBindings.find(right);
          globalVarMemRight = findGlobalRight->second->getCurrentMemOffset();

          std::string regUsedFirst = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
          std::string regUsedSecond = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

          regUsedFirst = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "div " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "mflo " << std::setw(4) << std::right << regUsedFirst  << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }

      }

      _context.checkAssignment.first = "#";
  }

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
    }

};

class MultiplyMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "*"; }

public:
  MultiplyMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};

class DivideMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "/"; }

public:
  DivideMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};

class ModMultiplicative : public MultiplicativeExpression
{
protected:
  virtual const char *getOperator() const override
  { return "%"; }

public:
  ModMultiplicative(const Expression *_left, const Expression *_right)
  : MultiplicativeExpression(_left, _right)
  {}

};

#endif
