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
    form.execute(b);
    form2.execute(b);
    form3.execute(b);
    return (0);
}