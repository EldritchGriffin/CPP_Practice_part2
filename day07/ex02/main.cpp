#include "Array.hpp"

int main()
{
    Array<int> intArray(5);
    Array<std::string> stringArray(5);

    for (int i = 0; i < 5; i++)
    {
        intArray[i] = i;
        stringArray[i] = std::to_string(i);
    }

    std::cout << "intArray: ";
    for (int i = 0; i < 5; i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    std::cout << "stringArray: ";
    for (int i = 0; i < 5; i++)
        std::cout << stringArray[i] << " ";
    std::cout << std::endl;

    std::cout << "intArray size: " << intArray.size() << std::endl;
    std::cout << "stringArray size: " << stringArray.size() << std::endl;

    std::cout << "intArray[0]: " << intArray[0] << std::endl;
    std::cout << "stringArray[0]: " << stringArray[0] << std::endl;

    std::cout << "intArray[4]: " << intArray[4] << std::endl;
    std::cout << "stringArray[4]: " << stringArray[4] << std::endl;

    try
    {
        std::cout << "intArray[5]: " << intArray[5] << std::endl;
        std::cout << "stringArray[5]: " << stringArray[5] << std::endl;

        std::cout << "intArray[-1]: " << intArray[-1] << std::endl;
        std::cout << "stringArray[-1]: " << stringArray[-1] << std::endl;

        std::cout << "intArray[6]: " << intArray[6] << std::endl;
        std::cout << "stringArray[6]: " << stringArray[6] << std::endl;

        std::cout << "intArray[100]: " << intArray[100] << std::endl;
        std::cout << "stringArray[100]: " << stringArray[100] << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}