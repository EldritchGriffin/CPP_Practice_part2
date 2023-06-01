#include "PmergeMe.hpp"

std::vector<int>    fillvc(char **av)
{
    std::vector<int> vc;
    int i = 1;
    while(av[i])
    {
        vc.push_back(std::atoi(av[i]));
        i++;
    }
    return vc;
}
std::deque<int>    filldq(char **av)
{
    std::deque<int> dq;
    int i = 1;
    int j = 0;
    while(av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if(!std::isdigit(av[i][j]))
                throw std::invalid_argument("Invalid argument");
            j++;
        }
        
        dq.push_back(std::atoi(av[i]));
        i++;
    }
    return dq;
}

void    printArgs(char  **av)
{
    int i = 1;
    int j = 0;
    std::cout << "Before: ";
    while(av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if(!std::isdigit(av[i][j]))
                throw std::invalid_argument("Invalid argument");
            j++;
        }
        std::cout << av[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void    printVc(std::vector<int> vc)
{
    std::cout << "After: ";
    for (unsigned long i = 0; i < vc.size(); i++)
        std::cout << vc[i] << " ";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if(ac == 1)
    {
        std::cout << "Usage: ./PmergeMe 1 2 3 4 5 6 7 8 9" << std::endl;
        return 1;
    }
    try
    {
        printArgs(av);

        PmergeMe pm;

        pm.setStartvc(clock());
        std::vector<int> vc = fillvc(av);
        pm.setVcSize(vc.size());
        pm.mergeSortVc(vc);
        pm.setEndvc(clock());
        //------
        pm.setStartdq(clock());
        std::deque<int> dq = filldq(av);
        pm.setDqSize(dq.size());
        pm.mergeSortDq(dq);
        pm.setEnddq(clock());
        //------
        printVc(vc);
        std::cout << "Time to process a range of " << vc.size() << " elements with std::vector " << 
        " elements: " << (double)(pm.getEndvc() - pm.getStartvc()) / 1000 << " us" << std::endl;
        std::cout << "Time to process a range of " << dq.size() << " elements with std::deque " <<
        " elements: " << (double)(pm.getEnddq() - pm.getStartdq()) / 1000 << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}