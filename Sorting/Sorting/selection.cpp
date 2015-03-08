/*

File: selection.cpp

Order based selection algorithms.

*/

/* The MIT License(MIT)

Copyright(c) 2015 andweller

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */


#include <cstdlib>
#include <ctime>
#include "selection.h"
#include "swap.h"



/* 
Returns the minimum value of the input array of the given length.
Assumes that the pointer points to a valid address.
Assumes that the length is valid.
*/
int minimum(int *input, int length) {
    int min = input[0];
    for (int index = 1; index < length; index++) {
        if (input[index] < min)
            min = input[index];
    }
    return min;
}



/*
Returns the maximum value of the input array of the given length.
Assumes that the pointer points to a valid address.
Assumes that the length is valid.
*/
int maximum(int *input, int length) {
    int max = input[0];
    for (int index = 1; index < length; index++) {
        if (input[index] > max)
            max = input[index];
    }
    return max;
}



int quick_select(int *input, int length, int order) {
    std::srand((unsigned int)time(NULL));
    return __q_select(input, length, order);
}




/*
Selects the element with statistical ordering of i in the given array.
The function is recursive.
*/
int __q_select(int *input, int length, int order) {
    if (length == 1)
        return input[0];

    int pivot_index = std::rand() % length;
    swap(input, length - 1, pivot_index);
    pivot_index = __q_select_partition(input, length);

    if (order == pivot_index + 1)
        return input[pivot_index];
    else if (order < pivot_index + 1)
        return __q_select(input, pivot_index, order);
    else
        return __q_select(input + pivot_index + 1, 
                            length - pivot_index - 1, order - pivot_index - 1);
}



/*
Partitions the data array using the last index as the pivot.
Important:  The last element of the array must be set in place
as the pivot element before this function is called!
*/
int __q_select_partition(int *input, int length) {
    int pivot = input[length - 1];

    int traverse = 0;
    int next_swap = 0;

    while (traverse < (length - 1)) {
        if (input[traverse] < pivot)
            swap(input, traverse, next_swap++);
        traverse++;
    }

    swap(input, length - 1, next_swap);
    return next_swap;
}