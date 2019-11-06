#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/DrillingRecordHasher.cpp"
#include "../Project3/DrillingRecord.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestHash)
		{
			DrillingRecord* dr = new DrillingRecord();
			DrillingRecordHasher* hasher = new DrillingRecordHasher();
			dr->setString("00:00:00",1);

			Assert::IsTrue(hasher->hash(*dr) == 404);

			dr->setString("11:11:11", 1);

			Assert::IsTrue(hasher->hash(*dr) == 410);
		}
	};
}
