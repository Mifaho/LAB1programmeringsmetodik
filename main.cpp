//main.cpp
#include "int_sorted.h"

using namespace std;

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

void selectionSorting() {
    cout << "Function: selectionSort" << endl << endl;
    srand(time(NULL));
    size_t elements = 40000;
    int array[40000];
    for (size_t i = 0; i < elements; i++) {
        array[i] = (rand() % elements + 1);
    }
    cout << endl;
    int_sorted sorted(array, elements);
    cout << endl;
    if (!sorted.checksorted()) {
        cout << "unsorted" << endl;
    }
    cout << endl << "Selectionsort" << endl;
    int_sorted selectsorted = sorted.selectionSort();
}

void mergeSorting() {
    cout << "Function: mergeSort" << endl;
    int_sorted sorted;
    for (int i = 0; i < 25; i++) {
        cout << *((sorted.insert(rand() % 25 + 1)) - 1) << ", ";
    }
    cout << endl << "sorted" << endl;
    sorted = sort(sorted.begin(), sorted.end());
    for (const int* i = sorted.buffer->begin(); i < sorted.buffer->end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;

}

int main(int argc, char** argv) {
    f(int_buffer(10));
    cout << endl;
    mergeSorting();
    selectionSorting();
    return 0;
}

