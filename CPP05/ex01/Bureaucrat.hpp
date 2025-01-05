#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;               

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif