/*

File: selection.h

Order based selection algorithms.

Algorithms are provided for finding the minimum, maximum, and selecting the
general nth order statistic from a set of data.


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


#ifndef SELECTION_H_AW
#define SELECTION_H_AW


/*
Finds and returns the minimum element of the given array.
Running Time: O(n)

input:  Pointer to the first element of the data array.
        The array is not modified.
        The array should contain at least one element.
length: Length of the data array
Returns the minimum element.
*/
int minimum(int *input, int length);




/*
Finds and returns the maximum element of the given array.
Running Time: O(n)

input:  Pointer to the first element of the data array.
        The array is not modified.
length: Length of the data array
Returns the maximum element.
*/
int maximum(int *input, int length);


#endif