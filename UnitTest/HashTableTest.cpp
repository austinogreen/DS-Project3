#include "pch.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		const int baseCap = 11;

		TEST_METHOD(TestHashTableFindTrue)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();

			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(&ht->find(*dr) == dr);
		}

		TEST_METHOD(TestHashTableFindFalse)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();

			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			dr->setString("00:00:01", 1);

			Assert::IsFalse(&ht->find(*dr) == dr);
		}

		TEST_METHOD(TestHashTableFindEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();

			dr->setString("00:00:00", 1);

			try {
				ht ->find(*dr);
				Assert::IsTrue(false);
			}
			catch (ExceptionHashTableAccess e) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestHashTableGetBaseCapacityDefault)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getBaseCapacity() == baseCap);
		}

		TEST_METHOD(TestHashTableGetBaseCapacity100)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(),100);

			Assert::IsTrue(ht->getBaseCapacity() == 223);
		}

		TEST_METHOD(TestHashTableGetBucketNumber)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			Assert::IsTrue(ht->getBucketNumber(*dr) == (404 % baseCap));
		}

		TEST_METHOD(TestHashTableGetLoadFactorEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getLoadFactor() == 0);
		}

		TEST_METHOD(TestHashTableGetLoadFactorBase)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getLoadFactor() == (1./11));
		}

		TEST_METHOD(TestHashTableGetLoadFactor100)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher(),100);

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getLoadFactor() == (1. / 223));
		}

		TEST_METHOD(TestHashTableGetSizeEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			Assert::IsTrue(ht->getSize() == 0);
		}

		TEST_METHOD(TestHashTableGetSize1)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(ht->getSize() == 1);
		}

		TEST_METHOD(TestHashTableGetTotalCapacity)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestHashTableInsert)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestHashTableRemove)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(true);
		}

		TEST_METHOD(TestHashTableReplace)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			DrillingRecord* dr = new DrillingRecord();
			dr->setString("00:00:00", 1);

			ht->insert(*dr);

			Assert::IsTrue(true);
		}
	};
}
*/