#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Heap\heap.h"
#include "..\Heap\heap.cpp"

#include <cstdlib>
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests
{
    TEST_CLASS(HeapSortTests)
    {
    public:

        TEST_METHOD(Heapsort_Int_One)
        {
            MinHeap heap = MinHeap(1);
            heap.add_item(10);
            Assert::AreEqual<int>(10, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Two)
        {
            int const length = 2;
            MinHeap heap = MinHeap(length);
            heap.add_item(10);
            heap.add_item(11);
            Assert::AreEqual<int>(10, heap.pop_head());
            Assert::AreEqual<int>(11, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Two_Reversed)
        {
            int const length = 2;
            MinHeap heap = MinHeap(length);
            heap.add_item(11);
            heap.add_item(10);
            Assert::AreEqual<int>(10, heap.pop_head());
            Assert::AreEqual<int>(11, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Three)
        {
            int const length = 3;
            MinHeap heap = MinHeap(length);
            heap.add_item(10);
            heap.add_item(11);
            heap.add_item(12);
            Assert::AreEqual<int>(10, heap.pop_head());
            Assert::AreEqual<int>(11, heap.pop_head());
            Assert::AreEqual<int>(12, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Three_Unordered)
        {
            int const length = 3;
            MinHeap heap = MinHeap(length);
            heap.add_item(10);
            heap.add_item(12);
            heap.add_item(11);
            Assert::AreEqual<int>(10, heap.pop_head());
            Assert::AreEqual<int>(11, heap.pop_head());
            Assert::AreEqual<int>(12, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Three_Reversed)
        {
            int const length = 3;
            MinHeap heap = MinHeap(length);
            heap.add_item(12);
            heap.add_item(11);
            heap.add_item(10);
            Assert::AreEqual<int>(10, heap.pop_head());
            Assert::AreEqual<int>(11, heap.pop_head());
            Assert::AreEqual<int>(12, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Ten)
        {
            int const length = 10;
            MinHeap heap = MinHeap(length);
            heap.add_item(2);
            heap.add_item(2);
            heap.add_item(3);
            heap.add_item(4);
            heap.add_item(5);
            heap.add_item(6);
            heap.add_item(7);
            heap.add_item(7);
            heap.add_item(9);
            heap.add_item(10);
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(3, heap.pop_head());
            Assert::AreEqual<int>(4, heap.pop_head());
            Assert::AreEqual<int>(5, heap.pop_head());
            Assert::AreEqual<int>(6, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(9, heap.pop_head());
            Assert::AreEqual<int>(10, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Ten_Unordered)
        {
            int const length = 10;
            MinHeap heap = MinHeap(length);
            heap.add_item(2);
            heap.add_item(7);
            heap.add_item(6);
            heap.add_item(4);
            heap.add_item(3);
            heap.add_item(2);
            heap.add_item(5);
            heap.add_item(9);
            heap.add_item(7);
            heap.add_item(10);
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(3, heap.pop_head());
            Assert::AreEqual<int>(4, heap.pop_head());
            Assert::AreEqual<int>(5, heap.pop_head());
            Assert::AreEqual<int>(6, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(9, heap.pop_head());
            Assert::AreEqual<int>(10, heap.pop_head());
        }


        TEST_METHOD(Heapsort_Int_Ten_Reversed)
        {
            int const length = 10;
            MinHeap heap = MinHeap(length);
            heap.add_item(10);
            heap.add_item(9);
            heap.add_item(7);
            heap.add_item(7);
            heap.add_item(6);
            heap.add_item(5);
            heap.add_item(4);
            heap.add_item(3);
            heap.add_item(2);
            heap.add_item(2);
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(2, heap.pop_head());
            Assert::AreEqual<int>(3, heap.pop_head());
            Assert::AreEqual<int>(4, heap.pop_head());
            Assert::AreEqual<int>(5, heap.pop_head());
            Assert::AreEqual<int>(6, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(7, heap.pop_head());
            Assert::AreEqual<int>(9, heap.pop_head());
            Assert::AreEqual<int>(10, heap.pop_head());
        }


        TEST_METHOD(Heapsort_100_Random)
        {
            int const length = 100;
            MinHeap heap = MinHeap(length);

            std::srand((unsigned int)time(NULL));
            
            for (int i = 0; i < length; i++) {
                heap.add_item(std::rand() % 10000);
            }

            int previous = -1;
            for (int i = 0; i < length; i++) {
                int current = heap.pop_head();
                Assert::IsTrue(previous <= current);
                previous = current;
            }
        }

    };
}