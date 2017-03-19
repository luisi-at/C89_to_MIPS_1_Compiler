#ifndef ast_labeled_statement_hpp
#define ast_labeled_statement_hpp

#include "statement.hpp"

class LabeledStatement : public Statement
{
private:
  const Expression *left;
  const Statement *right;
protected:
  LabeledStatement(const Statement *_right)
    : right(_right)
    {}
  LabeledStatement(const Expression *_left, const Statement *_right)
    : left(_left)
    , right(_right)
    {}
public:
  virtual ~LabeledStatement()
    {
        delete left;
        delete right;
    }

    const Expression *getLeft() const
    { return left; }

    const Statement *getRight() const
    { return right; }

    virtual void print_xml() const = 0;

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
      return 1+this->getRight()->statementCount();
    }

};

class IdentifierStatement : public LabeledStatement
{
public:
  IdentifierStatement(const Expression *_left, const Statement *_right)
  : LabeledStatement(_left, _right)
  {}

  virtual void print_xml() const override
  {
    //std::cout << "IDENTIFIER STATEMENT" << std::endl;
    this->getLeft()->print_xml();
    //std::cout << ":" << std::endl;
    this->getRight()->print_xml();
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

};

class CaseStatement : public LabeledStatement
{
public:
  CaseStatement(const Expression *_left, const Statement *_right)
  : LabeledStatement(_left, _right)
  {}

  virtual void print_xml() const override
  {
    //std::cout << "CASE STATEMENT" << std::endl;
    //std::cout << "CASE/SCOPE" << std::endl;
    this->getLeft()->print_xml();
    //std::cout << ":" << std::endl;
    this->getRight()->print_xml();
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

};

class DefaultStatement : public LabeledStatement
{
public:
  DefaultStatement(const Statement *_right)
  : LabeledStatement(_right)
  {}

    virtual ~DefaultStatement()
    { delete this->getRight(); } // memory leak here?!

    virtual void print_xml() const override
    {
      //std::cout << "DEFAULT" << std::endl;
      //std::cout << "DEFAULT/SCOPE" << std::endl;
      this->getRight()->print_xml();
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

};

#endif
