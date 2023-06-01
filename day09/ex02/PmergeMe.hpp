#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>

class PmergeMe
{
    private:
        int _vcSize;
        int _dqSize;
        clock_t _startdq;
        clock_t _enddq;
        clock_t _startvc;
        clock_t _endvc;
    public:
        PmergeMe();
        PmergeMe(PmergeMe const & src);
        ~PmergeMe();
        PmergeMe & operator=(PmergeMe const & rhs);
        void    mergeSortVc(std::vector<int> &vc);
        void    mergeSortDq(std::deque<int> &dq);


        void                setStartdq(clock_t startdq);
        void                setEnddq(clock_t enddq);
        void                setStartvc(clock_t startvc);
        void                setEndvc(clock_t endvc);
        void                setVcSize(int vcSize);
        void                setDqSize(int dqSize);
        clock_t             getStartdq() const;
        clock_t             getEnddq() const;
        clock_t             getStartvc() const;
        clock_t             getEndvc() const;
};

#endif