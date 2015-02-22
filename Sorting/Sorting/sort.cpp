/*	sort.cpp
 *  A collection of sorting algorithms
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

#include "sort.h"


template <typename T>
/* Sorts an array of a given length using insertion sort */
void insertion_sort(T *first, int length) {
    for (int outerIndex = 1; outerIndex < length; outerIndex++) {
        T element = first[outerIndex];
        int innerIndex = outerIndex - 1;

        while (innerIndex >= 0 && first[innerIndex] > element) {
	        first[innerIndex + 1] = first[innerIndex];
	        innerIndex--;
        }
        
        first[innerIndex + 1] = element;
    }
}


template <typename T>
/* Sorts an array of a given length using bubble sort */
void bubble_sort(T *A, int length) {
    for (int outerIndex = 0; outerIndex < length; outerIndex++) {
        for (int innerIndex = length - 1; innerIndex > outerIndex; innerIndex--) {
            if (A[innerIndex] < A[innerIndex - 1])
                swap(A, innerIndex, innerIndex - 1);
        }
    }
}



template <typename T>
/* Sorts an array of a given length using merge sort */
void merge_sort(T *A, int length) {
    if (length > 1) {
        int midpoint = length / 2;
        merge_sort(A, midpoint);
        merge_sort(A + midpoint, length - midpoint);
        __merge(A, midpoint, length);
    }
}


template <typename T>
/*  Sorts an array of a given length using merge sort 
    and insertion sort with small subsets (i.e. k=7) of the array
    which decreases the average running time and saves expensive
    allocation/deallocation calls for dynamic memory. */
void merge_sort_insertion_optimization(T *A, int length) {
    // Length at which to switch search algorithm
    int const k = 7;

    if (length > 1) {
        if (length > k) {
            // Perform merge sort
            int midpoint = length / 2;
            merge_sort_insertion_optimization(A, midpoint);
            merge_sort_insertion_optimization(A + midpoint, length - midpoint);
            __merge(A, midpoint, length);
        }
        else {
            // Perform insertion sort
            insertion_sort(A, length);
        }
    }
}


template <typename T>
/* Merge two sorted subarrays together into a sorted array 
 * Allocates dynamic memory in the order of the length */
void __merge(T *A, int midpoint, int length) {
    T *temp = new T[length];
    int firstIndex = 0;
    int secondIndex = midpoint;

    for (int i = 0; i < length; i++)
    {
        // Handle cases where subarrays are done merging
        // Then select the minimum of the next two elements
        if (firstIndex >= midpoint)
            temp[i] = A[secondIndex++];
        else if (secondIndex >= length)
            temp[i] = A[firstIndex++];
        else if (A[firstIndex] < A[secondIndex])
            temp[i] = A[firstIndex++];
        else
            temp[i] = A[secondIndex++];
    }

    memcpy(A, temp, sizeof(T)*length);
    delete[] temp;
}