#ifndef ast_main_declaration_declarator_hpp
#define ast_main_declaration_declarator_hpp

#include <string>
#include <iostream>
#include <vector>

#include "declarator.hpp"

class MainDeclaration : public Declarator
{
private:
  const Declarator *specifiers;
  const Declarator *init_list;

public:
  MainDeclaration(const Declarator *_specifiers, const Declarator *_init_list)
  : specifiers(_specifiers)
  , init_list(_init_list)
  {}

    const Declarator *getSpecifiers() const {
      return specifiers;
    }

    const Declarator *getInitList() const {
      return init_list;
    }

  virtual void print_xml() const override
  {
    this->getSpecifiers()->print_xml();
    this->getInitList()->print_xml();
  }

  virtual Declarator* *AddItem(const Declarator *_item) const override
  {
      return 0;
  }

  virtual void codegen(Context &_context) const override
  {
    std::cout << "MAIN DEC" << std::endl;
    this->getSpecifiers()->codegen(_context);
    this->getInitList()->codegen(_context);
  }

  virtual std::string ReturnName() const override
  {
    this->getSpecifiers()->ReturnName();
  }

};

class DeclarationList : public Declarator
{
private:
    mutable std::vector<const Declarator*> declarations_list;
public:
  DeclarationList()
  {
    //std::cout << "DECLARATION LIST" << std::endl;
  }
    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
      //std::cout << "ADD DECLARATION ITEM INSIDE" << std::endl;
      //std::cout << "==============" << std::endl;

      //std::cout << "==============" << std::endl;
      //std::cout << _item << std::endl;
      declarations_list.push_back(_item); // fails here
      //std::cout << "AFTER PUSH BACK" << std::endl;
      //this->print_xml();
    }

    virtual void print_xml() const override
    {
        // statement printy
        //std::cout << "TRY PRINT LIST DECLARATOR" << std::endl;
        /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
         (*iter)->print_xml();
         */
        //std::cout << "DECLARATION LIST SIZE: "<< declarations_list.size() << std::endl;
        for(int i = 0; i < declarations_list.size(); i++){
          //std::cout << "PRINTING DECLARATION LIST: " << i << std::endl;
          std::cout << "<Variable id= \"";
          declarations_list[i]->print_xml();
          std::cout << "\" />" << std::endl;
        }
        //std::cout << "DONE PRINTING DECLARATORS" << std::endl;
    }

    virtual void codegen(Context &_context) const override
    {
      for(int i = 0; i < declarations_list.size(); i++){
        //std::cout << "PRINTING DECLARATION LIST: " << i << std::endl;
        declarations_list[i]->codegen(_context);
      }
    }

    virtual std::string ReturnName() const override
    {}

};

class ParamDeclarationList : public Declarator
{
private:
    mutable std::vector<const Declarator*> param_declarations_list;
public:
  ParamDeclarationList()
  {
    //std::cout << "DECLARATION LIST" << std::endl;
  }
    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
    //std::cout << "ADD DECLARATION ITEM INSIDE" << std::endl;
    //std::cout << "==============" << std::endl;

    //std::cout << "==============" << std::endl;
    //std::cout << _item << std::endl;
      param_declarations_list.push_back(_item); // fails here
    //std::cout << "AFTER PUSH BACK" << std::endl;
    //this->print_xml();
    }

    virtual void print_xml() const override
    {
        // statement printy
        //std::cout << "TRY PRINT LIST DECLARATOR" << std::endl;
        /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
         (*iter)->print_xml();
         */
        //std::cout << "DECLARATION LIST SIZE: "<< declarations_list.size() << std::endl;
        for(int i = 0; i < param_declarations_list.size(); i++){
          //std::cout << "PRINTING DECLARATION LIST: " << i << std::endl;
          std::cout << "<Parameter id= \"";
          param_declarations_list[i]->print_xml();
          std::cout << "\" />" << std::endl;
        }
        //std::cout << "DONE PRINTING DECLARATORS" << std::endl;
    }

    virtual void codegen(Context &_context) const override
    {
      for(int i = 0; i < param_declarations_list.size(); i++){

        param_declarations_list[i]->codegen(_context);
      }
    }

    virtual std::string ReturnName() const override
    {}

};

class InitDeclarationList : public Declarator
{
private:
    mutable std::vector<const Declarator*> init_declarations_list;
public:
  InitDeclarationList()
  {
    //std::cout << "DECLARATION LIST" << std::endl;
  }
    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        //std::cout << "ADD DECLARATION ITEM INSIDE" << std::endl;
      //std::cout << "==============" << std::endl;

      //std::cout << "==============" << std::endl;
      //std::cout << _item << std::endl;
      init_declarations_list.push_back(_item); // fails here
      //std::cout << "AFTER PUSH BACK" << std::endl;
      //this->print_xml();
      }

      virtual void print_xml() const override
      {
          // statement printy
          //std::cout << "TRY PRINT LIST DECLARATOR" << std::endl;
          /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
           (*iter)->print_xml();
           */
          //std::cout << "DECLARATION LIST SIZE: "<< declarations_list.size() << std::endl;
          for(int i = 0; i < init_declarations_list.size(); i++){
            //std::cout << "PRINTING DECLARATION LIST: " << i << std::endl;

            init_declarations_list[i]->print_xml();

          }
          //std::cout << "DONE PRINTING DECLARATORS" << std::endl;
      }

      virtual void codegen(Context &_context) const override
      {
        for(int i = 0; i < init_declarations_list.size(); i++){
          init_declarations_list[i]->codegen(_context);
        }
      }

      virtual std::string ReturnName() const override
      {}

};


#endif
