#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    sp.print();
    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span sp2 = Span(10000);
    sp2.addRange(0, 9999);
    std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
    try
    {
        sp2.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span sp3 = Span(10000);
    try
    {
        std::cout << "shortestSpan: " << sp3.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "longestSpan: " << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span sp4 = Span(1);
    sp4.addNumber(42);
    try
    {
        std::cout << "shortestSpan: " << sp4.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "longestSpan: " << sp4.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}