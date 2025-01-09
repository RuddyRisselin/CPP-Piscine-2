#include <iostream>
#include "iter.hpp"

void printInt(int& x) {
    std::cout << x << " ";
}

void incrementInt(int& x) {
    x += 1;
}

void printString(std::string& str) {
    std::cout << str << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    iter(intArray, intArraySize, incrementInt);
    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, printInt);
    std::cout << std::endl;

    std::string strArray[] = {"hello", "world", "42"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original strArray: ";
    iter(strArray, strArraySize, printString);
    std::cout << std::endl;

    return 0;
}
