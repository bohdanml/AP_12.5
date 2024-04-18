#include "pch.h"
#include "CppUnitTest.h"
#include "..//AP_12.5/main.cpp"

#include "..//AP_12.5/test_numbers.txt"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			stack<int> numberStack;
			string filename = "test_numbers.txt"; 

			ofstream testFile(filename);
			testFile << "1 2 3 4 5 6 7 8 9 ";
			testFile.close();

			readNumbersFromFile(numberStack, filename);

			Assert::AreEqual(9, (int)numberStack.size()); 

			
			for (int i = 9; i > 0; --i) {
				Assert::AreEqual(i, numberStack.top());
				numberStack.pop();
			}
		
		}
	};
}
