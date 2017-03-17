#include "ast.hpp"
#include <iomanip>

int main()
{
    const Unit *ast=parseAST();

    std::cout << std::setw(10) << std::left << ".file " << std::right << "1 \"file\"" << std::endl;
    std::cout << std::setw(10) << std::left <<  ".section " << std::right << ".mdebug.abi32" << std::endl;
    std::cout << std::setw(10) << std::left << ".previous " << std::right << std::endl;
    std::cout << std::setw(10) << std::left << ".nan " << std::right << "legacy" << std::endl;
    std::cout << std::setw(10) << std::left << ".module " << std::right << "fp=xx" << std::endl;
    std::cout << std::setw(10) << std::left << ".module " << std::right << "nooddspreg" << std::endl;
    std::cout << std::setw(10) << std::left << ".abicalls " << std::endl;
    std::cout << std::setw(10) << std::left << ".text " << std::endl;
    std::cout << std::setw(10) << std::left << std::endl;

    return 0;
}
