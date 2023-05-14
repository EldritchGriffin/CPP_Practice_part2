#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    data.action = 42;
    data.action_name = "Hello World!";
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "raw data: " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "action: " << ptr->action << std::endl;
    std::cout << "action_name: " << ptr->action_name << std::endl;
    return (0);
}