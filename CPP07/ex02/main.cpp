#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); ++i)
            intArray[i] = i * 10;

        std::cout << "intArray: ";
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        std::cout << "Trying to access out-of-bounds element..." << std::endl;
        std::cout << intArray[10] << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }
    try
	{
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "42";

        std::cout << "strArray: ";
        for (size_t i = 0; i < strArray.size(); ++i)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
