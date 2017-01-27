#include "int_sorted.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size):buffer(new int_buffer(source, size)){//Varför denna ej fungera?
}


/*:
buffer(new int_buffer(source, size))*/ 

//size_t int_sorted::size(){
    //return buffer.size();
//}

int* int_sorted::insert(int value){
    /*size_t count = 1;
    int* i = buffer.begin();
    for(; i != buffer.end() && i != nullptr; i++){
        count++;
    }
    if(buffer.size() != count){
        *i = value;
    }
    else{
        buffer = new int_buffer(buffer.begin(), buffer.size() + 10);
    }*/
    /*int_buffer tempbuffer(buffer.begin(), buffer.size() + 1);
    buffer = tempbuffer;
    *(buffer.end()) = value;
    return buffer.end();*/
}

const int* int_sorted::begin() const{
    //return buffer.begin();
}

const int* int_sorted::end() const{
    //return buffer.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const{
    /*for(const int* i = merge_with.begin(); i != merge_with.end(); i++){
        insert(*i);
    }*/
    return *this;
}
