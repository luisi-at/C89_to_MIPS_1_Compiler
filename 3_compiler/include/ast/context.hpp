#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>
#include <vector>

struct RegisterAllocations{
  std::string variableName;
  std::string allocatedRegister;
  int value;
};

class Context
{
private:
  std::vector<int> params;
  std::map<std::string, RegisterAllocations*> bindings;
  int labelCount;
  int allocatedRegisters; // use this to set the frame space allocated on the stack
  // need something to store register allocations? VERY LIKELY
  // calculate the number of registers as add registers? Increment by 4 each time
  // need to have a stack of available registers so can push on and push off
  std::vector<std::string> availableRegisters;
  // every time a pop occurs, increase the reg count, even if returned to the stack

public:
  Context()
  {
    // initialize available registers using availableRegisters
  }

  // add to the parameters
  int addParam(int _inparam){
    params.push_back(_inparam);
  }
  // add to the map
  int addBinding(std::string _variableName, RegisterAllocations *_allocated)
  {
    // make a pair
    std::pair<std::string, RegisterAllocations*> temp;
    temp = std::make_pair(_variableName, _allocated);
  }

  std::string makeLabel(std::string inName){
    //make a label
    return "_"+inName+"_"+std::to_string(labelCount++);
  }

  // return a register available for use
  std::string pushRegister(std::string _reg){

  }

  // remove a register in use
  std::string popRegister(std::string _reg){

  }

};

#endif
