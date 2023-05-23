#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

class RPN
{
    private:
        std::stack<int> _stack;
        std::string _expression;
        void _add();
        void _sub();
        void _mul();
        void _div();
    public:
        RPN();
        RPN(std::string input);
        RPN(const RPN &copy);
        ~RPN();
        RPN &operator=(const RPN &copy);

        void parseExpression();

        class NotEnoughValuesException : public std::runtime_error
        {
            public:
                NotEnoughValuesException();
        };
        class InvalidInputException : public std::runtime_error
        {
            public:
                InvalidInputException();
        };
        class DivisionByZeroException : public std::runtime_error
        {
            public:
                DivisionByZeroException();
        };
};

#endif