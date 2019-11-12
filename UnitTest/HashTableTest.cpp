#include "pch.h"

#include "../Project3/DrillingRecordHasher.cpp"
#include "../Project3/DrillingRecord.cpp"
#include "../Project3/HashTable.h"
#include "../Project3/DrillingRecordComparator.cpp"
#include "../Project3/HashTableEnumerator.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		const int baseCap = 11;

		TEST_METHOD(TestFindTrue)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord dr;

			dr.setString("00:00:00", 1);

			ht->insert(dr);

			Assert::IsTrue(ht->find(dr).getString(1) == dr.getString(1));
		}

		TEST_METHOD(TestFindFalse)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord dr;

			dr.setString("00:00:00", 1);

			ht->insert(dr);

			dr.setString("00:00:01", 1);

			try {
				ht->find(dr);
				Assert::Fail();
			}
			catch (ExceptionHashTableAccess* e) {
				delete e;
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestFindEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord dr;

			dr.setString("00:00:00", 1);

			try {
				ht ->find(dr);
				Assert::Fail();
			}
			catch (ExceptionHashTableAccess* e) {
				delete e;
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestGetBaseCapacityDefault)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getBaseCapacity() == baseCap);
		}

		TEST_METHOD(TestGetBaseCapacity100)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(),100);

			Assert::IsTrue(ht->getBaseCapacity() == 223);
		}

		TEST_METHOD(TestGetBucketNumber)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord dr;
			dr.setString("00:00:00", 1);

			Assert::IsTrue(ht->getBucketNumber(dr) == (404 % baseCap));

			// These are from the doc
			dr.setString("22:43:12", 1);

			Assert::IsTrue(ht->getBucketNumber(dr) == 0);

			dr.setString("22:43:13", 1);

			Assert::IsTrue(ht->getBucketNumber(dr) == 1);
		}

		TEST_METHOD(TestGetLoadFactorEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getLoadFactor() == 0);
		}

		TEST_METHOD(TestGetLoadFactorBase)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getLoadFactor() == ((float)1 / 11));
		}

		TEST_METHOD(TestGetLoadFactor100)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(),100,DEFAULT_MAX_LOAD_FACTOR,DEFAULT_MIN_LOAD_FACTOR);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getLoadFactor() == ((float)1 / 223));
		}

		TEST_METHOD(TestGetLoadFactorResize)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(), 1, DEFAULT_MAX_LOAD_FACTOR, DEFAULT_MIN_LOAD_FACTOR);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getLoadFactor() == ((float)1 / 2));
		}

		TEST_METHOD(TestGetSizeEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getSize() == 0);
		}

		TEST_METHOD(TestGetSize1)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getSize() == 1);
		}

		TEST_METHOD(TestGetSizeResize)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(), 1, DEFAULT_MAX_LOAD_FACTOR, DEFAULT_MIN_LOAD_FACTOR);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getSize() == 1);
		}

		TEST_METHOD(TestGetTotalCapacityBase)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getTotalCapacity() == 11);
		}

		TEST_METHOD(TestGetTotalCapacity100)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(), 100, DEFAULT_MAX_LOAD_FACTOR, DEFAULT_MIN_LOAD_FACTOR);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getTotalCapacity() == 223);
		}

		TEST_METHOD(TestGetTotalCapacityLL)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(), 3, DEFAULT_MAX_LOAD_FACTOR, DEFAULT_MIN_LOAD_FACTOR);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);
			ht->insert(*dr);

			dr->setString("00:00:05", 1);
			ht->insert(*dr);

			Assert::IsTrue(ht->getTotalCapacity() == 6);
		}

		TEST_METHOD(TestInsert)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::Fail();
		}

		TEST_METHOD(TestRemove)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::Fail();
		}

		TEST_METHOD(TestReplace)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::Fail();
		}
	};
}