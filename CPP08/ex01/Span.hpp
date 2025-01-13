#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int maxSize);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

	template <typename InputIterator>
	void Span::addRange(InputIterator begin, InputIterator end)
	{
    	while (begin != end)
		{
    	    addNumber(*begin);
        	++begin;
    	}
	}
};

#endif
