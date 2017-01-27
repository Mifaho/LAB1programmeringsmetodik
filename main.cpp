
#include <cstdlib>
#include <iostream>
#include "int_sorted.h"

using namespace std;
/*
int_sorted sort(const int* begin, const int* end){
    if(begin == end) return int_sorted();
    if(begin == end - 1) return int_sorted(*begin, 1);
    ptrdiff_t half = (end-begin)/2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}*///Dåligt

void f(int_buffer buf) {
    *buf.begin() = 1;
    for (int* i = buf.begin(); i != buf.end(); i++)
    {
        *(i + 1) = *i + 1;
    }
    for (const int* i = buf.begin(); i != buf.end(); i++)
    {
        cout << *i << endl;
    }
 }

int main(int argc, char** argv) {
    int array[10];
    array[0] = 0;
    array[1] = 1;
    for(int i = 0; i < 10; i++){
        cout <<  i << " värde: " << array[i] << endl;
        if(array[i] == NULL){
            cout << i << " är null " << endl;
        }
    }
    f(int_buffer(10));
    return 0;
}

