//main.cpp
//v2
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
    for (int* i = buf.begin(); i + 1 != buf.end(); i++) {
        *(i + 1) = *i + 1;
    }
    cout << endl;
    for (const int* i = buf.begin(); i != buf.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
    for (int* i = buf.begin(); i != buf.end(); i++) {
        *(i) = rand() % 20 + 1;
        cout << *i << ", ";
    }
    int_sorted sorted;
    sort(buf.begin(), buf.end());
    cout << endl << "sorted using mergesort" << endl;
    for (const int* i = buf.begin(); i != buf.end(); i++) {
        cout << *i << ", ";
    }
    //sorted = sort(array, array + 6);
    //cout << endl << "over1" << endl;
}

void selectionSorting() {
    cout << "Function: selectionSort" << endl << endl;
    size_t elements = 400000;
    int array[400000];
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
    //int_sorted selectsorted = int_sorted(array, elements);
    if (selectsorted.checksorted()) {
        cout << "is sorted" << endl;
    }
    /*for (const int* i = selectsorted.begin(); i != selectsorted.end(); i++) {
        cout << *i << ", ";
    }*/
    cout << endl;
    int* ender = array + elements;
    clock_t t1 = clock();
    sort(array, ender);
    clock_t t2 = clock();
    double elapsed = double(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Time to sort with std sort: " << elapsed << " secs" << endl;
    //cout << "Sorted using default sort from std" << endl;
    /*for (int* i = pointer; i != pointer + selectsorted.size(); i++) {
        cout << *i << ", ";
    }*/
    cout << endl;
}

void mergeSorting() {
    cout << "Function: mergeSort" << endl;
    int_sorted sorted;
    for (int i = 0; i < 25; i++) {
        cout << *((sorted.insert(rand() % 25 + 1)) - 1) << ", ";
    }

    cout << endl << "sorted" << endl;
    sorted = sort(sorted.begin(), sorted.end());
    for (const int* i = sorted.buffer.begin(); i != sorted.buffer.end(); i++) {
        cout << *i << ", ";
    }
}

int main(int argc, char** argv) {
    f(int_buffer(10));
    srand(time(NULL));
    int_sorted tempsort;
    for (int i = 0; i < 200; i++) {
        tempsort.insert(rand() % 20 + 1);
    }
    cout << endl << "result after inserting 10 numbers" << endl;
    for (const int* i = tempsort.begin(); i != tempsort.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl << "over2" << endl;
    //cout << *(tempsort.buffer->begin()) << endl;
    //mergeSorting();
    selectionSorting();
    return 0;
}

