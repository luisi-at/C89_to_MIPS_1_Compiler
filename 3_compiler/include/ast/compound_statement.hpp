#ifndef ast_compund_statement_hpp
#define ast_compund_statement_hpp

#include "statement.hpp"
#include "declarator.hpp"

class CompoundStatement : public Statement
{
private:
  const Statement *statement_part;
  const Declarator *declaration_part;

public:
CompoundStatement(const Statement *_statement_part, const Declarator *_declaration_part)
  : statement_part(_statement_part)
  , declaration_part(_declaration_part)
{}

const Statement *getStatement() const{
  return statement_part;
}

const Declarator *getDeclarator() const{
  return declaration_part;
}

  virtual void print_xml() const override
  {
    //std::cout << "COMPOUND STATEMENT" << std::endl;
    if(this->getDeclarator())
    {
      this->getDeclarator()->print_xml();
    }
    if(this->getStatement())
    {
      this->getStatement()->print_xml();
    }

  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    //this->getDeclarator()->codegen(_context);
    this->getStatement()->codegen(_context);
  }

  virtual std::string ReturnName() const override
  {

  }

  virtual int statementCount() const override
  {
    return this->getStatement()->statementCount();
  }


};

#endif
