#include "stdafx.h"
#include "..\Sorting\selection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests
{
    TEST_CLASS(QuickSelectTests)
    {
    public:

        TEST_METHOD(Select_One)
        {
            int a[1] = { 1 };
            Assert::AreEqual<int>(1, quick_select(a, 1, 1));
        }


        TEST_METHOD(Select_First)
        {
            int const length = 4;
            int a[length] = { 5, 8, 1, 2 };
            Assert::AreEqual<int>(1, quick_select(a, length, 1));
        }


        TEST_METHOD(Select_Second)
        {
            int const length = 4;
            int a[length] = { 5, 8, 1, 2 };
            Assert::AreEqual<int>(2, quick_select(a, length, 2));
        }

        TEST_METHOD(Select_Third)
        {
            int const length = 4;
            int a[length] = { 5, 8, 1, 2 };
            Assert::AreEqual<int>(5, quick_select(a, length, 3));
        }


        TEST_METHOD(Select_Fourth)
        {
            int const length = 4;
            int a[length] = { 5, 8, 1, 2 };
            Assert::AreEqual<int>(8, quick_select(a, length, 4));
        }


        TEST_METHOD(Select_Fourteen_First)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(-63, quick_select(a, length, 1));
        }


        TEST_METHOD(Select_Fourteen_Second)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(-6, quick_select(a, length, 2));
        }


        TEST_METHOD(Select_Fourteen_Third)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(-4, quick_select(a, length, 3));
        }


        TEST_METHOD(Select_Fourteen_Fourth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(-3, quick_select(a, length, 4));
        }


        TEST_METHOD(Select_Fourteen_Fifth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(1, quick_select(a, length, 5));
        }


        TEST_METHOD(Select_Fourteen_Sixth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(2, quick_select(a, length, 6));
        }


        TEST_METHOD(Select_Fourteen_Seventh)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(3, quick_select(a, length, 7));
        }


        TEST_METHOD(Select_Fourteen_Eighth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(3, quick_select(a, length, 8));
        }


        TEST_METHOD(Select_Fourteen_Ninth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(4, quick_select(a, length, 9));
        }


        TEST_METHOD(Select_Fourteen_Tenth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(5, quick_select(a, length, 10));
        }


        TEST_METHOD(Select_Fourteen_Eleventh)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(7, quick_select(a, length, 11));
        }


        TEST_METHOD(Select_Fourteen_Twelvth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(7, quick_select(a, length, 12));
        }


        TEST_METHOD(Select_Fourteen_Thirteenth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(28, quick_select(a, length, 13));
        }


        TEST_METHOD(Select_Fourteen_Fourteenth)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(234, quick_select(a, length, 14));
        }

    };
}