/*

File: quicksort.cpp

Quick Sort Implementation

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
#include "quicksort.h"


template <typename T>
/*
Performs quicksort on the given array.
Sets the random seed if the pivot is selected randomly.
*/
void quick_sort(T *A, int length, QS_Pivot_Selection pivot_method) {
    if (pivot_method == Random)
        std::srand((unsigned int)time(NULL));

    __qs_sort(A, length, pivot_method);
}


template <typename T>
/*
Performs quicksort recursively by subsetting the array around a pivot
*/
void __qs_sort(T *A, int length, QS_Pivot_Selection pivot_method) {
    if (length > 1) {
        int pivot_index = __qs_get_pivot(length, pivot_method);
        swap(A, length - 1, pivot_index);
        pivot_index = __qs_partition(A, length);

        __qs_sort(A, pivot_index, pivot_method);
        __qs_sort(A + (pivot_index + 1), length - (pivot_index + 1), pivot_method);
    }
}


template <typename T>
/* 
Partitions the data array using the last index as the pivot.
Important:  The last element of the array must be set in place 
            as the pivot element before this function is called!
*/
int __qs_partition(T *A, int length) {
    T pivot = A[length - 1];

    int traverse = 0;
    int next_swap = 0;

    while (traverse < (length - 1)) {
        if (A[traverse] < pivot)
            swap(A, traverse, next_swap++);
        traverse++;
    }

    swap(A, length - 1, next_swap);
    return next_swap;
}


/*
Returns the pivot according to the given pivot selection method.
*/
int __qs_get_pivot(int length, QS_Pivot_Selection pivot_method) {
    int pivot;

    if (pivot_method == Random)
        pivot = std::rand() % length;
    else if (pivot_method == First)
        pivot = 0;
    else
        pivot = length - 1;

    return pivot;
}