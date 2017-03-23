#ifndef ast_relational_expression_hpp
#define ast_relational_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class RelationalExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  RelationalExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
{}
public:
  virtual ~RelationalExpression()
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


    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
        return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      this->getRight()->codegen(_context); // as the right side is a unary expression and must be done first
      bool isRightConst = _context.checkAssignment.second;
      this->getLeft()->codegen(_context); // left side is a multiplicative expression
      bool isLeftConst = _context.checkAssignment.second;

      bool alwaysEvaluates; // used to hold constants after being folded, may need to type check (look for "")

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

      if(this->getOperator() == "<"){
        _context.opUsedInIf.first = "<";

        if((!isLeftConst) && (isRightConst)){
          _context.canIgnore.first = false;
          // load the left and load immediate right
          _context.opUsedInIf.second = false;
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);

          alwaysEvaluates = leftValue < rightValue;
          _context.canIgnore.first = true;
          _context.canIgnore.second = alwaysEvaluates;

        }

        else if((isLeftConst) && (!isRightConst)){
          _context.canIgnore.first = false;
          findVar = _context.bindings.find(right);
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          _context.opUsedInIf.second = true;

          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else{
          _context.canIgnore.first = false;
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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

      if(this->getOperator() == ">"){
        _context.opUsedInIf.first = ">";

        if((!isLeftConst) && (isRightConst)){
          _context.canIgnore.first = false;
          // load the left and load immediate right
          _context.opUsedInIf.second = false;
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);

          alwaysEvaluates = leftValue > rightValue;
          _context.canIgnore.first = true;
          _context.canIgnore.second = alwaysEvaluates;

        }

        else if((isLeftConst) && (!isRightConst)){
          _context.canIgnore.first = false;
          findVar = _context.bindings.find(right);
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          _context.opUsedInIf.second = true;

          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else{
          _context.canIgnore.first = false;
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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

      if(this->getOperator() == "<="){
        _context.opUsedInIf.first = "<=";

        if((!isLeftConst) && (isRightConst)){
          _context.canIgnore.first = false;
          // load the left and load immediate right
          _context.opUsedInIf.second = false;
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          int rightValue = std::stoi(right, nullptr, 0);
          rightValue++;
          right = std::to_string(rightValue);

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);

          alwaysEvaluates = leftValue <= rightValue;
          _context.canIgnore.first = true;
          _context.canIgnore.second = alwaysEvaluates;

        }

        else if((isLeftConst) && (!isRightConst)){
          _context.canIgnore.first = false;
          findVar = _context.bindings.find(right);
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          _context.opUsedInIf.second = true;

          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else{
          _context.canIgnore.first = false;
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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }


      }

      if(this->getOperator() == ">="){
        _context.opUsedInIf.first = ">=";

        if((!isLeftConst) && (isRightConst)){
          _context.canIgnore.first = false;
          // load the left and load immediate right
          _context.opUsedInIf.second = false;
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << right  << std::endl;

        }

        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
          int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
          int rightValue = std::stoi(right, nullptr, 0);

          alwaysEvaluates = leftValue >= rightValue;
          _context.canIgnore.first = true;
          _context.canIgnore.second = alwaysEvaluates;

        }

        else if((isLeftConst) && (!isRightConst)){
          _context.canIgnore.first = false;
          findVar = _context.bindings.find(right);
          std::string regUsedFirst = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();

          _context.opUsedInIf.second = true;

          int leftValue = std::stoi(left, nullptr, 0);
          leftValue++;
          left = std::to_string(leftValue);

          // load the word
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << "," << left  << std::endl;
          _context.pushRegister(regUsedFirst, "rv");
        }

        else{
          _context.canIgnore.first = false;
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
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "slt " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst << std::endl;

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

class StrictLessThanExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return "<"; }

public:
  StrictLessThanExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class StrictGreaterThanExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return ">"; }

public:
  StrictGreaterThanExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class LessEqualExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return "<="; }

public:
  LessEqualExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

class GreaterEqualExpression : public RelationalExpression
{
protected:
  virtual const char *getOperator() const override
  { return ">="; }

public:
  GreaterEqualExpression(const Expression *_left, const Expression *_right)
  : RelationalExpression(_left, _right)
  {}
};

#endif
