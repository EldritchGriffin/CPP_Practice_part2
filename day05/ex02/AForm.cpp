#include "AForm.hpp"

AForm::AForm() : name("tarikh zdiyad"), signature(false), toSign(150), toExec(150) {}

AForm::AForm(std::string name, const int to_sign, const int to_exec) : name(name), signature(false), toSign(to_sign), toExec(to_exec) 
{
    if(this->toSign > 150 || this->toExec > 150)
        throw AForm::GradeTooLowException();
    else if(this->toSign < 1 || this->toExec < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm(){}

AForm::AForm(const AForm& obj) : name(obj.name), signature(obj.signature), toSign(obj.toSign), toExec(obj.toExec) {}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(!this->signature)
    {
        if(bureaucrat.get_grade() <= this->toSign)
            this->signature = true;
        else
            throw AForm::GradeTooLowException();
    }
    else
        throw AForm::FormAlreadySignedException();
}

const std::string AForm::get_name() const
{
    return this->name;
}

bool AForm::get_signature() const
{
    return this->signature;
}

int AForm::get_toSign() const
{
    return this->toSign;
}
int AForm::get_toExec() const
{
    return this->toExec;
}
void    AForm::set_signature(bool signature)
{
    this->signature = signature;
}

std::ostream&   operator<< ( std::ostream& ostrm, AForm& form)
{
    ostrm << "Form name : " << form.get_name() << std::endl;
	ostrm << "SignGrade : " << form.get_toSign() << std::endl;
	ostrm << "ExecGrade : " << form.get_toExec() << std::endl;
	ostrm << "isSigned : " <<  form.get_signature();
    return ostrm;
}

AForm::GradeTooHighException::GradeTooHighException() : std::runtime_error("GradeTooHigh."){}
AForm::GradeTooLowException::GradeTooLowException() : std::runtime_error("GradeTooLow."){}
AForm::FormAlreadySignedException::FormAlreadySignedException() : std::runtime_error("Form already signed."){}
AForm::FormNotSignedException::FormNotSignedException() : std::runtime_error("Form not signed, cannot execute."){}

