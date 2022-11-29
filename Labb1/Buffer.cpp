//Lab 1, DT079G
//Jonathan Shahi
//28/11/22
//implementation of int_buffer

#include "Buffer.h"
#include <algorithm>
#include <iostream>

int_buffer::int_buffer(size_t size) : first(new int[size]), last(first + size) {
    //std::cerr << "constructor" << std::endl;
}

int_buffer::int_buffer(const int* source, size_t size): int_buffer(size) {
    std::copy(source, source + size, first);
}

int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.first, rhs.size()) {}

int_buffer::int_buffer(int_buffer&& rhs) : first(nullptr), last(nullptr) { 
    swap(rhs); 
}

void int_buffer::swap(int_buffer& other) {
    std::swap(first, other.first);
    std::swap(last, other.last);
}

int_buffer& int_buffer::operator =(const int_buffer& rhs) {
    int_buffer copy(rhs);
    swap(copy);
    return *this;
}

int_buffer& int_buffer::operator =(int_buffer&& rhs) {
    swap(rhs);
    return *this;
}

int& int_buffer::operator [](size_t index) {
    return *(first + index);
}

const int& int_buffer::operator [](size_t index) const {
    return *(first + index);
}

size_t int_buffer::size() const {
    return std::distance(first, last);
}

int* int_buffer::begin() {
    //std::cerr << "first" << std::endl;

    return first;
}
int* int_buffer::end() {
    //std::cerr << "last" << std::endl;

    return last;
}

const int* int_buffer::begin() const {
    return first;
}
const int* int_buffer::end() const {
    return last;
}

int_buffer::~int_buffer() {
    //std::cerr << "Destructor" << std::endl;
    delete[] first;
}