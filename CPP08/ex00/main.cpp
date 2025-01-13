#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    try
	{
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Found: " << *easyfind(vec, 3) << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        std::cout << "Found: " << *easyfind(lst, 20) << std::endl;

        std::cout << "Found: " << *easyfind(vec, 100) << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
