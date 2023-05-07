#include "Bureaucrat.hpp"

int main()
{
    //0 is normal case, change the number assigned to I to change the test;
    int i = 0;
    if(i == 0)
    {
        try
        {
            Bureaucrat obama;
            std::cout << "the code continues after construction" << std::endl;
        }
        catch(const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "the code continues to the end of the if statement" << std::endl;
    }
    else if (i == 1) // 1 will throw the GradeTooLow Exception;
    {
        try
        {
            Bureaucrat obama("obama", 151);
        }
        catch(const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if (i == 2) // 2 will throw the GradeTooHigh Exception after incrementing the grade;
    {
        try
        {
            Bureaucrat obama("obama", 1);
            std::cout << obama.get_grade() << std::endl;
            obama.inc_gr();
            std::cout << "this wont be printed." << std::endl;
        }
        catch(const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

}