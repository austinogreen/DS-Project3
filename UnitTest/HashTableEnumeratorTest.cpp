#include "pch.h"


/*
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace HashTableEnumeratorTest
{
	TEST_CLASS(HashTableEnumeratorTest)
	{
	public:

		TEST_METHOD(TestHasNextEmpty)
		{
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			Assert::IsFalse(enumerator.hasNext());
		}

		TEST_METHOD(TestHasNextOneBucket)
		{
			DrillingRecord dr;
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			ht->insert(dr);

			Assert::IsTrue(enumerator.hasNext());
		}
		TEST_METHOD(TestNext)
		{
			DrillingRecord dr;
			dr.setString("00:00:00",1);
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());
			ht->insert(dr);

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			Assert::IsTrue(enumerator.next().getString(1) == dr.getString(1));
		}

		TEST_METHOD(TestNextNone)
		{
			DrillingRecord dr;
			dr.setString("00:00:00", 1);
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());
			ht->insert(dr);

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			enumerator.next();

			try {
				enumerator.next();
				Assert::Fail();
			}
			catch (ExceptionEnumerationBeyondEnd* e) {
				delete e;
				Assert::IsTrue(true);
			}

		}
		TEST_METHOD(TestPeekEmpty)
		{
			DrillingRecord dr;
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());
			
			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			try {
				enumerator.peek();
				Assert::Fail();
			}
			catch (ExceptionEnumerationBeyondEnd* e) {
				delete e;
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestPeek)
		{
			DrillingRecord dr;
			dr.setString("00:00:00", 1);
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());
			ht->insert(dr);

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			Assert::IsTrue(enumerator.peek().getString(1) == dr.getString(1));
		}

		TEST_METHOD(TestPeekX2)
		{
			DrillingRecord dr;
			dr.setString("00:00:00", 1);
			HashTable<DrillingRecord>* ht = new HashTable<DrillingRecord>(new DrillingRecordComparator(1), new DrillingRecordHasher());
			ht->insert(dr);

			HashTableEnumerator<DrillingRecord> enumerator = HashTableEnumerator<DrillingRecord>(ht);

			enumerator.peek();

			Assert::IsTrue(enumerator.peek().getString(1) == dr.getString(1));
		}
	};
}*/