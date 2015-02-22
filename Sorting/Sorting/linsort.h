/*

File: linsort.h

Non-comparision based sorting algorithms.

These algorithms provide sorting in linear time for
collections that have special statistical properties.


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


#ifndef LINSORT_H_AW
#define LINSORT_H_AW


/*
Performs Counting Sort on an array of integer values.
Running Time: O(n)

input:      Pointer to the first element of the input array
            All values k of the input must satisfy the property:
                0 <= k <= largest
            If this property is not satisfied, the sort will fail.
            The input is not modified.
output:     Pointer to the first element of the output array
length:     The length of both the input and output arrays
largest:    The largest value that occurs in the input
*/
void counting_sort(int *input, int *output, int length, int largest);


#endif