#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("Default"), _isSigned(false), _requiredToSign(150), _requiredToExecute(150) {}

Form::Form(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _requiredToSign(signGrade), _requiredToExecute(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned), _requiredToSign(src._requiredToSign), _requiredToExecute(src._requiredToExecute) {}

Form::~Form() {}

const std::string &Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getRequiredToSign() const {
    return _requiredToSign;
}

int Form::getRequiredToExecute() const {
    return _requiredToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName()
       << " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Required Grade to Sign: " << form.getRequiredToSign()
       << ", Required Grade to Execute: " << form.getRequiredToExecute() << "]";
    return os;
}

