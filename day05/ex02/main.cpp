#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"



int main()
{
    RobotomyRequestForm form("Bender");
    Bureaucrat b("Bender", 1);
    b.signForm(form);
    PresidentialPardonForm form2("Bender");
    b.signForm(form2);
    ShrubberyCreationForm form3("Bender");
    b.signForm(form3);
    b.executeForm(form);
    b.executeForm(form2);
    b.executeForm(form3);
    return (0);
}