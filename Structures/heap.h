/* heap.h - Heap definitions */

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


#ifndef HEAP_H_AW
#define HEAP_H_AW


/* Abstract class for heap implementations */
class AbstractHeap {
public:
    virtual ~AbstractHeap() = 0;
    bool add_item(int item);
    int pop_head();
    int peek_head();
protected:
    int *m_items;
    int m_memory_size;
    int m_count;
    const int m_head_index = 0;
    void swap(int first_index, int second_index);
    int parent_index(int index);
    int left_child_index(int index);
    int right_child_index(int index);
    virtual void heapify(int index) = 0;
    virtual void bubble_up(int index) = 0;
};



/* A minimum heap implementation (priority queue) */
class MinHeap : public AbstractHeap {
public:
    MinHeap(int size);
    ~MinHeap();
protected:
    void heapify(int index);
    void bubble_up(int index);
};

#endif