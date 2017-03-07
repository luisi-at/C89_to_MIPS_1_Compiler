#include "ast.hpp"

int main()
{
    const Unit *ast=parseAST();

    std::cout << "<?xml version = \"1.0\"?>" << std::endl;
    std::cout << "<Program>" << std::endl;
    ast->print_xml();
    std::cout << "</Program>" << std::endl;
    std::cout<<std::endl;

    return 0;
}
