#include "ast.hpp"

#include <iomanip>

int main()
{
    const Unit *ast=parseAST();

    Context programContext;

    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".file " << std::setw(15) << std::left << "1 \"file\"" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".section " << std::setw(15) << std::left << ".mdebug.abi32" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".previous " << std::setw(15) << std::left << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".nan " << std::setw(15) << std::left << "legacy" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".module " << std::setw(15) << std::left << "fp=xx" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".module " << std::setw(15) << std::left << "nooddspreg" << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".abicalls " << std::setw(15) << std::endl;
    std::cout << std::setw(5) << std::left << "" << std::setw(10) << std::left << ".text " << std::setw(15) << std::endl;

    ast->codegen(programContext);

    return 0;
}
