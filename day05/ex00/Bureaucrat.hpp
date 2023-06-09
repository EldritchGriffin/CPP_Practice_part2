#ifndef BUREUACRAT_HPP
#define BUREUACRAT_HPP

#include <iostream>
#include <exception>



class Bureaucrat
{
    private:

        const std::string name;
        int grade;

    public:

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        virtual ~Bureaucrat();
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator= (const Bureaucrat& obj);

        void    inc_gr();
        void    dec_gr();

        const std::string get_name() const;
        int   get_grade();
        void  set_grade(int grade);

        class GradeTooLowException : public std::runtime_error
        {
            public:
                GradeTooLowException();
        };
        class GradeTooHighException : public std::runtime_error
        {
            public:
                GradeTooHighException();
        };
};

#endif