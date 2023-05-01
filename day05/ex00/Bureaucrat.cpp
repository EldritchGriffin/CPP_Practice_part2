#include "Bureaucrat.hpp"

//Constructors------------------

Bureaucrat::Bureaucrat() :name("obama"){ this->grade = 150; }

Bureaucrat::Bureaucrat(int grade){this->set_grade(grade);}

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

Bureaucrat::GradeTooHigh::GradeTooHigh() : std::runtime_error("Grade Too High Exception."){}
Bureaucrat::GradeTooLow::GradeTooLow() : std::runtime_error("Grade Too Low Exeption."){}

//Getters & Setters--------------------------

int Bureaucrat::get_grade()
{
    return this->grade;
}

void Bureaucrat::set_grade(int grade)
{
    if(grade < 1)
        throw  GradeTooHigh();
    else if(grade > 150)
        throw  GradeTooLow();
    else
        this->grade = grade;
}

const std::string Bureaucrat::get_name() const
{
    return this->name;
}
