//int_sorted.h
#ifndef INT_SOORTED_H
#define INT_SOORTED_H

#include "int_buffer.h"

class int_sorted{
public:
    int_buffer* buffer;
    int_sorted();
    int_sorted(const int* source, size_t size);
    size_t size() const;
    bool checksorted();
    int* insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted selectionSort();
    int_sorted merge(const int_sorted& merge_with) const;
};

#endif /* INT_SOORTED_H */


