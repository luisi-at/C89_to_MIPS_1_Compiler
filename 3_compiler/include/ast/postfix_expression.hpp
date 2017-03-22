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

    RegisterAllocations *tempAlloc = new RegisterAllocations("", "", _context.getMemOffset());
    _context.updateMemOffset();

    if(getOperator() == "++"){
      //increment
      // add the left item to the context
      std::string temp = this->getLeft()->ReturnName();
      _context.addBinding(temp,tempAlloc);

      // get the top scratch register
      std::string regUsed = _context.popRegister("rv");
      int currentVarMem = tempAlloc->getCurrentMemOffset();

      // write out
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << regUsed+","+regUsed+"," << "1"  << std::endl;
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed+"," << currentVarMem << "($fp)" << std::endl;

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
    else {

    }

  }

  virtual std::string ReturnName() const override
  {}

};

class PostfixEmpty
  : public PostfixExpression
{
protected:
  virtual const char *getOperator() const override
  { return ""; }

public:
  PostfixEmpty(const Expression *_left, const Expression *_right)
    :PostfixExpression(_left, _right)
  {}

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


#endif
