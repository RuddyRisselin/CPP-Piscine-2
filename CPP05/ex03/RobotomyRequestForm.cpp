#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs)
	{
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}


void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    validateExecution(executor);

    std::cout << "Bzzzzzz... Vrrrrrr... *drilling noises*" << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}