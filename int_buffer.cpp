//int_buffer.cpp
#include "int_buffer.h"

int_buffer::int_buffer(size_t size) :
start(new int[size]), length(size) {
}

int_buffer::int_buffer(const int* source, size_t size) : start(new int[size]), length(size) {
    std::copy(source, source + length, begin());
}

int_buffer::int_buffer(const int_buffer& rhs) :
start(new int[rhs.size()]), length(rhs.size()) {
    std::copy(rhs.begin(), rhs.end(), begin());
}

int_buffer::int_buffer(int_buffer&& rhs)
: start(nullptr), length(0) {
    swap(rhs);
}

int_buffer & int_buffer::operator=(const int_buffer& rhs) {
    if (&rhs != this) {
        std::copy(rhs.begin(), rhs.end(), begin());
    }
    return *this;
}

int_buffer & int_buffer::operator=(int_buffer&& rhs) {
    if(&rhs != this){
        swap(rhs);
    }
    return *this;
}

size_t int_buffer::size() const {
    return length;
}

int* int_buffer::begin() {
    return this->start;
}

int* int_buffer::end() {
    return start + length;
}

const int* int_buffer::begin() const {
    return this->start;
}

const int* int_buffer::end() const {
    return start + length;
}

int_buffer::~int_buffer() {
    delete[] start;
}

void int_buffer::swap(int_buffer& temp) {
    std::swap(this->start, temp.start);
    std::swap(this->length, temp.length);
}