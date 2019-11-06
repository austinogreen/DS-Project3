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
	unsigned long itemNumber = 0;
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

	// Initialize enumerator to first bucket's enumerator
	chainEnumerator = hashTable->table[bucket].enumerator();
}

template <typename T>
HashTableEnumerator<T> :: ~HashTableEnumerator() {

}

template <typename T>
bool HashTableEnumerator<T> :: hasNext() const {

	// Checks if the returned items is equal to the number of items in the table
	if (itemNumber > hashTable->getSize()) {
		return false;
	}
	return true;
}

// throws ExceptionEnumerationBeyondEnd if no next item is available
template <typename T>
T HashTableEnumerator<T> ::next() {
	if (bucket > hashTable->getBaseCapacity()) {
		throw new ExceptionEnumerationBeyondEnd;
	}

	// If the chain enumerator doesn't have next go to the next bucket and get its enumerator
	while (!chainEnumerator->hasNext()) {
		bucket++;
		chainEnumerator = hashTable->table[bucket].enumerator();
	}

	// Increment items and return the next
	itemNumber++;
	return chainEnumerator->next();
}

// throws ExceptionEnumerationBeyondEnd if no next item is available
template <typename T>
T HashTableEnumerator<T> :: peek() const {
	if (bucket > hashTable->getBaseCapacity()) {
		throw new ExceptionEnumerationBeyondEnd;
	}

	// If the chain enumerator doesn't have next go to the next bucket and get its enumerator
	while (!(chainEnumerator->hasNext())) {
		bucket++;
		chainEnumerator = hashTable->table[bucket].enumerator();
	}

	// Increment items and return the next
	itemNumber++;
	return chainEnumerator->peek();
}

#endif // !HASH_TABLE_ENUMERATOR