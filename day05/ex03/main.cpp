#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern stagir;
    AForm* form = stagir.makeForm("robotomy request", "Bender");
    Bureaucrat b("Bender", 1);

    b.signForm(*form);
    b.executeForm(*form);
    delete form;
    form = stagir.makeForm("presidential pardon", "Bender");
    b.signForm(*form);
    b.executeForm(*form);
    delete form;
    form = stagir.makeForm("shrubbery creation", "Bender");
    b.signForm(*form);
    b.executeForm(*form);
    delete form;
    form = stagir.makeForm("shrubbery", "Bender");
}