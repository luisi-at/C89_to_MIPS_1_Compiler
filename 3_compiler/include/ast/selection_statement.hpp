#ifndef ast_selection_statement_hpp
#define ast_selection_statement_hpp

#include "statement.hpp"

class IfSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  IfSelection(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }

  virtual void print_xml() const override
  {
    //std::cout << "IF STATEMENT" << std::endl;
    std::cout << "<Scope>" << std::endl;
    this->getNext()->print_xml();
    std::cout << "</Scope>" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {

    _context.increaseScopeLevel();

    // any new variables declared here need to be removed from the map
    // due to scoping constraints
    std::string label = _context.makeLabel();
    /*if(_context.nestedIf.second){
      // use the label stored in first
      std::cout << "NESTED IF! " << std::endl;
      label = _context.nestedIf.first;
    }
    else{
      std::cout << "NOT NESTED IF! " << std::endl;
      label = _context.makeLabel();
    }*/
    _context.currentLabel = label;
    this->getFirst()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    //_context.nestedIf.first = label;
    //_context.nestedIf.second = true;
    this->getNext()->codegen(_context);
    //if(!_context.nestedIf.second){
    std::cout << label << ":" << std::endl;
    //}

    _context.decreaseScopeLevel();

  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return this->getNext()->statementCount();
  }

};

class IfElseSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
  const Statement *else_statement;
public:
  IfElseSelection(const Expression *_first, const Statement *_next, const Statement *_else)
    : first_expression(_first)
    , next_statement(_next)
    , else_statement(_else)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }

      const Statement *getElse() const
      { return else_statement; }


  virtual void print_xml() const override
  {
    //std::cout << "IF ELSE STATEMENT" << std::endl;
    std::cout << "<Scope>" << std::endl;
    this->getNext()->print_xml();
    std::cout << "</Scope>" << std::endl;
    std::cout << "<Scope>" << std::endl;
    this->getElse()->print_xml();
    std::cout << "</Scope>" << std::endl;

  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {

    _context.increaseScopeLevel();

    // any new variables declared here need to be removed from the map
    // due to scoping constraints

    std::string label = _context.makeLabel();
    std::string elseLabel = _context.makeLabel();

    _context.currentLabel = elseLabel;
    this->getFirst()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    //std::cout << _context.opUsedInIf.first;
    //label = _context.makeLabel();
    _context.nestedIf.first = label;
    _context.nestedIf.second = true;
    this->getNext()->codegen(_context);
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "b " << std::setw(6) << std::right << elseLabel << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
    std::cout << std::endl;
    std::cout << label << ":" << std::endl;
    this->getElse()->codegen(_context);
    std::cout << elseLabel << ":" << std::endl;

    _context.decreaseScopeLevel();

  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return this->getNext()->statementCount() + this->getElse()->statementCount();
  }

};

class SwitchSelection : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  SwitchSelection(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }



  virtual void print_xml() const override
  {
    //std::cout << "SWITCH STATEMENT" << std::endl;
    std::cout << "<Scope>" << std::endl;
    this->getNext()->print_xml();
    std::cout << "</Scope>" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {

  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return 1+this->getNext()->statementCount();
  }

};


#endif
