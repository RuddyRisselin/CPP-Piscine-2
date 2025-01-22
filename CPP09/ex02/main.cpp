#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>
#include <cstdlib>
#include <climits>
#include <ctime>
#include "PmergeMe.hpp"

bool isValidInput(const std::string& input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        for (size_t i = 0; i < token.length(); ++i)
        {
            if (!std::isdigit(token[i]))
                return false;
        }

        char* end;
        long value = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0')
            return false;
        if (value < INT_MIN || value > INT_MAX)
            return false;
    }

    return true;
}

std::vector<int> parseInput(const std::string& input)
{
    std::istringstream iss(input);
    std::vector<int> numbers;
    int number;

    while (iss >> number)
        numbers.push_back(number);

    return numbers;
}

void displaySequence(const std::string& label, const std::vector<int>& numbers, size_t limit = 20)
{
    std::cout << label;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
        if (i == limit && numbers.size() > limit)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

void displaySequence(const std::string& label, const std::deque<int>& numbers, size_t limit = 20)
{
    std::cout << label;
    size_t count = 0;
    for (std::deque<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it, ++count)
    {
        std::cout << *it << " ";
        if (count == limit && numbers.size() > limit)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./program \"<numbers separated by spaces>\"" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::vector<int> numbers = parseInput(input);

    if (numbers.empty()) {
        std::cerr << "Error: invalid input. Please provide numbers separated by spaces." << std::endl;
        return 1;
    }

    // === Test avec std::vector ===
    PmergeMe vectorPmerge(numbers);

    displaySequence("Sequence (unsorted): ", numbers);

    clock_t start = clock();
    vectorPmerge.process();
    clock_t end = clock();

    displaySequence("Sequence (sorted): ", vectorPmerge.getLarge());

    double timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process with std::vector: " << timeVector << " us" << std::endl;

    // === Test avec std::deque ===
    PmergeMe dequePmerge(numbers);

    std::deque<int> dequeNumbers(numbers.begin(), numbers.end());

    start = clock();
    dequePmerge.processDeque();
    end = clock();


    double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process with std::deque: " << timeDeque << " us" << std::endl;

    return 0;
}