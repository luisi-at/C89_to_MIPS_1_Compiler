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
    _context.multipleCodegen = true;

    //std::cout << "ASSIGNMENT CODGEN" << std::endl;
    this->getLeft()->codegen(_context); // as a unary expression is always on the left of an assignment expression
    this->getRight()->codegen(_context);
    //std::cout << "ASSIGNMENT CODGEN" << std::endl;
    // search for variable name in context map
    std::string left = this->getLeft()->ReturnName();
    std::map<std::string, RegisterAllocations*>::iterator findVar;
    std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobal;
    std::map<std::string, FunctionAttributes*>::iterator findFunc;

    //bool isGlobalOrLocal = false; // false is local, true is global;
    bool globalExists = false; // this means that local variables have precidence in the subroutine
    bool localExists = false;

    // look for global first;
    findGlobal = _context.globalBindings.find(left);
    if(findGlobal != _context.globalBindings.end()){
      //isGlobalOrLocal = true;
      globalExists = true;
    }
    findVar = _context.bindings.find(left);
    if(findVar != _context.bindings.end()){
      // variable already exists in context
      // must also use allocated memory location given in context
      // update context and bind the variable if it is a constant
      findVar->second->setValue(_context.getAwaitingValue());
      //isGlobalOrLocal = false;
      localExists = true;
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

      //isGlobalOrLocal = false;
      localExists = true;
      }
      // don't bind a constant if variable on other side
      else if(!globalExists){
        //std::cout << "LEFT--> " << left << std::endl;
        //std::cout << "RIGHT--> " << right << std::endl;
        //std::cout << "CHECK ASSIGNMENT--> " << _context.checkAssignment.second << std::endl;
        RegisterAllocations *tempAlloc = new RegisterAllocations("", "", _context.getMemOffset());

        _context.updateMemOffset();
        _context.bindings.emplace(left,tempAlloc);
        _context.varInUse = left;
        _context.assignFunction = false;

        //isGlobalOrLocal = false;
        localExists = true;
      }

    }

    std::string right = this->getRight()->ReturnName();
    //std::cout << "RIGHT--> " << right << std::endl;
    int currentVarMem;

    if((localExists) && (globalExists)){
      globalExists = false; // gives precedence to local variables
    }

    if(this->getOperator() == "="){
      // assign a constant
      //std::cout << "ASSIGNMENT CODGEN OPERATOR--> =" << std::endl;
      //std::cout << "CONST BOOL--> " << _context.checkAssignment.second << std::endl;
      //std::cout << "CONTEXT MEM OFFSET--> " << _context.getMemOffset() << std::endl;
      if(localExists){
        if(_context.checkAssignment.second){
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
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
        else if (!_context.operationInAssignment){
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
        else{
          findVar = _context.bindings.find(left);
          //std::cout << "LEFT NAME--> " << left << std::endl;
          int memOffsetLeft = findVar->second->getCurrentMemOffset();
          std::string regUsed = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;
          _context.pushRegister(regUsed,"rv");
          _context.operationInAssignment = false;
        }
      }

      else if(globalExists){
        if(_context.checkAssignment.second){
          findGlobal = _context.globalBindings.find(left);
          //std::cout << "LEFT--> " << left << std::endl;
          std::string regUsed = _context.popRegister("rv");
          std::string currentGlobalMem = findGlobal->second->getCurrentMemOffset();

          // write out
          //std::cout << "THIS STORED OFFSET--> " << currentVarMem << std::endl;
          //std::cout << "RIGHT--> " << right << std::endl;
          if(right == "0"){
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsed << "," << "%hi"+currentGlobalMem << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << "$0" << "," << "%lo"+currentGlobalMem+"("+regUsed+")" << std::endl;
          }
          else if (!_context.operationInAssignment){
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsed << "," << "%hi"+currentGlobalMem << std::endl;
            std::string secondRegUsed = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << secondRegUsed << "," << right << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << secondRegUsed << "," << "%lo"+currentGlobalMem+"("+regUsed+")"  << std::endl;
            _context.pushRegister(secondRegUsed,"rv");
          }
          else{
            //std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << "%lo"+currentGlobalMem+"("+regUsed+")"  << std::endl;
          }
          _context.pushRegister(regUsed,"rv");
          _context.checkAssignment.second = false;
        }
        else if (!_context.operationInAssignment){
          // assign a variable that is being assigned
          findGlobal = _context.globalBindings.find(left);
          //std::cout << "LEFT NAME--> " << left << std::endl;
          std::string memOffsetLeft = findGlobal->second->getCurrentMemOffset();
          //td::cout << "MEM OFFSET LEFT--> " << memOffsetLeft << std::endl;
          //================================================================
          // ASSIGN FUNCTION TO GLOBAL
          //================================================================
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
              std::string currentGlobalMem = findGlobal->second->getCurrentMemOffset();

              //std::cout << "POP REGISTER "<< std::endl;
              std::string regUsed = _context.popRegister("rv");
              std::string secondRegUsed = _context.popRegister("rv");
              std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "move " << std::setw(4) << std::right << secondRegUsed << "," << regUsed << std::endl;
              std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsed << "," << "%hi"+currentGlobalMem << std::endl;
              std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << secondRegUsed << "," << "%lo"+currentGlobalMem+"("+regUsed+")"  << std::endl;
              _context.pushRegister(regUsed,"rv");
              _context.pushRegister(secondRegUsed,"rv");
              _context.checkAssignment.second = false;
            }
          }
          //================================================================
          // ASSIGN LOCAL TO GLOBAL
          //================================================================
          else{
            right = _context.varInUse;
            //std::cout << "RIGHT NAME--> " << right << std::endl;
            findVar = _context.bindings.find(right);
            int memOffsetRight = findVar->second->getCurrentMemOffset();
            std::string currentGlobalMem = findGlobal->second->getCurrentMemOffset();

            std::string regUsed = _context.popRegister("rv");
            std::string secondRegUsed = _context.popRegister("rv");
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsed << "," << "%hi"+currentGlobalMem << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << secondRegUsed << "," << memOffsetRight << "($fp)"  << std::endl;
            std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << secondRegUsed << "," << "%lo"+currentGlobalMem+"("+regUsed+")"  << std::endl;
            _context.pushRegister(regUsed,"rv");
            _context.pushRegister(secondRegUsed,"rv");
          }

        }
        else{
          findGlobal = _context.globalBindings.find(left);
          //std::cout << "LEFT NAME--> " << left << std::endl;
          std::string memOffsetLeft = findGlobal->second->getCurrentMemOffset();
          std::string regUsed = _context.popRegister("rv");
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sw " << std::setw(4) << std::right << regUsed << "," << memOffsetLeft << "($fp)"  << std::endl;
          _context.pushRegister(regUsed,"rv");
          _context.operationInAssignment = false;
        }
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
