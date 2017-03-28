if((!globalExistsLeft) && (!globalExistsRight)){

  // check if a constant on the right
  // check if a constant on the right
  if((!isLeftConst) && (isRightConst)){
    // load the left and load immediate right
    findVar = _context.bindings.find(left);
    //std::cout << "LEFT--> " << left << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    currentVarMem = findVar->second->getCurrentMemOffset();

    // load the word
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedFirst << "," << regUsedFirst << right  << std::endl;
    _context.pushRegister(regUsedFirst, "rv");

  }
  // check if both constants
  else if((isLeftConst) && (isRightConst)){
    // constant fold and load immediate value
    int leftValue = std::stoi(left, nullptr, 0); // automatically converts ints and hex etc...
    int rightValue = std::stoi(right, nullptr, 0);
    std::string regUsed = _context.popRegister("rv");

    inLineConstFold = leftValue << rightValue;

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsed << "," << inLineConstFold << std::endl;
    _context.pushRegister(regUsed, "rv");

  }
  else if((isLeftConst) && (!isRightConst)){
    std::string regUsedFirst = _context.popRegister("rv");
    currentVarMem = findVar->second->getCurrentMemOffset();
    // load the word
    std::string regUsedSecond = _context.popRegister("rv");
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst  << std::endl;
    _context.pushRegister(regUsedSecond, "rv");

    _context.pushRegister(regUsedFirst, "rv");
  }
  // both variables
  else{
    // load value from left register
    // load value from right register
    findVar = _context.bindings.find(left);
    //std::cout << "LEFT--> " << left << std::endl;
    //std::cout << "RIGHT--> " << right << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    std::string regUsedSecond = _context.popRegister("rv");
    findVar = _context.bindings.find(left);
    int memOffsetLeft = findVar->second->getCurrentMemOffset();
    findVar = _context.bindings.find(right);
    int memOffsetRight = findVar->second->getCurrentMemOffset();

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << memOffsetLeft << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << memOffsetRight << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << regUsedFirst  << std::endl;

    _context.pushRegister(regUsedSecond, "rv");
    _context.pushRegister(regUsedFirst, "rv");

  }
}
else if((globalExistsLeft) && (!globalExistsRight)){
  if((!isLeftConst) && (isRightConst)){

    //findVar = _context.bindings.find(left);
    //std::cout << "LEFT--> " << left << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    //currentVarMem = findVar->second->getCurrentMemOffset();
    globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
    std::string regUsedSecond = _context.popRegister("rv");
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedSecond << "," << regUsedFirst << "," << right << std::endl;

    _context.pushRegister(regUsedSecond, "rv");
    _context.pushRegister(regUsedFirst, "rv");
  }

  else if((!isLeftConst) && (!isRightConst)){

    findVar = _context.bindings.find(right);
    //std::cout << "LEFT--> " << left << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    currentVarMem = findVar->second->getCurrentMemOffset();
    globalVarMemLeft = findGlobal->second->getCurrentMemOffset();

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
    std::string regUsedSecond = _context.popRegister("rv");
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedSecond << "," << regUsedSecond << "," << regUsedFirst << std::endl;

    _context.pushRegister(regUsedSecond, "rv");
    _context.pushRegister(regUsedFirst, "rv");
  }

}
else if((!globalExistsLeft) && (globalExistsRight)){
  if((isLeftConst) && (!isRightConst)){

    //findVar = _context.bindings.find(left);
    //std::cout << "LEFT--> " << left << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    //currentVarMem = findVar->second->getCurrentMemOffset();
    globalVarMemRight = findGlobal->second->getCurrentMemOffset();

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
    std::string regUsedSecond = _context.popRegister("rv");
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "li " << std::setw(4) << std::right << regUsedSecond << "," << left  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedSecond << "," << regUsedSecond << "," << regUsedFirst  << std::endl;

    _context.pushRegister(regUsedSecond, "rv");
    _context.pushRegister(regUsedFirst, "rv");
  }

  else if((!isLeftConst) && (!isRightConst)){

    findVar = _context.bindings.find(left);
    //std::cout << "LEFT--> " << left << std::endl;
    std::string regUsedFirst = _context.popRegister("rv");
    currentVarMem = findVar->second->getCurrentMemOffset();
    globalVarMemRight = findGlobal->second->getCurrentMemOffset();

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
    std::string regUsedSecond = _context.popRegister("rv");
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << currentVarMem << "($fp)"  << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedSecond << "," << regUsedSecond << "," << regUsedFirst << std::endl;

    _context.pushRegister(regUsedSecond, "rv");
    _context.pushRegister(regUsedFirst, "rv");
  }
}
else if((globalExistsLeft) && (globalExistsRight)){

  findGlobal = _context.globalBindings.find(left);
  globalVarMemLeft = findGlobal->second->getCurrentMemOffset();
  std::map<std::string, GlobalRegisterAllocations*>::iterator findGlobalRight;
  findGlobalRight = _context.globalBindings.find(right);
  globalVarMemRight = findGlobalRight->second->getCurrentMemOffset();

  std::string regUsedFirst = _context.popRegister("rv");
  std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
  std::string regUsedSecond = _context.popRegister("rv");
  std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedSecond << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

  _context.pushRegister(regUsedFirst, "rv");

  regUsedFirst = _context.popRegister("rv");
  std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lui " << std::setw(4) << std::right << regUsedFirst << "," << "%hi"+globalVarMemLeft << std::endl;
  std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << regUsedFirst << "," << "%lo"+globalVarMemLeft+"("+regUsedFirst+")" << std::endl;

  std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "sll " << std::setw(4) << std::right << regUsedSecond << "," << regUsedSecond << "," << regUsedFirst << std::endl;

  _context.pushRegister(regUsedSecond, "rv");
  _context.pushRegister(regUsedFirst, "rv");

}
