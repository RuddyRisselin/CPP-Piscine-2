#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <typeinfo>

void identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& ref)
{
    try
    {
        (void)dynamic_cast<A&>(ref);
        std::cout << "Type: A" << std::endl;
    }
    catch (std::bad_cast&)
    {
        try
        {
            (void)dynamic_cast<B&>(ref);
            std::cout << "Type: B" << std::endl;
        }
        catch (std::bad_cast&)
        {
            try
            {
                (void)dynamic_cast<C&>(ref);
                std::cout << "Type: C" << std::endl;
            }
            catch (std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main()
{
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "Identification via pointeur:" << std::endl;
    identify(a);
    identify(b);
    identify(c);

    std::cout << "\nIdentification via référence:" << std::endl;
    identify(*a);
    identify(*b);
    identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}

