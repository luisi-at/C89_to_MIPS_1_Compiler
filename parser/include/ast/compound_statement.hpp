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

  virtual void print_xml() const override
  {
    //printy xml
  }

  virtual Statement* *AddItem(const Statement *_item) const override
  {
    return 0;
  }

};

#endif
