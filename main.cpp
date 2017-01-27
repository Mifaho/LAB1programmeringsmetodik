
#include <cstdlib>
#include <iostream>
#include "int_sorted.h"

using namespace std;

size_t number;
const int* starter;
const int* ender;

int_sorted sort(const int* begin, const int* end){
    if(begin == end){
        cout << "no elements?" << endl;
        return int_sorted();
    }
    if(begin == end - 1){
        cout << "one element?" << endl;
        return int_sorted(begin, 1);
    }
    ptrdiff_t half = (end-begin)/2;
    const int* mid = begin + half;
    cout << "round: " << number << endl;
    number++;
    cout << "begin: " << *begin << endl;
    cout << "mid: " << *mid << endl;
    cout << "end: " << *end << endl;
    cout << "Currently in the array: "; 
    for(const int* i = starter; i != ender; i++){
        cout << *i << ", ";
    }
    cout << endl;
    return sort(begin, mid).merge(sort(mid, end));
}

void f(int_buffer buf) {
    number = 0;
    *buf.begin() = 1;
    for (int* i = buf.begin(); i != buf.end(); i++)
    {
        *(i + 1) = *i + 1;
    }
    const int temparray[10] = {3, 40, 20, 21 ,10 , 11, 23, 22, 12, 33};
    starter = temparray;
    ender = temparray + 10;
    cout << *ender << endl;
    sort( temparray, (temparray + 10));
 }

int main(int argc, char** argv) {
    f(int_buffer(10));
    return 0;
}

