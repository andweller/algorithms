/*

File: linsort.cpp

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

All values k of the input must satisfy the property:
    0 <= k <= largest
If this property is not satisfied, the sort will fail.
*/
void counting_sort(int *input, int *output, int length, int largest) {
    int *temp_array = new int[largest + 1];
    for (int temp_index = 0; temp_index <= largest; temp_index++)
        temp_array[temp_index] = 0;

    // Count the number of times each value occurs in the input
    for (int count_index = 0; count_index < length; count_index++) {
        int value = input[count_index];
        temp_array[value]++;
    }

    // Record the number of elements <= to each index i 
    // where i is a value in the input
    for (int prev_sum_index = 1; prev_sum_index <= largest; prev_sum_index++) {
        temp_array[prev_sum_index] += temp_array[prev_sum_index - 1];
    }

    // Place the appropiate value into the output array
    for (int index = length - 1; index >= 0; index--) {
        int value = input[index];
        int access = temp_array[value];
        output[temp_array[value] - 1] = value;
        temp_array[value]--;
    }

    delete[] temp_array;
}


#endif