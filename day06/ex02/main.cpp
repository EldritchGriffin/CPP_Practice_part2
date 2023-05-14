#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <iostream>

Base * generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new ClassA;
    else if (i == 1)
        return new ClassB;
    else
        return new ClassC;
}

void identify_from_pointer(Base * p)
{
    if (dynamic_cast<ClassA *>(p))
        std::cout << "Pointer type is of ClassA" << std::endl;
    else if (dynamic_cast<ClassB *>(p))
        std::cout << "Pointer type is of ClassB" << std::endl;
    else if (dynamic_cast<ClassC *>(p))
        std::cout << "Pointer type is of ClassC" << std::endl;
}

void identify_from_reference(Base & p)
{
    try
    {
        ClassA &a = dynamic_cast<ClassA &>(p);
        std::cout << "Reference type is of ClassA" << std::endl;
        (void)a;
        return;
    }
    catch(const std::bad_cast& e)
    {
    }
    try
    {
        ClassB &b = dynamic_cast<ClassB &>(p);
        std::cout << "Reference type is of ClassB" << std::endl;
        (void)b;
        return;
    }
    catch(const std::bad_cast& e)
    {
    }
    try
    {
        ClassC &c = dynamic_cast<ClassC &>(p);
        std::cout << "Reference type is of ClassC" << std::endl;
        (void)c;
        return;
    }
    catch(const std::bad_cast& e)
    {
        std::cerr << "Error: " << "Impossible cast" << std::endl;
    }
}

int main()
{
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
    return 0;
}