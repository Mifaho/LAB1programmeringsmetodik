/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "int_buffer.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

int_buffer::int_buffer() : start(new int[1]), ending(start) {
}

int_buffer::int_buffer(size_t size) :
start(new int[size]), ending(start + size) {
}

int_buffer::int_buffer(const int* source, size_t size) {
    start = new int[size];
    
    const int* tempend = source + size;
    while (source != tempend) {
        *start = *source;
        source++;
        start++;
    }
    ending = start;
    start = ending - size;
}

int_buffer::int_buffer(const int_buffer& rhs) :
start(new int[rhs.size()]) {
    std::copy(rhs.begin(), rhs.end(), begin());
    ending = start + rhs.size();
}

int_buffer::int_buffer(int_buffer&& rhs) :
start(std::move(rhs.start)), ending(std::move(rhs.ending)) {
}

int_buffer & int_buffer::operator=(const int_buffer& rhs) {
    start = new int[rhs.size()];
    std::copy(rhs.begin(), rhs.end(), begin());
    ending = start + rhs.size();
    return *this;
}

int_buffer & int_buffer::operator=(int_buffer&& rhs) {
    start = std::move(rhs.start);
    ending = std::move(rhs.ending);
    return *this;
}

size_t int_buffer::size() const {
    if (begin() == end()) {
        return 0;
    }
    size_t counter = 0;
    for (const int* i = begin(); i != end(); i++) {
        ++counter;
    }
    return counter;
}

int* int_buffer::begin() {
    return this->start;
}

int* int_buffer::end() {
    //return &(arr[size() - 1]);
    return this->ending;
}

const int* int_buffer::begin() const {
    return this->start;
}

const int* int_buffer::end() const {
    //return &(arr[size() - 1]);
    return this->ending;
}

int_buffer::~int_buffer() {
    delete start;
    delete[] start;
}