#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm()
    : _name("Default Form"), _isSigned(false), _requiredToSign(150), _requiredToExecute(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _requiredToSign(signGrade), _requiredToExecute(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned), _requiredToSign(src._requiredToSign), _requiredToExecute(src._requiredToExecute) {}

AForm::~AForm()
{}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
	{
        _isSigned = rhs._isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getRequiredToSign() const {
    return _requiredToSign;
}

int AForm::getRequiredToExecute() const {
    return _requiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::validateExecution(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _requiredToExecute)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName()
       << " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Required Grade to Sign: " << form.getRequiredToSign()
       << ", Required Grade to Execute: " << form.getRequiredToExecute() << "]";
    return os;
}
