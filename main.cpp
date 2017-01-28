
#include <cstdlib>
#include <iostream>
#include "int_sorted.h"

using namespace std;

size_t number;
const int* starter;
const int* ender;

int_sorted sort(const int* begin, const int* end){
    cout << "round: " << number << endl;
    cout <<  "Current begin: " <<*begin << endl;
    cout << "Current end: "<<*end << endl;
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
    number++;
    cout << "mid: " << *mid << endl;
    cout << "Currently in the array: "; 
    for(const int* i = starter; i != ender; i++){
        cout << *i << ", ";
    }
    cout << endl;
    int_sorted tempsort1 = sort(begin, mid);
    int_sorted tempsort2 = sort(mid, end);
    cout << "tempsort1 begin: "<< *(tempsort1.begin()) << endl;
    cout << "tempsort1 end: " << *(tempsort1.end()) << endl;
    cout << "tempsort1 size: " << tempsort1.size() << endl;
    for(const int* i = tempsort1.begin(); i != tempsort1.end(); i++){
        cout << *i << ", " << endl;
    }
    cout << "tempsort2 begin: "<< *(tempsort2.begin()) << endl;
    cout << "tempsort2 end: " << *(tempsort2.end()) << endl;
    cout << "tempsort2 size: " << tempsort2.size() << endl;
    for(const int* i = tempsort2.begin(); i != tempsort1.end(); i++){
        cout << *i << ", " << endl;
    }
    return tempsort1.merge(tempsort2);
}

void f(int_buffer buf) {
    number = 0;
    *buf.begin() = 1;
    for (int* i = buf.begin(); i != buf.end(); i++)
    {
        *(i + 1) = *i + 1;
    }
    const int temparray[4] = {3, 40, 20, 21};
    starter = temparray;
    ender = temparray + 4;
    cout << *ender << endl;
    int_sorted sortedlul = sort( temparray, (temparray + 4));
    for(const int* i = sortedlul.buffer->begin(); i < sortedlul.buffer->end(); i++){
        cout << *i << endl;
    }
 }

int main(int argc, char** argv) {
    f(int_buffer(10));
    return 0;
}

