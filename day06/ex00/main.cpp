#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return (1);
    }
    try
    {
        ScalarConverter sc(argv[1]);
        sc.convert();
    }
    catch(const ScalarConverter::InvalidInputException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}