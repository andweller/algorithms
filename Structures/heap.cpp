/* heap.cpp - Heap implementations */

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


#include "heap.h"


/* ------------------------------------------------------------- */

/* AbstractHeap Class Implementation */


AbstractHeap::~AbstractHeap() {}


/* 
Adds the given item to the heap.
Returns false if the add operation could not take place. 
*/
bool AbstractHeap::add_item(int item) {
    if (m_count < m_memory_size) {
        m_items[m_count] = item;
        bubble_up(m_count++);
        return true;
    }
    else {
        return false;
    }
}


/*
Removes and returns the head element of the heap.
*/
int AbstractHeap::pop_head() {
    int value = 0;
    if (m_count > 0) {
        value = m_items[m_head_index];
        swap(m_head_index, m_count - 1);
        m_items[--m_count] = 0;
        heapify(m_head_index);
    }
    return value;
}


/*
Returns the head element of the heap without removing it.
*/
int AbstractHeap::peek_head() {
    return m_items[m_head_index];
}


/* 
Swaps two elements in the heap 
first_index - The index of the first element to swap
second_index - The index of the second element to swap
*/
void AbstractHeap::swap(int first_index, int second_index) {
    int temp = m_items[first_index];
    m_items[first_index] = m_items[second_index];
    m_items[second_index] = temp;
}


/*
Returns the parent index of the child index given
*/
int AbstractHeap::parent_index(int index) {
    return (index - 1) / 2;
}


/*
Returns the left child index of the parent index given
*/
int AbstractHeap::left_child_index(int index) {
    return (2 * index) + 1;
}


/*
Returns the right child index of the parent index given
*/
int AbstractHeap::right_child_index(int index) {
    return (2 * index) + 2;
}



/* ------------------------------------------------------------- */

/* MinHeap Implementation */


MinHeap::MinHeap(int size) {
    m_items = new int[size];
    m_memory_size = size;
    m_count = 0;
}


MinHeap::~MinHeap() {
    delete[] m_items;
}


/*
Maintain the minimum heap property starting from the given index.
The function is recursive.
*/
void MinHeap::heapify(int index) {
    int left_index = left_child_index(index);
    int right_index = right_child_index(index);

    int smallest_index;
    int smallest_data;

    if (left_index < m_count && m_items[left_index] < m_items[index]) {
        smallest_index = left_index;
        smallest_data = m_items[left_index];
    }
    else {
        smallest_index = index;
        smallest_data = m_items[index];
    }

    if (right_index < m_count && m_items[right_index] < smallest_data) {
        smallest_index = right_index;
        smallest_data = m_items[right_index];
    }

    if (smallest_index != index) {
        swap(index, smallest_index);
        heapify(smallest_index);
    }
}


/*
Maintains the minimum heap property from a given index by 'bubbling up'
smaller elements until the heap property is satisfied.
For use after an insertion was made at the given index.
*/
void MinHeap::bubble_up(int index) {
    int p_index = parent_index(index);

    while (p_index >= 0 && m_items[p_index] > m_items[index]) {
        swap(index, p_index);
        index = p_index;
        p_index = parent_index(index);
    }
}