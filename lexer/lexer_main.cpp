#include <iostream>
#include "c_lexer.hpp"

#include <vector>
#include <sstream>

struct jsonContainer{
    std::string tokenClass;
    std::string text;
    int streamline;
    std::string sourcefile;


};

TokenContainer yylval;

int main() {

    std::vector<jsonContainer> foundValues;
    std::string className;


    while(1){
        TokenType type = (TokenType)yylex();

        if(type == None){
            break;
        }
        if(type == Keyword){
            className = "Keyword";
        }
        if(type == Identifier){
            className = "Identifier";
        }
        if(type == Operator){
            className = "Operator";
        }
        if(type == Constant){
            className = "Constant";
        }
        if(type == StringLiteral){
            className = "StringLiteral";
        }
        if(type == Invalid){
            className = "Invalid";
        }

        /*switch(type){
            case None: break;
            case Keyword: className = "Keyword";
            case Identifier: className = "Identifier";
            case Operator: className = "Operator";
            case Constant: className = "Constant";
            case StringLiteral: className = "StringLiteral";
            case Invalid: className = "Invalid";
        } why does this not work? */

        jsonContainer temp{
                .tokenClass = className,
                .text = *yylval.value
        };
        foundValues.push_back(temp);

    }

    // create stringstream item
    // loop through and add the values
    std::stringstream ss;
    ss << "[" << std::endl;
    for(std::vector<jsonContainer>::iterator iter = foundValues.begin(); iter != foundValues.end(); ++iter){
        ss << "{" << "\"Class\": \t" << "\"" << iter->tokenClass <<"\"" << ",\t" << "\"Text:\"\t" << "\"" << iter->text << "\"" << "\t}," << std::endl;
    }
    ss << "{}" << std::endl << "]";
    std::string jsonString = ss.str();
    std::cout << jsonString << std::endl;
    return 0;
}

