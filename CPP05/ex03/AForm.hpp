#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _requiredToSign;
    const int _requiredToExecute;

protected:
    void validateExecution(const Bureaucrat &executor) const;

public:
    // Canonical form
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm();

    // Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getRequiredToSign() const;
    int getRequiredToExecute() const;

    // Functions
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
