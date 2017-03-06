#include "ast.hpp"

int main()
{
    const Unit *ast=parseAST();

    ast->print_xml();
    std::cout<<std::endl;

    return 0;
}
