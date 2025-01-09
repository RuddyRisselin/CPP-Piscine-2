#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* data;
    size_t arraySize;

public:
    Array() : data(NULL), arraySize(0) {}
    Array(unsigned int n) : data(new T[n]()), arraySize(n) {}

    Array(const Array& other) : data(NULL), arraySize(0) {
        *this = other;
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& other) {
        if (this != &other)
		{
            delete[] data;
            arraySize = other.arraySize;
            data = new T[arraySize];
            for (size_t i = 0; i < arraySize; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= arraySize)
            throw OutOfBoundsException();
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= arraySize)
            throw OutOfBoundsException();
        return data[index];
    }

    size_t size() const {
        return arraySize;
    }

    class OutOfBoundsException : public std::exception {
    public:
        const char* what() const throw() {
            return "Index out of bounds!";
        }
    };
};

#endif
