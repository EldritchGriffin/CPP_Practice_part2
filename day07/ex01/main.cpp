
#include <iostream>
#include "iter.hpp"

template<typename T>
void    print_array(T & x)
{
    std::cout << x << " ";
}

void    add_one(int& x)
{
    x++;
}

void    subtract_one(float& x)
{
    x -= 1.1f;
}

void    append(std::string& x)
{
    x += "!";
}

void    rotate(char& x)
{
    if (x == 'z')
        x = 'a';
    else if (x == 'Z')
        x = 'A';
    else
        x++;
}

int main()
{
    int array[] = { 0, 1, 2, 3, 4 };
    iter(array, 5, print_array);
    iter(array, 5, add_one);
    std::cout << std::endl;
    iter(array, 5, print_array);
    std::cout << std::endl;

    std::string array2[] = { "zero", "one", "two", "three", "four" };
    iter(array2, 5, print_array);
    iter(array2, 5, append);
    std::cout << std::endl;
    iter(array2, 5, print_array);
    std::cout << std::endl;

    float array3[] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
    iter(array3, 5, print_array);
    iter(array3, 5, subtract_one);
    std::cout << std::endl;
    iter(array3, 5, print_array);
    std::cout << std::endl;

    char array4[] = { 'a', 'b', 'c', 'd', 'z' };
    iter(array4, 5, print_array);
    iter(array4, 5, rotate);
    std::cout << std::endl;
    iter(array4, 5, print_array);
    std::cout << std::endl;
}