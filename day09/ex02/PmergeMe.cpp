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
		this->_startdq = rhs._startdq;
		this->_enddq = rhs._enddq;
		this->_startvc = rhs._startvc;
		this->_endvc = rhs._endvc;
	}
    return *this;
}

void	insertionSortVc(std::vector<int> &vc)
{
	unsigned long i = 1;
	int j;
	int tmp;

	while (i < vc.size())
	{
		j = i;
		while (j > 0 && vc[j - 1] > vc[j])
		{
			tmp = vc[j];
			vc[j] = vc[j - 1];
			vc[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

void	insertionSortDq(std::deque<int> &dq)
{
	unsigned long i = 1;
	int j;
	int tmp;

	while (i < dq.size())
	{
		j = i;
		while (j > 0 && dq[j - 1] > dq[j])
		{
			tmp = dq[j];
			dq[j] = dq[j - 1];
			dq[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

void	mergeDq(std::deque<int> &left, std::deque<int> &right, std::deque<int> &dq)
{
	unsigned long i = 0;
	unsigned long j = 0;
	unsigned long k = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			dq[k] = left[i++];
		else
			dq[k] = right[j++];
		k++;
	}
	while (i < left.size())
		dq[k++] = left[i++];
	while (j < right.size())
		dq[k++] = right[j++];
}

void	mergeVc(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vc)
{
	unsigned long i = 0;
	unsigned long j = 0;
	unsigned long k = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
			vc[k] = left[i++];
		else
			vc[k] = right[j++];
		k++;
	}
	while (i < left.size())
		vc[k++] = left[i++];
	while (j < right.size())
		vc[k++] = right[j++];
}

void	PmergeMe::mergeSortDq(std::deque<int> &dq)
{
	std::deque<int> left;
	std::deque<int> right;
	unsigned long middle;

	if (dq.size() <= 1)
		return;
	if(dq.size() <= this->_dqSize * 0.2)
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

void	PmergeMe::setStartdq(clock_t startdq) { _startdq = startdq; }

void	PmergeMe::setEnddq(clock_t enddq) { _enddq = enddq; }

void	PmergeMe::setStartvc(clock_t startvc) { _startvc = startvc; }

void	PmergeMe::setEndvc(clock_t endvc) { _endvc = endvc; }

void	PmergeMe::setVcSize(int vcSize) { _vcSize = vcSize; }

void	PmergeMe::setDqSize(int dqSize) { _dqSize = dqSize; }

clock_t	PmergeMe::getStartdq() const { return _startdq; }

clock_t	PmergeMe::getEnddq() const { return _enddq; }

clock_t	PmergeMe::getStartvc() const { return _startvc; }

clock_t	PmergeMe::getEndvc() const { return _endvc; }


