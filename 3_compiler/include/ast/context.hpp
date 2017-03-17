#ifndef ast_context_hpp
#define ast_context_hpp

#include <string>

class Context
{
private:
  std::vector<int> params;
  std::map<std::string, int> bindings;
  int labelCount;

public:
  // add to the parameters
  // add to the map
  std::string makeLabel(std::string inName){
    //make a label
    return "_"+inName+"_"+std::to_string(labelCount++);
  }

};

#endif
