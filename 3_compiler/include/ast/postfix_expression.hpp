#ifndef ast_postfix_expression_hpp
#define ast_postfix_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class PostfixExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  PostfixExpression(const Expression *_left, const Expression *_right)
  : left(_left)
  , right(_right)
{}
public:
  virtual ~PostfixExpression()
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
      //std::cout << "left" << std::endl;
      //std::cout << "POSTFIX EXPRESSION" << std::endl;
      this->getLeft()->print_xml();
      std::cout << getOperator();
      if(this->getRight()){
        this->getRight()->print_xml();
      }
    }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    _context.operationInAssignment = true;
    RegisterAllocations *tempAlloc = new RegisterAllocations("", "", _context.getMemOffset());
    _context.updateMemOffset();

    if(getOperator() == "++"){

      int currentVarMem;
      // increment
      // add the left item to the context
      std::string temp = this->getLeft()->ReturnName();
      // check to see if left item exists:
      std::pair<std::map<std::string, RegisterAllocations*>::iterator, bool> tryAdd = _context.bindings.emplace(temp, tempAlloc);
      if(tryAdd.second)
      {
        // binding exists previously, use that memory location
        currentVarMem = tryAdd.first->second->getCurrentMemOffset();
      }
      else{
        currentVarMem = tryAdd.first->second->getCurrentMemOffset();
        _context.addBinding(temp, tempAlloc);
      }

      // get the top scratch register
      std::string regUsed = _context.popRegister("rv");
      //std::cout << "MULTIPLE RECURSION " << _context.multipleCodegen << std::endl;
      //std::cout << "VAR IN USE--> " << _context.varInUse << std::endl;

      // write out
      if(_context.multipleCodegen){
        std::string assignReg = _context.popRegister("rv");
        //std::cout << "ASSIGN REG--> " << assignReg << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(3) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << assignReg+","+regUsed+"," << "1"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << assignReg+"," << currentVarMem << "($fp)" << std::endl;
        _context.pushRegister(assignReg, "rv");
      }
      else{
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(3) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << regUsed+","+regUsed+"," << "1"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed+"," << currentVarMem << "($fp)" << std::endl;
      }


      // return the scratch register to the stack

      _context.pushRegister(regUsed, "rv");


    }
    else if(getOperator() == "--"){
      //decrement

      // add the left item to the context
      std::string temp = this->getLeft()->ReturnName();
      _context.addBinding(temp,tempAlloc);

      // get the top scratch register
      std::string regUsed = _context.popRegister("rv");
      int currentVarMem = tempAlloc->getCurrentMemOffset();

      // write out
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << regUsed+","+regUsed+"," << "-1"  << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed+"," << currentVarMem << "($fp)" << std::endl;

      // return the scratch register to the stack
      _context.pushRegister(regUsed, "rv");

    }

    _context.checkAssignment.first = "#";
    _context.checkAssignment.second = false;

  }

  virtual std::string ReturnName() const override
  {
    return this->getLeft()->ReturnName();
  }

};



class PostfixPeriod
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "."; }

public:
  PostfixPeriod(const Expression *_left, const Expression *_right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixPtrOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "->"; }

public:
  PostfixPtrOp(const Expression *_left, const Expression *_right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixIncOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "++"; }

public:
  PostfixIncOp(const Expression *_left, const Expression *_right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixDecOp
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return "--"; }

public:
  PostfixDecOp(const Expression *_left, const Expression *_right)
  :PostfixExpression(_left, _right)
  {}

};

class PostfixEmpty: public Expression
{
private:
  const Expression *left;

public:
  PostfixEmpty(const Expression *_left)
    : left (_left)
  {}

  virtual ~PostfixEmpty()
  {
      delete left;
  }

  const Expression *getLeft() const
  { return left; }

  virtual void print_xml() const override
  {}

  virtual std::string ReturnName() const override
  {

    return this->getLeft()->ReturnName();
  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    // look up left in the function table
    // print out a jump then a no op and then the assignment
    if(_context.checkAssignment.second){
      _context.assignFunction = true;
      std::string funcName = this->getLeft()->ReturnName();
      std::string picOne = _context.getPic();
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << picOne << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "jal " << std::setw(4) << std::right << funcName << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::endl;
      std::cout << std::endl;
      //std::cout << "DONE POSTFIX EMPTY "<< std::endl;
      std::string picTwo = _context.getPic();
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << picTwo << std::endl;
    }
    else{
      std::cout << "#VOID FUNCTION!" << std::endl;
      std::string funcName = this->getLeft()->ReturnName();
      std::string picOne = _context.getPic();
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << picOne << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "jal " << std::setw(4) << std::right << funcName << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::endl;
      std::cout << std::endl;
      //std::cout << "DONE POSTFIX EMPTY "<< std::endl;
      std::string picTwo = _context.getPic();
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << picTwo << std::endl;
    }


  }

};


#endif
