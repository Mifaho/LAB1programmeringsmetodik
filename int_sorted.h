/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   int_soorted.h
 * Author: stefa_000
 *
 * Created on den 25 januari 2017, 16:48
 */

#ifndef INT_SOORTED_H
#define INT_SOORTED_H

#include "int_buffer.h"
#include <cstdlib>

class int_sorted{
public:
    int_buffer buffer;
    int_sorted(const int* source, size_t size);
    size_t size() const;
    int* insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;
};

#endif /* INT_SOORTED_H */

