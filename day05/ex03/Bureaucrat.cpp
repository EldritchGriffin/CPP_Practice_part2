#include "Bureaucrat.hpp"

//Constructors------------------

Bureaucrat::Bureaucrat() :name("obama"){ this->grade = 150; }

Bureaucrat::Bureaucrat(std::string name, int grade):name(name){this->set_grade(grade);}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name){ this->set_grade(obj.grade); }

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& obj)
{
    Bureaucrat  *bureaucrat = new Bureaucrat(obj);
    return (*bureaucrat);
}

//incrementing and decrementing the Grade

void    Bureaucrat::inc_gr()
{
    int grade = this->get_grade();
    this->set_grade(--grade);
}
void    Bureaucrat::dec_gr()
{
    int grade = this->get_grade();
    this->set_grade(++grade);
}
//Exeption Handling functions------

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("Grade Too High Exception."){}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("Grade Too Low Exeption."){}

//Getters & Setters--------------------------

int Bureaucrat::get_grade() const
{
    return this->grade;
}

void Bureaucrat::set_grade(int grade)
{
    if(grade < 1)
        throw  GradeTooHighException();
    else if(grade > 150)
        throw  GradeTooLowException();
    else
        this->grade = grade;
}

const std::string Bureaucrat::get_name() const
{
    return this->name;
}

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " Signed " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
    }
    
} 
