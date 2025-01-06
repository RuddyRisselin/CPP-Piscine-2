#include "Intern.hpp"
#include <iostream>

Intern::Intern() 
{}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern::~Intern() 
{}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    struct FormPair {
        std::string name;
        AForm *(Intern::*creator)(const std::string &);
    };

    FormPair formPairs[3] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formPairs[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return (const_cast<Intern *>(this)->*(formPairs[i].creator))(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" is not recognized!" << std::endl;
    return NULL;
}

AForm *Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
