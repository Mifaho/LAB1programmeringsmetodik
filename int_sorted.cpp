#include "int_sorted.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <climits>

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
    pointer = buffer->begin();
    buffer = new int_buffer(pointer, (buffer->size() + 1));
    return buffer->end();
}

const int* int_sorted::begin() const {
    return (*buffer).begin();
}

const int* int_sorted::end() const {
    return (*buffer).end();
}

int_sorted int_sorted::selectionSort() {
    int_sorted tempsort(buffer->begin(), size());
    if (!checksorted()) {
        int* front = tempsort.buffer->begin();
        int* iter = front;
        int* min = front;
        int minValue = INT_MAX;
        while (front != tempsort.buffer->end()) {
            iter = front;
            iter++;
            while (iter != tempsort.buffer->end()) {
                if (minValue > *iter) {
                    minValue = *iter;
                    min = iter;
                }
                iter++;
            }
            if (min != front && minValue < *front) {
                std::swap(*min, *front);
            }
            front++;
            minValue = INT_MAX;
        }
    }
    return tempsort;
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    int* i = (*buffer).begin();
    int* j = merge_with.buffer->begin();
    int_sorted newsorted;
    while (i != (*buffer).end() && j != merge_with.buffer->end()) {
        if (*i > *j) {
            newsorted.insert(*j);
            j++;
        } else {
            newsorted.insert(*i);
            i++;
        }
    }
    while (i != (*buffer).end()) {
        newsorted.insert(*i);
        i++;
    }
    while (j != merge_with.buffer->end()) {
        newsorted.insert(*j);
        j++;
    }
    return newsorted;
}
