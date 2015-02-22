#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Sorting\linsort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests
{
    TEST_CLASS(CountingSortTests)
    {
    public:

        TEST_METHOD(CountingSort_One)
        {
            int a[1] = { 1 };
            int b[1];
            counting_sort(a, b, 1, 1);
            Assert::AreEqual<int>(1, b[0]);
        }


        TEST_METHOD(CountingSort_Two)
        {
            int const length = 2;
            int a[length] = { 0, 1 };
            int b[length];
            counting_sort(a, b, length, 1);
            Assert::AreEqual<int>(0, b[0]);
            Assert::AreEqual<int>(1, b[1]);
        }


        TEST_METHOD(CountingSort_Two_Reversed)
        {
            int const length = 2;
            int a[length] = { 1, 0 };
            int b[length];
            counting_sort(a, b, length, 1);
            Assert::AreEqual<int>(0, b[0]);
            Assert::AreEqual<int>(1, b[1]);
        }


        TEST_METHOD(CountingSort_Three)
        {
            int const length = 3;
            int a[length] = { 0, 1, 2 };
            int b[length];
            counting_sort(a, b, length, 2);
            Assert::AreEqual<int>(0, b[0]);
            Assert::AreEqual<int>(1, b[1]);
            Assert::AreEqual<int>(2, b[2]);
        }


        TEST_METHOD(CountingSort_Three_Unordered)
        {
            int const length = 3;
            int a[length] = { 0, 2, 1 };
            int b[length];
            counting_sort(a, b, length, 2);
            Assert::AreEqual<int>(0, b[0]);
            Assert::AreEqual<int>(1, b[1]);
            Assert::AreEqual<int>(2, b[2]);
        }


        TEST_METHOD(CountingSort_Three_Reversed)
        {
            int const length = 3;
            int a[length] = { 2, 1, 0 };
            int b[length];
            counting_sort(a, b, length, 2);
            Assert::AreEqual<int>(0, b[0]);
            Assert::AreEqual<int>(1, b[1]);
            Assert::AreEqual<int>(2, b[2]);
        }


        TEST_METHOD(CountingSort_Ten)
        {
            int const length = 10;
            int a[length] = { 2, 2, 3, 4, 5, 6, 7, 7, 9, 10 };
            int b[length];
            counting_sort(a, b, length, 10);
            Assert::AreEqual<int>(2, b[0]);
            Assert::AreEqual<int>(2, b[1]);
            Assert::AreEqual<int>(3, b[2]);
            Assert::AreEqual<int>(4, b[3]);
            Assert::AreEqual<int>(5, b[4]);
            Assert::AreEqual<int>(6, b[5]);
            Assert::AreEqual<int>(7, b[6]);
            Assert::AreEqual<int>(7, b[7]);
            Assert::AreEqual<int>(9, b[8]);
            Assert::AreEqual<int>(10, b[9]);
        }


        TEST_METHOD(CountingSort_Ten_Unordered)
        {
            int const length = 10;
            int a[length] = { 2, 7, 6, 4, 3, 2, 5, 9, 7, 10 };
            int b[length];
            counting_sort(a, b, length, 10);
            Assert::AreEqual<int>(2, b[0]);
            Assert::AreEqual<int>(2, b[1]);
            Assert::AreEqual<int>(3, b[2]);
            Assert::AreEqual<int>(4, b[3]);
            Assert::AreEqual<int>(5, b[4]);
            Assert::AreEqual<int>(6, b[5]);
            Assert::AreEqual<int>(7, b[6]);
            Assert::AreEqual<int>(7, b[7]);
            Assert::AreEqual<int>(9, b[8]);
            Assert::AreEqual<int>(10, b[9]);
        }


        TEST_METHOD(CountingSort_Ten_Reversed)
        {
            int const length = 10;
            int a[length] = { 10, 9, 7, 7, 6, 5, 4, 3, 2, 2 };
            int b[length];
            counting_sort(a, b, length, 10);
            Assert::AreEqual<int>(2, b[0]);
            Assert::AreEqual<int>(2, b[1]);
            Assert::AreEqual<int>(3, b[2]);
            Assert::AreEqual<int>(4, b[3]);
            Assert::AreEqual<int>(5, b[4]);
            Assert::AreEqual<int>(6, b[5]);
            Assert::AreEqual<int>(7, b[6]);
            Assert::AreEqual<int>(7, b[7]);
            Assert::AreEqual<int>(9, b[8]);
            Assert::AreEqual<int>(10, b[9]);
        }

    };
}