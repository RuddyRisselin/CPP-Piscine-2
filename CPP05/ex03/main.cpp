#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat lucas("Lucas", 50);
        Bureaucrat yann("Yann", 20);
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

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        yann.signForm(robotomy);
        yann.executeForm(robotomy);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);

        Intern intern;
        std::cout << "\n--- Testing Intern ---" << std::endl;

        AForm *form1 = intern.makeForm("shrubbery creation", "Home");
        if (form1)
        {
            lucas.signForm(*form1);
            lucas.executeForm(*form1);
            delete form1;
        }

        AForm *form2 = intern.makeForm("robotomy request", "Robot");
        if (form2)
        {
            yann.signForm(*form2);
            yann.executeForm(*form2);
            delete form2;
        }

        AForm *form3 = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
        if (form3)
        {
            president.signForm(*form3);
            president.executeForm(*form3);
            delete form3;
        }

        AForm *form4 = intern.makeForm("unknown form", "Test Target");
        if (form4)
            delete form4;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
