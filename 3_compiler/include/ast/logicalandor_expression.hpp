#ifndef ast_logicalandor_expression_hpp
#define ast_logicalandor_expression_hpp

#include "expression.hpp"

#include <string>
#include <iostream>
#include <map>

class LogicalAndOrExpression : public Expression
{
private:
  const Expression *left;
  const Expression *right;
protected:
  LogicalAndOrExpression(const Expression *_left, const Expression *_right)
    : left(_left)
    , right(_right)
    {}
public:
  virtual ~LogicalAndOrExpression()
    {}

    virtual const char *getOperator() const =0;

    const Expression *getLeft() const
    { return left; }

    const Expression *getRight() const
    { return right; }

    virtual void print_xml() const override
    {
      //std::cout << "LOGICAL AND OR" << std::endl;
      this->getLeft()->print_xml();
      this->getRight()->print_xml();

    }

    virtual Expression* *AddItem(const Expression *_item) const override
    {
      return 0;
    }

    virtual void codegen(Context &_context) const override
    {
      std::string label = _context.currentLabel;
      if(this->getOperator() == "&&"){
        //_context.opUsedInIf.first = "&&";
        // essentially just carries out what is in the brackets that number of times
        // leave the if statement or the loop to deal with the labelling and the nops
        // both branch commands are dependent opposite to what is in the sub expression

        //if(this->getLeft()){
        //std::cout << _context.opUsedInIf.first << std::endl;

        this->getLeft()->codegen(_context);

        //std::cout << _context.opUsedInIf.first << std::endl;

        if(_context.opUsedInIf.first == "=="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        if(_context.opUsedInIf.first == "!="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }

        this->getRight()->codegen(_context);

        if(_context.opUsedInIf.first == "=="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        if(_context.opUsedInIf.first == "!="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        _context.opUsedInIf.first = "&&";
      }
      else if(this->getOperator() == "||"){
        // both branch commands are opposite to what corresponds to the sub expression

        this->getLeft()->codegen(_context);
        if(_context.opUsedInIf.first == "=="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");



          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        if(_context.opUsedInIf.first == "!="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");



          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");



          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");



          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }

        this->getRight()->codegen(_context);

        if(_context.opUsedInIf.first == "=="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        if(_context.opUsedInIf.first == "!="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");
          std::string regUsedSecond = _context.popRegister("rv");



          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << regUsedSecond << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedSecond, "rv");
          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">"){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == "<="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "beq " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        else if(_context.opUsedInIf.first == ">="){
          std::string compValueOrReg = _context.valueForSelection.first;
          std::string regUsedFirst = _context.popRegister("rv");


          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "bne " << std::setw(4) << std::right << regUsedFirst << "," << "$0" << "," << label << std::endl;
          std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << "nop " << std::setw(4) << std::right << std::endl;
          std::cout << std::endl;

          _context.pushRegister(regUsedFirst, "rv");

        }
        _context.opUsedInIf.first = "||";
      }


    }

    virtual std::string ReturnName() const override
    {
      return this->getLeft()->ReturnName();
    }

};

class LogicalAndExpression : public LogicalAndOrExpression
{
protected:
  virtual const char *getOperator() const override
  { return "&&"; }

public:
  LogicalAndExpression(const Expression *_left, const Expression *_right)
  : LogicalAndOrExpression(_left, _right)
  {}

};

class LogicalOrExpression : public LogicalAndOrExpression
{
protected:
  virtual const char *getOperator() const override
  { return "||"; }

public:
  LogicalOrExpression(const Expression *_left, const Expression *_right)
  : LogicalAndOrExpression(_left, _right)
  {}


};


#endif
