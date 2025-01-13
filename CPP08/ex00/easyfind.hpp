#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator> 
#include <exception>
#include <iostream>

class ElementNotFoundException : public std::exception {
public:
    const char* what() const throw()
	{
        return "Element not found in the container.";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ElementNotFoundException();
    return it;
}

#endif