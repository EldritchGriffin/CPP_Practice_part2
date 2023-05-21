#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span() {}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _v = copy._v;
    }
    return (*this);
}

void    Span::addNumber(int n)
{
    if (_v.size() >= _n)
        throw FullException();
    _v.push_back(n);
}

int     Span::shortestSpan()
{
    std::vector<int> tmp = _v;
    if (tmp.size() <= 1)
        throw NoSpanException();
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return (min);
}

int     Span::longestSpan()
{
    std::vector<int> tmp = _v;
    if (tmp.size() <= 1)
        throw NoSpanException();
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

void    Span::addRange(int start, int end)
{
    if (start > end)
        throw std::invalid_argument("invalid input range");
    if (end - start + 1 > (int)(_n - _v.size()))
        throw FullException();
    for (int i = start; i <= end; i++)
        _v.push_back(i);
}

void    Span::print()
{
    for (unsigned int i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << std::endl;
}

Span::FullException::FullException() : std::runtime_error("Span is full") {}

Span::NoSpanException::NoSpanException() : std::runtime_error("No span to find") {}

