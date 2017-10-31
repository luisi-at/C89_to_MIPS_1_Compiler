#include <iostream>
#include "c_lexer.hpp"
#include <algorithm>
#include <vector>
#include <sstream>

struct jsonContainer{
    std::string tokenClass;
    std::string text;
    int streamline;
    int columnNumber;
    std::string sourcefile;
    int sourceLine;
};

// source column ahead too many characters
// source line lags by 1

jsonContainer serialize(std::string className, std::string text, int streamline, std::string sfile);

TokenContainer yylval;

int main() {

    std::vector<jsonContainer> foundValues;
    std::string className;
    std::string assignString;

    std::string tempsfile;
    int sline = 0;

    int colnum = 1;
    int prevcol;
    bool serialize = false;

    while(1){
        TokenType type = (TokenType)yylex();
        serialize = false;

        prevcol = colnum;

        if(type == None){
            break;
        }
        if(type == Keyword){
            className = "Keyword";
            assignString = *yylval.value;
            colnum += yyleng;
            serialize = true;
        }
        if(type == Identifier){
            className = "Identifier";
            colnum += yyleng;
            assignString = *yylval.value;
            serialize = true;
        }
        if(type == Operator){
            className = "Operator";
            colnum += yyleng;
            assignString = *yylval.value;
            serialize = true;
        }
        if(type == Constant){
            className = "Constant";
            if(*yylval.value == "\t"){
                std::cout << "TAB" << std::endl;
                colnum += 8; // - (colnum % 8);
            }
            else{
                colnum += yyleng;
            }
            assignString = *yylval.value;
            serialize = true;
        }
        if(type == StringLiteral){
            className = "StringLiteral";
            colnum += yyleng;
            assignString = *yylval.value;
            assignString.erase(remove(assignString.begin(), assignString.end(), '\"'), assignString.end());
            serialize = true;
        }
        if(type == Invalid){
            className = "Invalid";
            colnum += yyleng;
            assignString = *yylval.value;
            serialize = true;
        }
        if(type == PreProcessor){
            // take the line number
            // then take the filename
            //std::cout << *yylval.value << std::endl;
            std::stringstream ss(*yylval.value);
            std::string buffer;
            std::vector<std::string> temptok;
            while(ss >> buffer){
                temptok.push_back(buffer);
            }
            //know that preproc is tokens separated by spaces
            // pos0 = #
            // pos1 = lineno
            // pos2 = fileno
            // pos3 = NA
            sline = std::stoi(temptok[1]) - 1;
            tempsfile = temptok[2];
            //std::cout << temptok[3] << std::endl;
            serialize = false;
        }
        if(type == AddCol){
            if(*yylval.value == "\t"){
                std::cout << "TAB" << std::endl;
                colnum += 8; // - (colnum % 8);
            }
            else{
                colnum++;
            }
            serialize = false;
        }
        if(type == ResetCol){
            colnum = 1;
            sline++;
            serialize = false;
        }

        if(serialize){

            jsonContainer temp;
            temp.tokenClass = className;
            temp.text = assignString;
            temp.streamline = yylineno;
            temp.columnNumber = prevcol;
            temp.sourceLine = sline;
            temp.sourcefile = tempsfile;

            foundValues.push_back(temp);
        }

    }

    // create stringstream item
    // loop through and add the values
    std::stringstream ss;
    ss << "[" << std::endl;
    for(std::vector<jsonContainer>::iterator iter = foundValues.begin(); iter != foundValues.end(); ++iter){
        ss << "{" << "\"Class\"" << ":" << "\"" << iter->tokenClass << "\", " << "\"Text\"" << ":" << "\"" << iter->text << "\", ";
        ss << "\"StreamLine\"" << ":" << iter->streamline << ", ";
        ss << "\"SourceFile\"" << ":\"" << iter->sourcefile << "\", "; // DT10
        ss << "\"SourceLine\"" << ": " << iter->sourceLine << ", ";
        ss << "\"SourceCol\"" << ":" << iter->columnNumber << "}," << std::endl;
    }
    ss << "{}" << std::endl << "]";
    std::string jsonString = ss.str();
    std::cout << jsonString << std::endl;
    return 0;
}


