#include "stdafx.h"
#include "..\Sorting\selection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests
{
    TEST_CLASS(MinimumTests)
    {
    public:

        TEST_METHOD(Min_One)
        {
            int a[1] = { 1 };
            Assert::AreEqual<int>(1, minimum(a, 1));
        }


        TEST_METHOD(Min_Two)
        {
            int const length = 2;
            int a[length] = { 1, 2 };
            Assert::AreEqual<int>(1, minimum(a, length));
        }


        TEST_METHOD(Min_Two_Reversed)
        {
            int const length = 2;
            int a[length] = { 2, 1 };
            Assert::AreEqual<int>(1, minimum(a, length));
        }


        TEST_METHOD(Min_Three_Reversed)
        {
            int const length = 3;
            int a[length] = { 2, 1, 0 };
            Assert::AreEqual<int>(0, minimum(a, length));
        }


        TEST_METHOD(Min_Ten)
        {
            int const length = 14;
            int a[length] = { -4, -6, 1, 5, 7, 28, 4, -3, 2, 3, -63, 3, 7, 234 };
            Assert::AreEqual<int>(-63, minimum(a, length));
        }

    };
}