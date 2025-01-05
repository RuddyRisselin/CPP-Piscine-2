#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat b1("Lucas", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b2("Ruddy", 151);
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b3("Yann", 150);
        std::cout << b3 << std::endl;
        b3.decrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}