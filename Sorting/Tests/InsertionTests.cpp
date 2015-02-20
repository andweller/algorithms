#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Sorting\sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests
{		
	TEST_CLASS(InsertionTests)
	{
	public:
		
		TEST_METHOD(Insertion_Int_One)
		{
			int a[1] = { 10 };
			insertion_sort(a, 1);
			Assert::AreEqual<int>(10, a[0]);
		}


		TEST_METHOD(Insertion_Int_Two)
		{
			int const length = 2;
			int a[length] = { 10, 11 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(10, a[0]);
			Assert::AreEqual<int>(11, a[1]);
		}


		TEST_METHOD(Insertion_Int_Two_Reversed)
		{
			int const length = 2;
			int a[length] = { 11, 10 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(10, a[0]);
			Assert::AreEqual<int>(11, a[1]);
		}


		TEST_METHOD(Insertion_Int_Three)
		{
			int const length = 3;
			int a[length] = { 10, 11, 12 };
            insertion_sort(a, length);
			Assert::AreEqual<int>(10, a[0]);
			Assert::AreEqual<int>(11, a[1]);
			Assert::AreEqual<int>(12, a[2]);
		}


		TEST_METHOD(Insertion_Int_Three_Unordered)
		{
			int const length = 3;
			int a[length] = { 10, 12, 11 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(10, a[0]);
			Assert::AreEqual<int>(11, a[1]);
			Assert::AreEqual<int>(12, a[2]);
		}


		TEST_METHOD(Insertion_Int_Three_Reversed)
		{
			int const length = 3;
			int a[length] = { 12, 11, 10 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(10, a[0]);
			Assert::AreEqual<int>(11, a[1]);
			Assert::AreEqual<int>(12, a[2]);
		}


		TEST_METHOD(Insertion_Int_Ten)
		{
			int const length = 10;
			int a[length] = { 2, 2, 3, 4, 5, 6, 7, 7, 9, 10 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(2, a[0]);
			Assert::AreEqual<int>(2, a[1]);
			Assert::AreEqual<int>(3, a[2]);
			Assert::AreEqual<int>(4, a[3]);
			Assert::AreEqual<int>(5, a[4]);
			Assert::AreEqual<int>(6, a[5]);
			Assert::AreEqual<int>(7, a[6]);
			Assert::AreEqual<int>(7, a[7]);
			Assert::AreEqual<int>(9, a[8]);
			Assert::AreEqual<int>(10, a[9]);
		}


		TEST_METHOD(Insertion_Int_Ten_Unordered)
		{
			int const length = 10;
			int a[length] = { 2, 7, 6, 4, 3, 2, 5, 9, 7, 10 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(2, a[0]);
			Assert::AreEqual<int>(2, a[1]);
			Assert::AreEqual<int>(3, a[2]);
			Assert::AreEqual<int>(4, a[3]);
			Assert::AreEqual<int>(5, a[4]);
			Assert::AreEqual<int>(6, a[5]);
			Assert::AreEqual<int>(7, a[6]);
			Assert::AreEqual<int>(7, a[7]);
			Assert::AreEqual<int>(9, a[8]);
			Assert::AreEqual<int>(10, a[9]);
		}


		TEST_METHOD(Insertion_Int_Ten_Reversed)
		{
			int const length = 10;
			int a[length] = { 10, 9, 7, 7, 6, 5, 4, 3, 2, 2 };
			insertion_sort(a, length);
			Assert::AreEqual<int>(2, a[0]);
			Assert::AreEqual<int>(2, a[1]);
			Assert::AreEqual<int>(3, a[2]);
			Assert::AreEqual<int>(4, a[3]);
			Assert::AreEqual<int>(5, a[4]);
			Assert::AreEqual<int>(6, a[5]);
			Assert::AreEqual<int>(7, a[6]);
			Assert::AreEqual<int>(7, a[7]);
			Assert::AreEqual<int>(9, a[8]);
			Assert::AreEqual<int>(10, a[9]);
		}

	};
}