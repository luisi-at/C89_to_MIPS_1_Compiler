#ifndef ast_assignment_expression_hpp
#define ast_assignment_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class AssignmentExpression : public Expression
{
private:
  const Expression *left;
  const std::string assignment_operator;
  const Expression *right;
public:
  AssignmentExpression(const Expression *_left
    , std::string _assignment_operator
    , const Expression *_right)
    : left(_left)
    , assignment_operator(_assignment_operator)
    , right(_right)
  {}

  ~AssignmentExpression(){
    delete left;
    delete right;
  }

  const Expression *getLeft() const
  { return left; }

  const std::string getOperator() const
  { return assignment_operator; }

  const Expression *getRight() const
  { return right; }

  virtual void print_xml() const override
  {
    //std::cout << "ASSIGNMENT EXPRESSION" << std::endl;
    //this->getLeft()->print_xml();
    //this->getRight()->print_xml();
  }

  virtual Expression* *AddItem(const Expression *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    // the left unary expression gets sorted first
    std::cout << "ASSIGNMENT CODGEN" << std::endl;
    this->getLeft()->codegen(_context); // as a unary expression is always on the left of an assignment expression
    this->getRight()->codegen(_context);
    // search for variable name in context map
    std::string left = this->getLeft()->ReturnName();
    std::map<std::string, RegisterAllocations*>::iterator findVar;
    findVar = _context.bindings.find(left);

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
      if(!_context.checkAssignment.second){
      RegisterAllocations *tempAlloc = new RegisterAllocations("", _context.getAwaitingValue(), _context.getMemOffset());
      _context.updateMemOffset();
      _context.addBinding(left,tempAlloc);

      // don't bind a constant if variable on other side
      }
      else{
        std::cout << "MAKE BINDING" << std::endl;
        RegisterAllocations *tempAlloc = new RegisterAllocations("", "", _context.getMemOffset());

        _context.updateMemOffset();
        _context.bindings.emplace(left,tempAlloc);
      }
    }

    //==============================================
    // Need to constant fold unary expressions?
    // =============================================

    std::string right = this->getRight()->ReturnName();
    int currentVarMem;

    if(this->getOperator() == "="){
      // assign a constant
      //std::cout << "ASSIGNMENT CODGEN OPERATOR--> =" << std::endl;
      //std::cout << "CONST BOOL--> " << _context.checkAssignment.second << std::endl;
      //std::cout << "CONTEXT MEM OFFSET--> " << _context.getMemOffset() << std::endl;
      if(_context.checkAssignment.second){
        findVar = _context.bindings.find(left);
        //std::cout << "LEFT--> " << left << std::endl;
        std::string regUsed = _context.popRegister("rv");
        currentVarMem = findVar->second->getCurrentMemOffset();

        // write out
        //std::cout << "THIS STORED OFFSET--> " << currentVarMem << std::endl;
        //std::cout << "RIGHT--> " << right << std::endl;
        if(right == "0"){
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(3) << std::right << "$0" << "," << currentVarMem << "($fp)"  << std::endl;
        }
        else{
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << right << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << currentVarMem << "($fp)"  << std::endl;
        }
        _context.pushRegister(regUsed,"rv");
      }
      else{
        // assign a variable
        findVar = findVar = _context.bindings.find(left);
        int memOffsetLeft = findVar->second->getCurrentMemOffset();
        findVar = findVar = _context.bindings.find(right);
        int memOffsetRight = findVar->second->getCurrentMemOffset();

        std::string regUsed = _context.popRegister("rv");

        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsed << "," << memOffsetRight << "($fp)"  << std::endl;
        std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;

        _context.pushRegister(regUsed,"rv");
      }
    }

    else if(this->getOperator() == "+="){

    }
    else if(this->getOperator() == "-="){

    }
    else if(this->getOperator() == "*="){

    }
    else if(this->getOperator() == "/="){

    }
    else if(this->getOperator() == "|="){

    }
    else if(this->getOperator() == "&="){

    }
    else if(this->getOperator() == "%="){

    }
    else if(this->getOperator() == "^="){

    }
    else if(this->getOperator() == "<<="){

    }
    else if(this->getOperator() == ">>="){

    }

}


  virtual std::string ReturnName() const override
  {


  }

};

#endif
