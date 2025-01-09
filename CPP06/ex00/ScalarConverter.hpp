#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void convert(const std::string& literal);

private:
    static char convertToChar(int intValue, float floatValue, bool isFloat);
    static int convertToInt(const std::string& literal, bool isFloat, bool isDouble);
    static float convertToFloat(const std::string& literal, bool isPseudoFloat);
    static double convertToDouble(const std::string& literal, bool isPseudoDouble);

    static void printChar(char charValue, bool isPseudoFloat, bool isPseudoDouble, bool isChar);
    static void printInt(int intValue, bool isPseudoFloat, bool isPseudoDouble, bool isInt);
    static void printFloat(float floatValue, bool isFloat);
    static void printDouble(double doubleValue, bool isDouble);
};

#endif
