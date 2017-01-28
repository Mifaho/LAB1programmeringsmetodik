#include "int_sorted.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

int_sorted::int_sorted() {
    buffer = new int_buffer();
}

int_sorted::int_sorted(const int* source, size_t size) {//Varför denna ej fungera?
    this->buffer = new int_buffer(source, size);
}

size_t int_sorted::size() const {
    (*buffer).size();
}

bool int_sorted::checksorted() {
    size_t tempsize = (*buffer).size();
    for (int* i = (*buffer).begin(); i < ((*buffer).begin() + tempsize - 1); i++) {
        if (*i > *(i + 1)) {
            return false;
        }
    }
    return true;
}
/*:
buffer(new int_buffer(source, size))*/

//size_t int_sorted::size(){
//return buffer.size();
//}

int* int_sorted::insert(int value) {
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

const int* int_sorted::begin() const {
    return (*buffer).begin();
}

const int* int_sorted::end() const {
    return (*buffer).end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    //std::cout << "merging" << std::endl;
    //std::cout << "merge_with.buffer->begin() " << *(merge_with.buffer->begin()) << std::endl;
    //std::cout << "(*buffer).begin() " << *((*buffer).begin()) << std::endl;
    size_t newsize = buffer->size() + merge_with.buffer->size();
    //std::cout << "newsize: " << newsize << std::endl;
    int* i = (*buffer).begin();
    int* j = merge_with.buffer->begin();
    int* newarray = new int[newsize];
    size_t count = 0;
    while (i != (*buffer).end() && j != merge_with.buffer->end()) {
        if (*i > *j) {
            newarray[count] = *j;
            //std::cout << "j: " << *j << std::endl;
            j++;
            count++;
        } else {
            newarray[count] = *i;
            //std::cout << "i: " << *i << std::endl;
            i++;
            count++;
        }
    }
    while (i != (*buffer).end()) {
        //std::cout << "i: " << *i << std::endl;
        newarray[count] = *i;
        i++;
        count++;
    }
    while (j != merge_with.buffer->end()) {
        //std::cout << "j: " << *j << std::endl;
        newarray[count] = *j;
        j++;
        count++;
    }
    /*size_t newsize = buffer->size() + merge_with.buffer->size();
    int* newarray = new int[newsize];
    size_t count = 0;
    for(int* i = (*buffer).begin(); i != (*buffer).end(); i++){
        newarray[count] = *i;
        count++;
    }
    for(int* i = merge_with.buffer->begin(); i != merge_with.buffer->end(); i++){
        newarray[count] = *i;
        count++;
    }*/
    //this->buffer = new int_buffer(buffer->begin(), newsize);
    int_sorted* newsorted = new int_sorted(newarray, newsize);
    return *newsorted;
}
