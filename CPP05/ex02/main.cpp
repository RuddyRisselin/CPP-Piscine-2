#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat lucas("Lucas", 50);
        Bureaucrat Yann("Yann", 20);
        Bureaucrat president("President", 1);

        ShrubberyCreationForm shrubbery("Form 1");
        RobotomyRequestForm robotomy("Form 2");
        PresidentialPardonForm pardon("Form 3");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        lucas.signForm(shrubbery);
        lucas.executeForm(shrubbery);
        std::cout << std::endl;

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        Yann.signForm(robotomy);
        Yann.executeForm(robotomy);
        std::cout << std::endl;

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
        std::cout << std::endl;

        std::cout << "\n--- Testing Errors ---" << std::endl;
        ShrubberyCreationForm errorForm("RestrictedZone");
        lucas.executeForm(errorForm);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
