#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/DrillingRecordHasher.cpp"
#include "../Project3/DrillingRecord.cpp"
#include "../Project3/HashTable.h"
#include "../Project3/DrillingRecordComparator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestHashTableGetBucketNumber)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00",1);

			Assert::IsTrue(ht->getBucketNumber(*dr) == 404);
		}

		TEST_METHOD(TestHashTableInsert)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();

			ht->insert(*dr);

			Assert::IsTrue(true);
		}
	};
}
