#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include "statement.hpp"
#include "expression_statement.hpp"

class WhileIteration : public Statement
{
private:
  const Expression *first_expression;
  const Statement *next_statement;
public:
  WhileIteration(const Expression *_first, const Statement *_next)
    : first_expression(_first)
    , next_statement(_next)
    {}

      const Expression *getFirst() const
      { return first_expression; }

      const Statement *getNext() const
      { return next_statement; }

  virtual void print_xml() const override
  {
    //std::cout << "ITERATION STATEMENT" << std::endl;
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
    std::string bottomContinueLabel = _context.makeLabel();
    std::string topLoopLabel = _context.makeLabel();


    //_context.currentLabel = label;
    std::cout << topLoopLabel << std::endl;
    this->getFirst()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    // get next
    this->getNext()->codegen(_context);
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "b " << std::setw(4) << std::right << topLoopLabel << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
    std::cout << std::endl;
    std::cout << bottomContinueLabel << std::endl;

    _context.checkAssignment.first = "#";

  }


  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    // 1 register for the expression in case
    return 1+this->getNext()->statementCount();
  }

};

class DoWhileIteration : public Statement
{
private:
  const Statement *first_statement;
  const Expression *loop_expression;
public:
  DoWhileIteration(const Statement *_first, const Expression *_loop)
    : first_statement(_first)
    , loop_expression(_loop)
    {}

      const Statement *getFirst() const
      { return first_statement; }

      const Expression *getLoop() const
      { return loop_expression; }

  virtual void print_xml() const override
  {
    std::cout << "<Scope>" << std::endl;
    this->getLoop()->print_xml();
    std::cout << "</Scope>" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    std::string bottomContinueLabel = _context.makeLabel();
    std::string topLoopLabel = _context.makeLabel();

    std::cout << topLoopLabel << std::endl;
    // get the statement inside the loop
    this->getFirst()->codegen(_context);

    // get loop condition
    this->getLoop()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "b " << std::setw(4) << std::right << topLoopLabel << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
    std::cout << std::endl;
    std::cout << bottomContinueLabel << std::endl;

    _context.checkAssignment.first = "#";

  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return 1+this->getFirst()->statementCount();
  }

};

class ForNoExprIteration : public Statement
{
private:
  const Statement *first_statement;
  const Statement *second_statement;
  const Statement *third_statement;
public:
  ForNoExprIteration(const Statement *_first
    , const Statement *_second
    , const Statement *_third)
    : first_statement(_first)
    , second_statement(_second)
    , third_statement(_third)
    {}

  const Statement *getFirst() const
  { return first_statement; }

  const Statement *getSecond() const
  { return second_statement; }

  const Statement *getThird() const
  { return third_statement; }


  virtual void print_xml() const override
  {
    std::cout << "<Scope>" << std::endl;
    this->getThird()->print_xml();
    std::cout << "</Scope>" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    std::string bottomContinueLabel = _context.makeLabel();
    std::string topLoopLabel = _context.makeLabel();

    this->getFirst()->codegen(_context);
    std::cout << topLoopLabel << std::endl;
    this->getSecond()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    this->getThird()->codegen(_context);

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "b " << std::setw(4) << std::right << topLoopLabel << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
    std::cout << std::endl;
    std::cout << bottomContinueLabel << std::endl;


  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return 2+this->getThird()->statementCount();
  }

};

class ForExprIteration : public Statement
{
private:
  const Statement *first_statement;
  const Statement *second_statement;
  const Statement *third_statement;
  const Expression *loop_expression;
public:
  ForExprIteration(const Statement *_first
    , const Statement *_second
    , const Statement *_third
    , const Expression *_loop)
    : first_statement(_first)
    , second_statement(_second)
    , third_statement(_third)
    , loop_expression(_loop)
    {}

  const Statement *getFirst() const
  { return first_statement; }

  const Statement *getSecond() const
  { return second_statement; }

  const Statement *getThird() const
  { return third_statement; }

  const Expression *getLoopExpr() const
  { return loop_expression; }

  virtual void print_xml() const override
  {
    std::cout << "<Scope>" << std::endl;
    this->getThird()->print_xml();
    std::cout << "</Scope>" << std::endl;
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    std::string bottomContinueLabel = _context.makeLabel();
    std::string topLoopLabel = _context.makeLabel();

    this->getFirst()->codegen(_context);
    std::cout << topLoopLabel << std::endl;
    this->getSecond()->codegen(_context);
    if(_context.opUsedInIf.first == "=="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    if(_context.opUsedInIf.first == "!="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");
      std::string regUsedSecond = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedSecond, "rv");
      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">"){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == "<="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }
    else if(_context.opUsedInIf.first == ">="){
      std::string compValueOrReg = _context.valueForSelection.first;
      std::string regUsedFirst = _context.popRegister("rv");

      // make label
      //label = _context.makeLabel();

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << bottomContinueLabel << std::endl;

      _context.pushRegister(regUsedFirst, "rv");

    }

    if((_context.opUsedInIf.first != "&&") && (_context.opUsedInIf.first != "||")){

      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
      std::cout << std::endl;
    }

    this->getThird()->codegen(_context);
    this->getLoopExpr()->codegen(_context);
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "b " << std::setw(4) << std::right << topLoopLabel << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
    std::cout << std::endl;
    std::cout << bottomContinueLabel << std::endl;
  }

  virtual std::string ReturnName() const override
  {}

  virtual int statementCount() const override
  {
    return 3+this->getThird()->statementCount();
  }

};


#endif
