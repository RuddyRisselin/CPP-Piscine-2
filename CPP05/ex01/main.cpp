#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Lucas", 2);
        Bureaucrat b2("Yann", 150);

        Form f1("Form A", 1, 50);
        Form f2("Form B", 150, 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << std::endl;

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << std::endl;

        b1.signForm(f1); // b1 can't sign f1
        b2.signForm(f2); //b2 sign f2

    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}