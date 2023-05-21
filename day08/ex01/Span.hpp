#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>

class Span
{
    private:
        unsigned int    _n;
        std::vector<int> _v;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &copy);

        void    addNumber(int n);
        int     shortestSpan();
        int     longestSpan();
        void    addRange(int start, int end);
        void    print();
        class FullException : public std::runtime_error
        {
            public:
                FullException();
        };
        class NoSpanException : public std::runtime_error
        {
            public:
                NoSpanException();
        };
};



#endif