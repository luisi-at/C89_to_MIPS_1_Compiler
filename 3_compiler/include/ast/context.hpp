#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <stack>
#include <map>
#include <utility>

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


};

class Context
{
private:
  std::vector<int> params;
  std::map<std::string, RegisterAllocations*> bindings;
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

public:
  Context()
  {
    functionMemOffset = 4;
    availableRegisters_rv.push("$2");
    availableRegisters_rv.push("$3");

    availableRegisters_fa.push("$4");
    availableRegisters_fa.push("$5");
    availableRegisters_fa.push("$6");
    availableRegisters_fa.push("$7");

    std::string tempReg;
    for(int i = 8; i < 16; i++){
      tempReg = "$" + i;
      availableRegisters_tp.push(tempReg.c_str());
    }
    availableRegisters_tp.push("$24");
    availableRegisters_tp.push("$25");

    for(int i = 16; i < 24; i++){
      tempReg = "$" + i;
      availableRegisters_st.push(tempReg.c_str());
    }

  }

  // add to the parameters
  int addParam(int _inparam){
    params.push_back(_inparam);
  }
  // add to the map
  void addBinding(std::string _variableName, RegisterAllocations *_allocated)
  {
    // make a pair
    std::pair<std::string, RegisterAllocations*> temp;
    temp = std::make_pair(_variableName, _allocated);
  }

  void getBindingDetails(std::string _variableName)
  {
    // get information regarding the variable from here
  }

  std::string makeLabel(std::string inName){
    //make a label
    return "_"+inName+"_"+std::to_string(labelCount++);
  }

  // remove a register in use
  // remove the register from the top of the list
  std::string popRegister(std::string _range)
  {
    if(_range == "rv"){
      return availableRegisters_rv.top();
      availableRegisters_rv.pop();
    }
    else if(_range == "fa"){
      return availableRegisters_fa.top();
      availableRegisters_fa.pop();
    }
    else if(_range == "tp"){
      return availableRegisters_tp.top();
      availableRegisters_tp.pop();
    }
    else if(_range == "st"){
      return availableRegisters_st.top();
      availableRegisters_st.pop();
    }
  }

  // return a register available for use
  // now return that register back to the top of the stack
  std::string pushRegister(std::string _reg, std::string _range)
  {

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

};

#endif
