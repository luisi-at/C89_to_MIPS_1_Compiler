#include <iostream>
#include "c_lexer.hpp"

#include <vector>
#include <sstream>

struct jsonContainer{
    std::string tokenClass;
    std::string text;
    int streamline;
    int columnNumber;
    std::string sourcefile;


};

jsonContainer serialize(std::string className, std::string text, int streamline, std::string sfile);

TokenContainer yylval;

int main() {

    std::vector<jsonContainer> foundValues;
    std::string className;

    int sline = 1;
    int colnum = 0;
    bool serialize = false;

    while(1){
        TokenType type = (TokenType)yylex();
        serialize = false;

        if(type == None){
            break;
        }
        if(type == Keyword){
            className = "Keyword";
            colnum++;
            serialize = true;
        }
        if(type == Identifier){
            className = "Identifier";
            colnum++;
            serialize = true;
        }
        if(type == Operator){
            className = "Operator";
            colnum++;
            serialize = true;
        }
        if(type == Constant){
            className = "Constant";
            colnum++;
            serialize = true;
        }
        if(type == StringLiteral){
            className = "StringLiteral";
            colnum++;
            serialize = true;
        }
        if(type == Invalid){
            className = "Invalid";
            colnum++;
            serialize = true;
        }
        if(type == StreamlineUpdate){
            sline++;
            colnum = 0;
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
                    .streamline = sline,
                    .columnNumber = colnum

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
        ss << "\"Streamline\": \t" << iter->streamline << ",\t";
        ss << "\"SourceCol\": \t" << iter->columnNumber << "\t}" << std::endl;
    }
    ss << "{}" << std::endl << "]";
    std::string jsonString = ss.str();
    std::cout << jsonString << std::endl;
    return 0;
}

jsonContainer serialize(std::string className, std::string text, int streamline, std::string sfile){


}