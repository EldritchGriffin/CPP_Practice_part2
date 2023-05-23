#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) : _expression(input) {}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
    {
        this->_stack = rhs._stack;
    }
    return *this;
}


void RPN::_add()
{
    if (this->_stack.size() < 2)
        throw RPN::NotEnoughValuesException();
    int a = this->_stack.top();
    this->_stack.pop();
    int b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a + b);
}

void RPN::_sub()
{
    if (this->_stack.size() < 2)
        throw RPN::NotEnoughValuesException();
    int a = this->_stack.top();
    this->_stack.pop();
    int b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(b - a);
}

void RPN::_mul()
{
    if (this->_stack.size() < 2)
        throw RPN::NotEnoughValuesException();
    int a = this->_stack.top();
    this->_stack.pop();
    int b = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a * b);
}

void RPN::_div()
{
    if (this->_stack.size() < 2)
        throw RPN::NotEnoughValuesException();
    int a = this->_stack.top();
    this->_stack.pop();
    int b = this->_stack.top();
    this->_stack.pop();
    if (a == 0)
        throw RPN::DivisionByZeroException();
    this->_stack.push(b / a);
}

void RPN::parseExpression()
{
    std::string::iterator it = this->_expression.begin();
    std::string::iterator ite = this->_expression.end();
    while (it != ite)
    {
        if (*it == '+')
            this->_add();
        else if (*it == '-')
            this->_sub();
        else if (*it == '*')
            this->_mul();
        else if (*it == '/')
            this->_div();
        else if (*it >= '0' && *it <= '9')
            this->_stack.push(*it - '0');
        else if (*it != ' ')
            throw RPN::InvalidInputException();
        it++;
    }
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    std::cout << this->_stack.top() << std::endl;
}

RPN::NotEnoughValuesException::NotEnoughValuesException() : std::runtime_error("Error: Not enough values in stack") {}

RPN::InvalidInputException::InvalidInputException() : std::runtime_error("Error: Invalid input") {}

RPN::DivisionByZeroException::DivisionByZeroException() : std::runtime_error("Error: Division by zero") {}