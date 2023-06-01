#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>

class PmergeMe
{
    private:
        int _vcSize;
        int _dqSize;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const & src);
        ~PmergeMe();
        PmergeMe & operator=(PmergeMe const & rhs);
        void    mergeSortVc(std::vector<int> &vc);
        void    mergeSortDq(std::deque<int> &dq);


        void                setVcSize(int vcSize);
        void                setDqSize(int dqSize);
};

#endif