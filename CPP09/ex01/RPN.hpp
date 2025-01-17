#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cstdlib>

class RPN {
private:
    bool isOperator(char c) const;
    int applyOperation(int a, int b, char op) const;

public:
    RPN();                            
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);

};

#endif
