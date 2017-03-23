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

      this->getRight()->codegen(_context); // as the right side is a unary expression and must be done first
      bool isRightConst = _context.checkAssignment.second;
      this->getLeft()->codegen(_context); // left side is a multiplicative expression
      bool isLeftConst = _context.checkAssignment.second;

      int inLineConstFold; // used to hold constants after being folded, may need to type check (look for "")

      std::map<std::string, RegisterAllocations*>::iterator findVar;
      std::string left = this->getLeft()->ReturnName();
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
      else{

      }

      if(this->getOperator() == "*"){

        // check if a constant on the right
        if((!isLeftConst) && (isRightConst)){
          // load the left and load immediate right
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsed = _context.popRegister("rv");
          currentVarMem = findVar->second->getCurrentMemOffset();
        }
        // check if both constants
        else if((isLeftConst) && (isRightConst)){
          // constant fold and load immediate value
        }
        // both variables
        else{
          // load value from left register
          // load value from right register
        }

      }
      else if(this->getOperator() == "/"){

      }
      else if(this->getOperator() == "%"){

      }
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
