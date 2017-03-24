#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <stack>
#include <map>
#include <utility>
#include <iostream>

class RegisterAllocations{
private:
  std::string allocatedRegister;
  std::string value;
  int memOffset;
public:
  RegisterAllocations(std::string _reg, std::string _val, int _offset)
  : allocatedRegister(_reg)
  , value(_val)
  , memOffset(_offset)
  {}

  int getCurrentMemOffset()
  {
    return memOffset;
  }

  void setValue(std::string _value)
  {
    value = _value;
  }

  std::string getValue()
  {
    return value;
  }
};

class Context
{
private:
  std::vector<int> params;
  int labelCount;
  int allocatedRegisters;

  // need to have a stack of available registers so can push on and push off
  // initialize when create context object
  std::stack<std::string> availableRegisters_rv; // return values $2, $3
  std::stack<std::string> availableRegisters_fa; // function arguments $4-$7
  std::stack<std::string> availableRegisters_st; // saved temporaries $16-$23
  std::stack<std::string> availableRegisters_tp; // temporaries $8-$15 and $24-$25

  // every time a pop occurs, increase the reg count, even if returned to the stack?
  int functionMemOffset; // global memory offset for the function
  std::string valueAwaitingBinding; // used for assignments

public:
  Context()
  {
    functionMemOffset = 4;
    labelCount = 1;
    //std::cout << "FUNCTION OFFSET = 4" << std::endl;
    availableRegisters_rv.push("$3");
    availableRegisters_rv.push("$2");

    availableRegisters_fa.push("$5");
    availableRegisters_fa.push("$6");
    availableRegisters_fa.push("$7");
    availableRegisters_fa.push("$4");

    std::string tempReg;
    for(int i = 16; i > 7; i--){
      tempReg = "$" + i;
      availableRegisters_tp.push(tempReg.c_str());
    }
    availableRegisters_tp.push("$25");
    availableRegisters_tp.push("$24");


    for(int i = 24; i > 15; i--){
      tempReg = "$" + i;
      availableRegisters_st.push(tempReg.c_str());
    }

  }
  ~Context()
  {}

  std::map<std::string, RegisterAllocations*> bindings;
  // checking for constant assignment
  std::pair<std::string, bool> checkAssignment;
  std::string varInUse;
  bool multipleCodegen = false;
  bool operationInAssignment = false;
  // bool false for const right
  // bool true for const left
  std::pair<std::string, bool> opUsedInIf;
  std::pair<bool, bool> canIgnore;
  std::pair<std::string, bool> valueForSelection; // left contains either a register or a valueForSelection
  // true for register, false for constant

  // add to the parameters
  int addParam(int _inparam){
    params.push_back(_inparam);
  }
  // add to the map
  std::pair<std::string, RegisterAllocations*> addBinding(std::string _variableName, RegisterAllocations *_allocated)
  {
    // make a pair
    //std::pair<std::string, RegisterAllocations*> temp;
    //temp = std::make_pair(_variableName, _allocated);
    bindings.emplace(_variableName, _allocated);

  }

  void getBindingDetails(std::string _variableName)
  {
    // get information regarding the variable from here
  }


  std::string makeLabel(){
    //make a label
    return "$L"+std::to_string(labelCount++)+":";
  }

  // remove a register in use
  // remove the register from the top of the list
  std::string popRegister(std::string _range)
  {
    std::string returnReg;
    if(_range == "rv"){
      returnReg = availableRegisters_rv.top();
      availableRegisters_rv.pop();
    }
    else if(_range == "fa"){
      returnReg = availableRegisters_fa.top();
      availableRegisters_fa.pop();
    }
    else if(_range == "tp"){
      returnReg = availableRegisters_tp.top();
      availableRegisters_tp.pop();
    }
    else if(_range == "st"){
      returnReg = availableRegisters_st.top();
      availableRegisters_st.pop();
    }
    return returnReg;
  }

  // return a register available for use
  // now return that register back to the top of the stack
  void pushRegister(std::string _reg, std::string _range)
  {
    if(_range == "rv"){
      availableRegisters_rv.push(_reg);
    }
    else if(_range == "fa"){
      availableRegisters_fa.push(_reg);
    }
    else if(_range == "tp"){
      availableRegisters_tp.push(_reg);
    }
    else if(_range == "st"){
      availableRegisters_st.push(_reg);
    }
  }

  void setRegisterCount(int _allocatedRegisters)
  {
    allocatedRegisters = _allocatedRegisters;
  }

  int getRegisterCount()
  {
    return allocatedRegisters;
  }

  void updateMemOffset()
  {
    functionMemOffset += 4;
  }

  int getMemOffset()
  {
    return functionMemOffset;
  }

  // set to "#" when there is no value to assign
  void setAwaitingValue(std::string _await)
  {
    valueAwaitingBinding = _await;
  }

  std::string getAwaitingValue()
  {
    return valueAwaitingBinding;
  }

};

#endif
