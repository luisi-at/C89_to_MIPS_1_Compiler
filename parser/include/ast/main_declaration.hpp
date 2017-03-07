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

};

class DeclarationList : public Declarator
{
private:
    mutable std::vector<const Declarator*> declarations_list;
public:
  DeclarationList()
  {std::cout << "DECLARATION LIST" << std::endl;}
    virtual Declarator* *AddItem(const Declarator *_item) const override
    {
        std::cout << "ADD ITEM INSIDE" << std::endl;
        std::cout << "==============" << std::endl;

        std::cout << "==============" << std::endl;
        std::cout << _item << std::endl;
        declarations_list.push_back(_item); // fails here
        std::cout << "AFTER PUSH BACK" << std::endl;
        this->print_xml();
        }

        virtual void print_xml() const override
        {
            // statement printy
            std::cout << "TRY PRINT LIST" << std::endl;
            /*for(std::vector<const Statement*>::iterator iter = statements_list.begin(); iter != statements_list.end(); ++iter){
             (*iter)->print_xml();
             */
            std::cout << declarations_list.size() << std::endl;
            for(int i = 0; i < declarations_list.size(); i++){
                declarations_list[i]->print_xml();
            }

        }

        };

#endif
