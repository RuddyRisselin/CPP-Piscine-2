#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    validateExecution(executor);

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing" << std::endl;
        return;
    }

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "       | |" << std::endl;
    file << "       | |" << std::endl;
    file << "      // \\\\" << std::endl;

    file.close();
    std::cout << "Shrubbery created in file: " << _target + "_shrubbery" << std::endl;
}
