#include "int_sorted.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

int_sorted::int_sorted() {
    buffer = new int_buffer();
}

int_sorted::int_sorted(const int* source, size_t size) {
    this->buffer = new int_buffer(source, size);

}

size_t int_sorted::size() const {
    return (*buffer).size();
}

bool int_sorted::checksorted() {
    size_t tempsize = (*buffer).size();
    for (int* i = (*buffer).begin(); i < ((*buffer).begin() + tempsize - 1); i++) {
        if (*i > *(i + 1)) {
            return false;
        }
    }
    return true;
}

int* int_sorted::insert(int value) {
    int* pointer = buffer->end();
    *pointer = value;
    pointer = pointer - buffer->size();
    buffer = new int_buffer(pointer, (buffer->size() + 1));
    return buffer->end();
}

const int* int_sorted::begin() const {
    return (*buffer).begin();
}

const int* int_sorted::end() const {
    return (*buffer).end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    size_t newsize = buffer->size() + merge_with.buffer->size();
    int* i = (*buffer).begin();
    int* j = merge_with.buffer->begin();
    int* newarray = new int[newsize];
    size_t count = 0;
    while (i != (*buffer).end() && j != merge_with.buffer->end()) {
        if (*i > *j) {
            newarray[count] = *j;
            j++;
        } else {
            newarray[count] = *i;
            i++;
        }
        count++;
    }
    while (i != (*buffer).end()) {
        newarray[count] = *i;
        i++;
        count++;
    }
    while (j != merge_with.buffer->end()) {
        newarray[count] = *j;
        j++;
        count++;
    }
    int_sorted* newsorted = new int_sorted(newarray, newsize);
    return *newsorted;
}
