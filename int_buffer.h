#include <cstdlib>

#ifndef INT_BUFFER_H
#define INT_BUFFER_H

class int_buffer {
    int* start;
    int* ending;
public:
    int_buffer() = delete;
    explicit int_buffer(size_t size);
    int_buffer(const int* source, size_t size);
    int_buffer(const int_buffer& rhs);
    int_buffer(int_buffer&& rhs);
    int_buffer & operator=(const int_buffer& rhs);
    int_buffer & operator=(int_buffer&& rhs);
    size_t size() const;
    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;
    ~int_buffer();
};
/*
class int_sorted{
public:
    int_buffer buffer;
    int_sorted(const int* source, size_t size);
    size_t size() const;
    int* insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;
};*/

#endif /* INT_BUFFER_H */

