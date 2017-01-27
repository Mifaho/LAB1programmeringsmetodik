/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "int_buffer.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>


int_buffer::int_buffer(size_t size) :
start(new int[size]), ending(start + size) {
    for(int i = 0; i < size; i++){
        //start[i] = nullptr;
    }
}

int_buffer::int_buffer(const int* source, size_t size) {
    int tempArray [size];
    for (int i = 0; source != nullptr && i < size; i++) {
        tempArray[i] = *source;
        ++source;
    }
    this->start = tempArray;
    this->ending = &tempArray[size - 1];
    //this->current_size = size;
}

int_buffer::int_buffer(const int_buffer& rhs) :
start(new int[rhs.size()]) {
    std::copy(rhs.begin(), rhs.end(), begin());
    ending = start + rhs.size();
}
    /*size_t tempsize = rhs.size();
    int tempArray [tempsize];
    const int* tempConstArray = rhs.begin();
    for (int i = 0; i < tempsize; i++) {
        tempArray[i] = tempConstArray[i];
    }
    this->start = tempArray;
    this->ending = &tempArray[tempsize - 1];*/
    //this->current_size = rhs.size();

//}

int_buffer::int_buffer(int_buffer&& rhs):
start(std::move(rhs.start)), ending(std::move(rhs.ending)) {
}

int_buffer & int_buffer::operator=(const int_buffer& rhs) {
    start = new int[rhs.size()];
    std::copy(rhs.begin(), rhs.end(), begin());
    ending = start + rhs.size();
    /*int tempArray [rhs.size()];
    const int* tempConstArray = rhs.begin();
    for (int i = 0; i < rhs.size(); i++) {
        tempArray[i] = tempConstArray[i];
    }
    this->start = tempArray;
    this->ending = &tempArray[rhs.size() - 1];*/
    return *this;
    //this->current_size = rhs.size();

}

int_buffer & int_buffer::operator=(int_buffer&& rhs){
    start = std::move(rhs.start);
    ending = std::move(rhs.ending);
    return *this;
}

size_t int_buffer::size() const {
    size_t counter = 1;
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