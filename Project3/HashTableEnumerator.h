#ifndef HASH_TABLE_ENUMERATOR
#define HASH_TABLE_ENUMERATOR

#include "Enumerator.h"
#include "Exceptions.h"
#include "HashTable.h"

template <typename T>
class HashTableEnumerator : public Enumerator<T>
{
private:
	unsigned long bucket = 0;
	OULinkedListEnumerator<T>* chainEnumerator = NULL;
	HashTable<T>* hashTable;
public:
	HashTableEnumerator(HashTable<T>* hashTable);
	virtual ~HashTableEnumerator();
	bool hasNext() const;
	T next();              // throws ExceptionEnumerationBeyondEnd if no next item is available
	T peek() const;        // throws ExceptionEnumerationBeyondEnd if no next item is available
};

// Add your implementation below this line.

template <typename T>
HashTableEnumerator<T> :: HashTableEnumerator(HashTable<T>* hashTable) {
	this->hashTable = hashTable;

}

template <typename T>
HashTableEnumerator<T> :: ~HashTableEnumerator() {

}

template <typename T>
bool HashTableEnumerator<T> :: hasNext() const {

}

// throws ExceptionEnumerationBeyondEnd if no next item is available
template <typename T>
T HashTableEnumerator<T> :: next() {

}

// throws ExceptionEnumerationBeyondEnd if no next item is available
template <typename T>
T HashTableEnumerator<T> :: peek() const {

}

#endif // !HASH_TABLE_ENUMERATOR