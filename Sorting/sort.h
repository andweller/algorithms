/*	sort.h
 *	A collection of sorting algorithms
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


#ifndef SORT_H_AW
#define SORT_H_AW

#include <cstring>

using std::memcpy;



template <typename T>
/* Swaps two elements x, y of array A
A - Pointer to the first element of the array
x - Index of the first value to swap
y - Index of the second value to swap */
inline void swap(T *A, int x, int y) {
    T temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}



template <typename T>
/* Sorts an array using insertion sort
Running Time: O(n^2)
  
first - Pointer to the first element of the array to sort
length - The length of the array */
void insertion_sort(T *first, int length);



template <typename T>
/* Sorts an array using bubble sort
   Running Time: O(n^2)
  
   A - Pointer to the first element of the array to sort
   length - The length of the array
 */
void bubble_sort(T *A, int length);



template <typename T>
/* Sorts an array using merge sort
   Running Time: O(n lg n)
  
   A - Pointer to the first element of the array to sort
   length - The length of the array
 */
void merge_sort(T *A, int length);


template <typename T>
/*  Sorts an integer array using merge sort and insertion sort
    for optimization with small subsets of the array
    Running Time: O(n lg n)

    A - Pointer to the first element of the integer array to sort
    length - The length of the integer array
*/
void merge_sort_insertion_optimization(T *A, int length);


template <typename T>
void __merge(T *A, int midpoint, int length);


#endif