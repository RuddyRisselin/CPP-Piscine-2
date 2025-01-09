#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
