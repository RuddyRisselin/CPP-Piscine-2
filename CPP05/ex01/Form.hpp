#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _requiredToSign;
    const int _requiredToExecute;

public:
	//cannonical form
    Form();
    Form(const std::string &name, int signGrade, int execGrade);
    Form(const Form &src);
	Form &operator=(const Form &rhs);
    ~Form();

    // Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getRequiredToSign() const;
    int getRequiredToExecute() const;

    // Functions
    void beSigned(Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
