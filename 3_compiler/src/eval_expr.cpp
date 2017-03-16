#include "ast.hpp"

#include <iomanip>

int main(int argc, char *argv[])
{
    std::map<std::string,double> bindings;

    std::string inputVar;
    double inputNum;
    std::string expression;

    // TODO : for each pair of arguments:
    //  - read the variable name
    //  - parse the value
    //  - insert into the bindings map

    for(int i = 1; i < argc; i+=2){
      inputVar = argv[i];
      inputNum = std::stod(argv[i+1]);
      bindings.insert(std::pair<std::string, double>(inputVar, inputNum));
    }

    const Expression *ast=parseAST();

    double res = ast->evaluate(bindings);

    // TODO : print out with 6 decimal digits of precision
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << res << std::endl;

    return 0;
}
