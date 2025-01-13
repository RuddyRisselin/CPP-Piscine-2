#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
	{
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full.");
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough elements to calculate a span.");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to calculate a span.");
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}
