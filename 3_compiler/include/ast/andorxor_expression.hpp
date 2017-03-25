#ifndef ast_andorxor_expression_hpp
#define ast_andorxor_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class AndOrXorExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  AndOrXorExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~AndOrXorExpression()
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
      //std::cout << "LOGICAL EXPRESSION" << std::endl;
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


      std::map<std::string, RegisterAllocations*>::iterator findVar;
      std::string left = this->getLeft()->ReturnName();
      std::string right = this->getRight()->ReturnName();
      int currentVarMem;

      if(!isLeftConst){
        // check if the left side exists in the context:

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
        findVar = _context.bindings.find(right);
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

      if(this->getOperator() == "&"){

        if((!isLeftConst) && (isRightConst)){

          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "andi " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);
          std::string regUsed = _context.popRegister("rv");

          inLineConstFold = leftValue & rightValue;

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
          _context.pushRegister(regUsed, "rv");

        }

        else if((isLeftConst) && (!isRightConst)){
          std::string regUsedFirst = _context.popRegister("rv");
          findVar = _context.bindings.find(right);
          currentVarMem = findVar->second->getCurrentMemOffset();


          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "andi " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "and " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;


          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

      if(this->getOperator() == "|"){

        if((!isLeftConst) && (isRightConst)){

          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "ori " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);
          std::string regUsed = _context.popRegister("rv");

          inLineConstFold = leftValue | rightValue;

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
          _context.pushRegister(regUsed, "rv");

        }

        else if((isLeftConst) && (!isRightConst)){
          std::string regUsedFirst = _context.popRegister("rv");
          findVar = _context.bindings.find(right);
          currentVarMem = findVar->second->getCurrentMemOffset();


          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "ori " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "or " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;


          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

      if(this->getOperator() == "^"){

        if((!isLeftConst) && (isRightConst)){

          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "xori " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);
          std::string regUsed = _context.popRegister("rv");

          inLineConstFold = leftValue ^ rightValue;

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
          _context.pushRegister(regUsed, "rv");

        }

        else if((isLeftConst) && (!isRightConst)){
          std::string regUsedFirst = _context.popRegister("rv");
          findVar = _context.bindings.find(right);
          currentVarMem = findVar->second->getCurrentMemOffset();


          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "xori " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left << std::endl;

          _context.pushRegister(regUsedFirst, "rv");
        }

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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "xor " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;


          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

    }

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
    }

};

class AndExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "&"; }

public:
  AndExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

class XorExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "^"; }

public:
  XorExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

class OrExpression : public AndOrXorExpression
{
protected:
  virtual const char *getOperator() const override
  { return "|"; }

public:
  OrExpression(const Expression *_left, const Expression *_right)
  : AndOrXorExpression(_left, _right)
  {}
};

#endif
