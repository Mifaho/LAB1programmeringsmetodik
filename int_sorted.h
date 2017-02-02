//int_sorted.h
//v2
#ifndef INT_SOORTED_H
#define INT_SOORTED_H

#include "int_buffer.h"

class int_sorted{
public:
    int_buffer buffer;
    int_sorted();
    int_sorted(const int* source, size_t size);
    //int_sorted& operator=(const int_sorted& rhs);
    size_t size() const;
    bool checksorted();
    int* insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted selectionSort();
    int_sorted merge(const int_sorted& merge_with) const;
    //~int_sorted();
};

#endif /* INT_SOORTED_H */


