
#include <cstdlib>
#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"

using namespace std;

int_sorted sort(const int* begin, const int* end){
    if(begin == end) return int_sorted();
    if(begin == end - 1) return int_sorted(*begin, 1);
    ptrdiff_t half = (end-begin)/2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}//Dåligt

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
    f(int_buffer(10));
    return 0;
}
