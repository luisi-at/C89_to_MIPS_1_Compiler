#include <iostream>
#include "c_lexer.hpp"

#include <vector>
#include <sstream>

struct jsonContainer{
    std::string tokenClass;
    std::string text;
    int streamline;
    int columnline;
    std::string sourcefile;


};

jsonContainer serialize(std::string className, std::string text, int streamline, std::string sfile);

TokenContainer yylval;

int main() {

    std::vector<jsonContainer> foundValues;
    std::string className;

    int sline = 1;
    bool serialize = false;

    while(1){
        TokenType type = (TokenType)yylex();
        serialize = false;

        if(type == None){
            break;
        }
        if(type == Keyword){
            className = "Keyword";
            serialize = true;
        }
        if(type == Identifier){
            className = "Identifier";
            serialize = true;
        }
        if(type == Operator){
            className = "Operator";
            serialize = true;
        }
        if(type == Constant){
            className = "Constant";
            serialize = true;
        }
        if(type == StringLiteral){
            className = "StringLiteral";
            serialize = true;
        }
        if(type == Invalid){
            className = "Invalid";
            serialize = true;
        }
        if(type == StreamlineUpdate){
            sline++;
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

        if(serialize){
            jsonContainer temp{
                    .tokenClass = className,
                    .text = *yylval.value,
                    .streamline = sline

            };
            foundValues.push_back(temp);
        }

    }

    // create stringstream item
    // loop through and add the values
    std::stringstream ss;
    ss << "[" << std::endl;
    for(std::vector<jsonContainer>::iterator iter = foundValues.begin(); iter != foundValues.end(); ++iter){
        ss << "{" << "\"Class\": \t" << "\"" << iter->tokenClass <<"\"\t" << ",\t" << "\"Text:\"\t" << "\"" << iter->text << "\",\t";
        ss << "\"Streamline\": \t" << iter->streamline << "\t}" << std::endl;
    }
    ss << "{}" << std::endl << "]";
    std::string jsonString = ss.str();
    std::cout << jsonString << std::endl;
    return 0;
}

jsonContainer serialize(std::string className, std::string text, int streamline, std::string sfile){


}