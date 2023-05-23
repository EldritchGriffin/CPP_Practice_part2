#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn(argv[1]);
        rpn.parseExpression();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
