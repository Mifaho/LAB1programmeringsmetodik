
#include <cstdlib>
#include <iostream>
#include "int_sorted.h"
#include <time.h> 

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
    cout << "Function: f" << endl;
    *buf.begin() = 1;
    for (int* i = buf.begin(); i != buf.end(); i++) {
        *(i + 1) = *i + 1;
    }
    for (const int* i = buf.begin(); i != buf.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
}

void commenceSorting() {
    cout << "Function: commenceSorting" << endl << endl;
    srand(time(NULL));
    const int* pointer;
    int_sorted sorted;

    for (int i = 0; i < 25; i++) {
        cout << *((sorted.insert(rand() % 25 + 1)) - 1) << ", ";
    }
    cout << endl;
    if (!sorted.checksorted()) {
        cout << "unsorted" << endl;
    }
    cout << endl << "Selectionsort" << endl;
    int_sorted selectsorted = sorted.selectionSort();
    for (const int* i = selectsorted.buffer->begin(); i < selectsorted.buffer->end(); i++) {
        cout << *i << ", ";
    }
    cout << endl << "Mergesort" << endl;
    sorted = sort(sorted.begin(), sorted.end());
    for (const int* i = sorted.buffer->begin(); i < sorted.buffer->end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
    if (sorted.checksorted()) {
        cout << "sorted" << endl;
    }
}

int main(int argc, char** argv) {
    f(int_buffer(10));
    cout << endl;
    commenceSorting();
    return 0;
}

