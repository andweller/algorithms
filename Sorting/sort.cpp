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


/* Swaps two elements x, y of array A */
inline void swap(int *A, int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}


/* Sorts an integer array of a given length using insertion sort
 * The function is written in the style of ANSI C */
void insertion_sort(int *first, int length) {
	int outerIndex, innerIndex, element;

	for (outerIndex = 1; outerIndex < length; outerIndex++) {
		element = first[outerIndex];

		innerIndex = outerIndex - 1;
		while (innerIndex >= 0 && first[innerIndex] > element) {
			first[innerIndex + 1] = first[innerIndex];
			innerIndex--;
		}

		first[innerIndex + 1] = element;
	}
}


/* Sorts an integer array of a given length using bubble sort */
void bubble_sort(int *A, int length) {
    for (int outerIndex = 0; outerIndex < length; outerIndex++) {
        for (int innerIndex = length - 1; innerIndex > outerIndex; innerIndex--) {
            if (A[innerIndex] < A[innerIndex - 1])
                swap(A, innerIndex, innerIndex - 1);
        }
    }
}



/* Sorts an integer array of a given length using merge sort */
void merge_sort(int *A, int length) {
    if (length > 1) {
        int midpoint = length / 2;
        merge_sort(A, midpoint);
        merge_sort(A + midpoint, length - midpoint);
        __merge(A, midpoint, length);
    }
}


/*  Sorts an integer array of a given length using merge sort 
    and insertion sort with small subsets (i.e. k=7) of the array
    which decreases the average running time and saves expensive
    allocation/deallocation calls for dynamic memory. */
void merge_sort_insertion_optimization(int *A, int length) {
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


/* Merge two sorted subarrays together into a sorted array 
 * Allocates dynamic memory in the order of the length */
void __merge(int *A, int midpoint, int length) {
    int *temp = new int[length];
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

    memcpy(A, temp, sizeof(int)*length);
    delete[] temp;
}