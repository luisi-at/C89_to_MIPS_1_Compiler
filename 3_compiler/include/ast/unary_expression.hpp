#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

#include "expression.hpp"

#include <string.h>
#include <iostream>
#include <map>

class UnaryExpression : public Expression
{
private:
  const Expression *right;
protected:
  UnaryExpression(const Expression *_right)
    : right(_right)
{}
public:
  virtual ~UnaryExpression()
    {
        delete right;
    }

    virtual const char *getOperator() const =0;

    const Expression *getRight() const
    { return right; }

    virtual void print_xml() const override
    {
      //std::cout << "UNARY EXPRESSION" << std::endl;
      //fprintf(stderr, "Unary Expression Print\n");
      if(strcmp(this->getOperator(), "") == 0){
        //std::cout << "UNARY EXPRESSION IF1" << std::endl;
        this->getRight()->print_xml();
      }
      else{
        //std::cout << this->getOperator() << std::endl;
        //std::cout << "UNARY EXPRESSION IF2" << std::endl;
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
        std::string temp = this->getRight()->ReturnName();
        _context.addBinding(temp,tempAlloc);

        // get the top scratch register
        std::string regUsed = _context.popRegister("rv");
        int currentVarMem = tempAlloc->getCurrentMemOffset();

        // write out
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(3) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "addiu " << std::setw(4) << std::right << regUsed+","+regUsed+"," << "1"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(3) << std::right << regUsed+"," << currentVarMem << "($fp)" << std::endl;

        // return the scratch register to the stack
        _context.pushRegister(regUsed, "rv");

      }
      else if(getOperator() == "--"){
        //decrement

        // add the left item to the context
        std::string temp = this->getRight()->ReturnName();
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
    {
      this->getRight()->ReturnName();
    }

};


class UnaryIncExpression
  : public UnaryExpression
{
protected:
  virtual const char *getOperator() const override
  { return "++"; }

public:
  UnaryIncExpression(const Expression *_right)
  : UnaryExpression(_right)
  {}
};


class UnaryDecExpression
  : public UnaryExpression
{
protected:
  virtual const char *getOperator() const override
  { return "--"; }

public:
  UnaryDecExpression(const Expression *_right)
  : UnaryExpression(_right)
  {}
};


#endif
