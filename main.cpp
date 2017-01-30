
#include <cstdlib>
#include <iostream>
#include "int_sorted.h"

using namespace std;

//size_t number;
//const int* starter;
//const int* ender;

int_sorted sort(const int* begin, const int* end) {
    if (begin == end) {
        return int_sorted();
    }
    if (begin == end - 1) {
        return int_sorted(begin, 1);
    }
    ptrdiff_t half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

void f(int_buffer buf) {
    *buf.begin() = 1;
    for (int* i = buf.begin(); i != buf.end(); i++) {
        *(i + 1) = *i + 1;
    }

    size_t length = 8;
    const int temparray[] = {3, 40, 20, 21, 13, 14, 22, 1};
    int_sorted empty;
    empty.insert(7);
    empty.insert(4);
    for (const int* i = empty.buffer->begin(); i < empty.buffer->end(); i++) {
        cout << *i << endl;
    }
    int_sorted sorted = sort(temparray, (temparray + length));
    cout << "final result" << endl;
    for (const int* i = sorted.buffer->begin(); i < sorted.buffer->end(); i++) {
        cout << *i << endl;
    }
    cout << "sorted" << endl;
    cout << "Adding 5 and 6" << endl;
    sorted.insert(5);
    sorted.insert(6);
    for (const int* i = sorted.buffer->begin(); i < sorted.buffer->end(); i++) {
        cout << *i << endl;
    }
}

int main(int argc, char** argv) {
    f(int_buffer(10));
    return 0;
}

