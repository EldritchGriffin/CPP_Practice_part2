#include "Form.hpp"

Form::Form() : name("tarikh zdiyad"), signature(false), toSign(150), toExec(150) {}

Form::Form(std::string name, const int to_sign, const int to_exec) : name(name), signature(false), toSign(to_sign), toExec(to_exec) 
{
    if(this->toSign > 150 || this->toExec > 150)
        throw Form::GradeTooLowException();
    else if(this->toSign < 1 || this->toExec < 1)
        throw Form::GradeTooHighException();
}

Form::~Form(){}

Form::Form(const Form& obj) : name(obj.name), signature(obj.signature), toSign(obj.toSign), toExec(obj.toExec) {}

Form& Form::operator=(const Form& obj)
{
    Form *form = new Form(obj);
    return (*form);
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if(!this->signature)
    {
        if(bureaucrat.get_grade() <= this->toSign)
            this->signature = true;
        else
            throw Form::GradeTooLowException();
    }
    else
        throw Form::FormAlreadySignedException();
}

const std::string Form::get_name() const
{
    return this->name;
}

bool Form::get_signature()
{
    return this->signature;
}

int Form::get_toSign() const
{
    return this->toSign;
}
int Form::get_toExec() const
{
    return this->toExec;
}
void    Form::set_signature(bool signature)
{
    this->signature = signature;
}

std::ostream&   operator<< ( std::ostream& ostrm, Form& form)
{
    ostrm << "Form name : " << form.get_name() << std::endl;
	ostrm << "SignGrade : " << form.get_toSign() << std::endl;
	ostrm << "ExecGrade : " << form.get_toExec() << std::endl;
	ostrm << "isSigned : " <<  form.get_signature();
    return ostrm;
}

Form::GradeTooHighException::GradeTooHighException() : std::runtime_error("GradeTooHigh."){}
Form::GradeTooLowException::GradeTooLowException() : std::runtime_error("GradeTooLow."){}
Form::FormAlreadySignedException::FormAlreadySignedException() : std::runtime_error("Form already signed."){}

