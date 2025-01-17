#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperation(int a, int b, char op) const
{
    switch (op)
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) // Vérification de la division par zéro
                throw std::runtime_error("Error: division by zero.");
            return a / b;
        default:
            throw std::invalid_argument("Error: invalid operator.");
    }
}

int RPN::evaluate(const std::string& expression)
{
    std::stack<int> stack; // Pile pour stocker les opérandes
    std::istringstream tokens(expression); // Découper l'expression
    std::string token;

    while (tokens >> token) {
        if (token.length() == 1 && isOperator(token[0]))
		{
            // Si le token est un opérateur, appliquer l'opération
            if (stack.size() < 2)
                throw std::invalid_argument("Error: invalid expression.");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(applyOperation(a, b, token[0]));
        }
		else
		{
            // Sinon, le token doit être un entier
            int number;
            char* end; // Pour détecter les erreurs
            number = std::strtol(token.c_str(), &end, 10);

            // Vérifier si la conversion est complète
            if (*end != '\0') {
                throw std::invalid_argument("Error: invalid token.");
            }
            stack.push(number);
        }
    }
    // Après traitement, la pile doit contenir un seul élément
    if (stack.size() != 1)
        throw std::invalid_argument("Error: invalid expression.");
    return stack.top();
}
