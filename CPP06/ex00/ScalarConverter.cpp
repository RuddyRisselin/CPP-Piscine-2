#include "ScalarConverter.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& /*other*/)
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& /*other*/)
{
    return *this;
}

char ScalarConverter::convertToChar(int intValue, float floatValue, bool isFloat)
{
    if (isFloat)
        return (floatValue >= std::numeric_limits<char>::min() && floatValue <= std::numeric_limits<char>::max()) ? static_cast<char>(floatValue) : 0;
    return (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) ? static_cast<char>(intValue) : 0;
}

int ScalarConverter::convertToInt(const std::string& literal, bool isFloat, bool isDouble)
{
    if (isFloat || isDouble)
    {
        double value = std::strtod(literal.c_str(), NULL);
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value))
            return 0;
        return static_cast<int>(value);
    }
    return std::atoi(literal.c_str());
}

float ScalarConverter::convertToFloat(const std::string& literal, bool isPseudoFloat)
{
    if (isPseudoFloat)
    {
        if (literal == "nanf")
			return std::numeric_limits<float>::quiet_NaN();
        if (literal == "+inff")
			return std::numeric_limits<float>::infinity();
        if (literal == "-inff")
			return -std::numeric_limits<float>::infinity();
    }
    return std::strtof(literal.c_str(), NULL);
}

double ScalarConverter::convertToDouble(const std::string& literal, bool isPseudoDouble)
{
    if (isPseudoDouble)
    {
        if (literal == "nan")
			return std::numeric_limits<double>::quiet_NaN();
        if (literal == "+inf")
			return std::numeric_limits<double>::infinity();
        if (literal == "-inf")
			return -std::numeric_limits<double>::infinity();
    }
    return std::strtod(literal.c_str(), NULL);
}

void ScalarConverter::printChar(char charValue, bool isPseudoFloat, bool isPseudoDouble, bool isChar)
{
    std::cout << "char: ";
    if (isPseudoFloat || isPseudoDouble || charValue == 0)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(charValue))
        std::cout << "'" << charValue << "'" << std::endl;
    else if (isChar)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printInt(int intValue, bool isPseudoFloat, bool isPseudoDouble, bool isInt)
{
    std::cout << "int: ";
    if (isPseudoFloat || isPseudoDouble)
        std::cout << "impossible" << std::endl;
    else if (isInt)
        std::cout << intValue << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printFloat(float floatValue, bool isFloat)
{
    std::cout << "float: ";
    if (isFloat)
    {
        std::cout << floatValue;
        if (floatValue == static_cast<int>(floatValue))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printDouble(double doubleValue, bool isDouble)
{
    std::cout << "double: ";
    if (isDouble)
    {
        std::cout << doubleValue;
        if (doubleValue == static_cast<int>(doubleValue))
            std::cout << ".0";
        std::cout << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    bool isPseudoFloat = (literal == "nanf" || literal == "+inff" || literal == "-inff");
    bool isPseudoDouble = (literal == "nan" || literal == "+inf" || literal == "-inf");

    bool isChar = literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
    bool isInt = literal.find_first_not_of("-0123456789") == std::string::npos && !isChar;
    bool isFloat = (literal.find('f') != std::string::npos && literal.find_first_not_of("-0123456789.f") == std::string::npos) || isPseudoFloat;
    bool isDouble = (literal.find('.') != std::string::npos && !isFloat) || isPseudoDouble || literal == "0";

    int intValue = convertToInt(literal, isFloat, isDouble);
    float floatValue = convertToFloat(literal, isPseudoFloat);
    double doubleValue = convertToDouble(literal, isPseudoDouble);
    char charValue = convertToChar(intValue, floatValue, isFloat);

    printChar(charValue, isPseudoFloat, isPseudoDouble, isChar);
    printInt(intValue, isPseudoFloat, isPseudoDouble, isInt);
    printFloat(floatValue, isFloat || isInt || isDouble);
    printDouble(doubleValue, isDouble || isInt || isFloat);
}
