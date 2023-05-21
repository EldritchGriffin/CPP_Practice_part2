#include "Easyfind.hpp"

template<typename T>
void    print(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v;
    std::array<int, 3> a = {1, 2, 3};
    std::deque<int> d;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(v.begin(), 0);

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(0);

    std::cout << "vector: ";
    print(v);

    std::cout << "array: ";
    print(a);

    std::cout << "deque: ";
    print(d);

    try
    {
        std::cout << "easyfind(v, 3): " << *easyfind(v, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "easyfind(a, 0): " << *easyfind(a, 0) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "easyfind(d, 1): " << *easyfind(d, 1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}