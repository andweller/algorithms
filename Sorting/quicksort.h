/*	

File: quicksort.h

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


#ifndef QSORT_H_AW
#define QSORT_H_AW

#include "swap.h"


enum QS_Pivot_Selection { Random, First, Last };


template <typename T>
/*
Performs quicksort on the given array.
Running Time: O(n lg n)

A - The array to be sorted
length - The length of the array to be sorted
pivot_method - Method to use to sort the array, default is random
*/
void quick_sort(T *A, int length, QS_Pivot_Selection pivot_method = Random);



template <typename T>
void __qs_sort(T *A, int length, QS_Pivot_Selection pivot_method);

int __qs_get_pivot(int length, QS_Pivot_Selection pivot_method);

template <typename T>
int __qs_partition(T *A, int length);


#endif