#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const & src) { *this = src; }

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		this->_vcSize = rhs._vcSize;
		this->_dqSize = rhs._dqSize;
	}
    return *this;
}

void	insertionSortVc(std::vector<int> &vc)
{
	std::vector<int>::iterator i = vc.begin();
	std::vector<int>::iterator ie = vc.end();
	std::vector<int>::iterator j;
	int tmp;

	while (i < ie)
	{
		j = i;
		while (j > vc.begin() && *(j - 1) > *j)
		{
			tmp = *j;
			*j = *(j - 1);
			*(j - 1) = tmp;
			j--;
		}
		i++;
	}
}

void	insertionSortDq(std::deque<int> &dq)
{
	std::deque<int>::iterator i = dq.begin();
	std::deque<int>::iterator ie = dq.end();
	std::deque<int>::iterator j;
	int tmp;

	while (i < ie)
	{
		j = i;
		while (j > dq.begin() && *(j - 1) > *j)
		{
			tmp = *j;
			*j = *(j - 1);
			*(j - 1) = tmp;
			j--;
		}
		i++;
	}
}

void	mergeDq(std::deque<int> &left, std::deque<int> &right, std::deque<int> &dq)
{
	std::deque<int>::iterator i = left.begin();
	std::deque<int>::iterator j = right.begin();
	std::deque<int>::iterator k = dq.begin();

	std::deque<int>::iterator ie = left.end();
	std::deque<int>::iterator je = right.end();

	while (i < ie && j < je)
	{
		if (*i < *j)
		{
			*k = *i;
			i++;
		}
		else
		{
			*k = *j;
			j++;
		}
		k++;
	}
	while (i < ie)
	{
		*k = *i;
		i++;
	}
	while (j < je)
	{
		*k = *j;
		j++;
	}
}

void	mergeVc(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vc)
{
	std::vector<int>::iterator i = left.begin();
	std::vector<int>::iterator j = right.begin();
	std::vector<int>::iterator k = vc.begin();

	std::vector<int>::iterator ie = left.end();
	std::vector<int>::iterator je = right.end();

	while (i < ie && j < je)
	{
		if (*i < *j)
		{
			*k = *i;
			i++;
		}
		else
		{
			*k = *j;
			j++;
		}
		k++;
	}
	while (i < ie)
	{
		*k = *i;
		i++;
	}
	while (j < je)
	{
		*k = *j;
		j++;
	}
}

void	PmergeMe::mergeSortDq(std::deque<int> &dq)
{
	std::deque<int> left;
	std::deque<int> right;
	unsigned long middle;

	if (dq.size() <= 1)
		return;
	if(dq.size() <= this->_dqSize * 0.2 || dq.size() <= 10)
	{
		insertionSortDq(dq);
		return;
	}
	middle = dq.size() / 2;
	for (unsigned long i = 0; i < middle; i++)
		left.push_back(dq[i]);
	for (unsigned long i = middle; i < dq.size(); i++)
		right.push_back(dq[i]);
	mergeSortDq(left);
	mergeSortDq(right);
	mergeDq(left, right, dq);
}

void	PmergeMe::mergeSortVc(std::vector<int> &vc)
{
	std::vector<int> left;
	std::vector<int> right;
	unsigned long middle;

	if (vc.size() <= 1)
		return;
	if(vc.size() <= this->_vcSize * 0.2 || vc.size() <= 10)
	{
		insertionSortVc(vc);
		return;
	}
	middle = vc.size() / 2;
	for (unsigned long i = 0; i < middle; i++)
		left.push_back(vc[i]);
	for (unsigned long i = middle; i < vc.size(); i++)
		right.push_back(vc[i]);
	mergeSortVc(left);
	mergeSortVc(right);
	mergeVc(left, right, vc);
}

void	PmergeMe::setVcSize(int vcSize) { _vcSize = vcSize; }

void	PmergeMe::setDqSize(int dqSize) { _dqSize = dqSize; }



