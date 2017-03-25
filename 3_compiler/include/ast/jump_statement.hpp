#ifndef ast_jump_statement_hpp
#define ast_jump_statement_hpp

#include "statement.hpp"

class GotoStatement : public Statement
{
private:
  const Expression *jump_identifier;
public:
  GotoStatement(const Expression *_jump_to)
  : jump_identifier(_jump_to)
  {}

    const Expression *getJump() const
    { return jump_identifier; }

    virtual void print_xml() const override
    {
      //std::cout << "GOTO" << std::endl;
      this->getJump()->print_xml();
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
      return 1;
    }

};

class ContinueStatement : public Statement
{
private:
  const Expression *continue_point;
public:
  ContinueStatement(const Expression *_jump_to)
  : continue_point(_jump_to)
  {}

  const Expression *getJump() const
  { return continue_point; }

  virtual void print_xml() const override
  {
    //std::cout << "CONTINUE" << std::endl;
    this->getJump()->print_xml();
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
      return 1;
    }

};

class BreakStatement : public Statement
{
private:
  const Expression *break_point;
public:
  BreakStatement(const Expression *_jump_to)
  : break_point(_jump_to)
  {}

  const Expression *getJump() const
  { return break_point; }

  virtual void print_xml() const override
  {
    //std::cout << "BREAK" << std::endl;
    this->getJump()->print_xml();
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
    return 1;
  }

};

class ReturnStatement : public Statement
{
protected:
  const Expression *return_point;
public:
  ReturnStatement(const Expression *_jump_to)
  : return_point(_jump_to)
  {}

  const Expression *getJump() const
  { return return_point; }

  virtual void print_xml() const override
  {
    //std::cout << "RETURN EMPTY" << std::endl;
    this->getJump()->print_xml();
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
    return 1;
  }

};

class ReturnExprStatement : public Statement
{
private:
  const Expression *return_expression;
public:
  ReturnExprStatement(const Expression *_jump_to)
  : return_expression(_jump_to)
  {}

  const Expression *getJump() const
  { return return_expression; }


  virtual void print_xml() const override
  {
    //std::cout << "RETURN VALUE COMING" << std::endl;
    //this->getJump()->print_xml();
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    std::string returnReg;
    bool isJumpConst = _context.checkAssignment.second;
    std::string isExpression = _context.checkAssignment.first;
    std::map<std::string, RegisterAllocations*>::iterator findVar;
    std::string value;

    if(isJumpConst){
      value = this->getJump()->ReturnName();
      if(value == "0"){
        value = "$0";
      }
      returnReg = _context.popRegister("rv");
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "move " << std::setw(4) << std::right << returnReg << "," << value << std::endl;
      _context.pushRegister(returnReg,"rv");
    }
    else if(isExpression != "#"){
      // do the rest of the trickery here
      findVar = _context.bindings.find(value);
      int currentVarMem = findVar->second->getCurrentMemOffset();
      returnReg = _context.popRegister("rv");
      std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "lw " << std::setw(4) << std::right << returnReg << "," << currentVarMem << "($fp)"  << std::endl;
      _context.pushRegister(returnReg,"rv");
    }
    else{
      this->getJump()->codegen(_context);
    }


  }

  virtual std::string ReturnName() const override
  {
    // dealing only with constants currently
  }

  virtual int statementCount() const override
  {
    return 1;
  }

};


#endif
