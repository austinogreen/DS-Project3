#ifndef HASH_TABLE
#define HASH_TABLE

#include <math.h>
#include "Exceptions.h"
#include "Comparator.h"
#include "OULinkedList.h"
#include "OULinkedListEnumerator.h"
#include "Hasher.h"

const unsigned int SCHEDULE_SIZE = 25;
const unsigned int SCHEDULE[SCHEDULE_SIZE] = { 1, 2, 5, 11, 23, 53, 107, 223, 449, 907, 1823, 3659, 7309, 14621, 29243, 58511, 117023, 234067, 468157, 936319, 1872667, 3745283, 7490573, 14981147, 29962343 };
const unsigned int DEFAULT_SCHEDULE_INDEX = 3;
const unsigned long DEFAULT_BASE_CAPACITY = SCHEDULE[DEFAULT_SCHEDULE_INDEX];
const float DEFAULT_MAX_LOAD_FACTOR = 0.8f;
const float DEFAULT_MIN_LOAD_FACTOR = 0.3f;

template <typename T>
class HashTable {
	template <typename U>
	friend class HashTableEnumerator;
private:
	Comparator<T>* comparator;                                // used to determine item equality
	Hasher<T>* hasher;                                        // used to compute hash value
	unsigned long size = 0;                                   // actual number of items currently in hash table
	float maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR;
	float minLoadFactor = DEFAULT_MIN_LOAD_FACTOR;
	unsigned int scheduleIndex = DEFAULT_SCHEDULE_INDEX;
	unsigned long baseCapacity = DEFAULT_BASE_CAPACITY;        // the size of the array
	unsigned long totalCapacity = baseCapacity;                // the size of the array plus chains of more than one link
	OULinkedList<T>** table = NULL;                            // table will be an array of pointers to OULinkedLists of type T
	// you may add additional member variables and functions here to support the operation of your code
public:
	HashTable(Comparator<T>* comparator, Hasher<T>* hasher);            // creates an empty table of DEFAULT_BASE_CAPACITY
	HashTable(Comparator<T>* comparator, Hasher<T>* hasher,
		// if size given, creates empty table with size from schedule of sufficient capacity (considering maxLoadFactor)
		unsigned long size,
		float maxLoadFactor = DEFAULT_MAX_LOAD_FACTOR,
		float minLoadFactor = DEFAULT_MIN_LOAD_FACTOR);
	virtual ~HashTable();

	// if an equivalent item is not already present, insert item at proper location and return true
	// if an equivalent item is already present, leave table unchanged and return false
	bool insert(T item);

	// if an equivalent item is already present, replace item and return true
	// if an equivalent item is not already present, leave table unchanged and return false
	bool replace(T item);

	// if an equivalent item is already present, remove item and return true
	// if an equivalent item is not already present, leave table unchanged and return false
	bool remove(T item);

	// if an equivalent item is present, return a copy of the item
	// if an equivalent item is not present, throw a new ExceptionHashTableAccess
	T find(T item) const;

	// If the array goes over a load factor threshold, resize
	void resize(void);

	unsigned long getSize() const;                            // returns the current number of items in the table
	unsigned long getBaseCapacity() const;                    // returns the current base capacity of the table
	unsigned long getTotalCapacity() const;                    // returns the current total capacity of the table
	float getLoadFactor() const;                            // returns the current load factor of the table
	unsigned long getBucketNumber(T item) const;            // returns the current bucket number for an item
};

// Add your implementation below this line.

// creates an empty table of DEFAULT_BASE_CAPACITY
template <typename T>
HashTable<T> :: HashTable(Comparator<T>* comparator, Hasher<T>* hasher) {
	// Initialize Class
	this->comparator = comparator;
	this->hasher = hasher;

	// Initialize array at base capacity
	table = new OULinkedList<T>*[baseCapacity];
	if (table == NULL) {
		throw new ExceptionMemoryNotAvailable;
	}

	for (unsigned int i = 0; i < baseCapacity; i++) {
		table[i] = new OULinkedList<T>(comparator);
		if (table[i] == NULL) {
			throw new ExceptionMemoryNotAvailable;
		}
	}
}

// if size given, creates empty table with size from schedule of sufficient capacity (considering maxLoadFactor)
template <typename T>
HashTable<T> :: HashTable(Comparator<T>* comparator, Hasher<T>* hasher,	unsigned long size, float maxLoadFactor, float minLoadFactor) {
	// Initialize Class
	this->comparator = comparator;
	this->hasher = hasher;
	this->maxLoadFactor = maxLoadFactor;
	this->minLoadFactor = minLoadFactor;

	unsigned int minSize = (unsigned int)(size / maxLoadFactor); // This gives the min number of necessary buckets
	scheduleIndex = 0;

	// Loops through the schedule until a size is found greater than minSize
	// >=?
	while (minSize > SCHEDULE[scheduleIndex]) {
		scheduleIndex++;
	}

	// Base capacity of the table
	baseCapacity = SCHEDULE[scheduleIndex];

	// Initialize array at baseCapaticty
	table = new OULinkedList<T> * [baseCapacity];
	if (table == NULL) {
		throw new ExceptionMemoryNotAvailable;
	}

	for (unsigned int i = 0; i < baseCapacity; i++) {
		table[i] = new OULinkedList<T>(comparator);
		if (table[i] == NULL) {
			throw new ExceptionMemoryNotAvailable;
		}
	}
}

// Deallocate all mem
template <typename T>
HashTable<T> :: ~HashTable() {
	for (unsigned int i = 0; i < baseCapacity; i++) {
		delete table[i];
		table[i] = NULL;
	}
	delete[] table;
}

// TODO: If the table exceeds min/max loadfactor, resize

// if an equivalent item is not already present, insert item at proper location and return true
// if an equivalent item is already present, leave table unchanged and return false
// TODO: Check if goes over the size limit
template <typename T>
bool HashTable<T> :: insert(T item) {
	unsigned long bucket = getBucketNumber(item);

	try {
		// Tries to get the first element, if throws an excpetion the bucket is empty
		table[bucket]->getFirst();
		// Chain already exists
		// If the item already exists, return false
		if (!(table[bucket]->insert(item))) {
			return false;
		}
		size++;
	}
	// The list is null
	catch (ExceptionLinkedListAccess*e) {
		// If the item inserts, need to update the total capacity
		if (table[bucket]->insert(item)) {
			totalCapacity++;
			size++;
		}
		// Item is already in the chain
		else {
			return false;
		}
	}

	// Handle case where list over cap
	float loadFactor = ((float)size) / totalCapacity;
	if (loadFactor >= minLoadFactor) {
		resize();
	}

	return true;
}

// if an equivalent item is already present, replace item and return true
// if an equivalent item is not already present, leave table unchanged and return false
template <typename T>
bool HashTable<T> :: replace(T item) {
	unsigned long bucket = getBucketNumber(item);
	
	// Replace item and return true if done
	return table[bucket]->replace(item);
}

// if an equivalent item is already present, remove item and return true
// if an equivalent item is not already present, leave table unchanged and return false
template <typename T>
bool HashTable<T> :: remove(T item) {
	unsigned long bucket = getBucketNumber(item);

	if (table[bucket]->remove) {
		size--;
	}
	else {
		// If the item was not in the list, return false
		return false;
	}
	// See if there are more items in the list
	try {
		table[bucket]->getFirst();
		// If it does not throw an exceptions, that wasn't the only item in the list
		totalCapacity--;
	}
	// there were other items in the list therefore don't decrement total cap
	catch (ExceptionLinkedListAccess e) {}

	// Handle case where list under cap
	float loadFactor = ((float)size) / totalCapacity;
	if (loadFactor <= minLoadFactor) {
		resize();
	}

	return true;
}

// if an equivalent item is present, return a copy of the item
// if an equivalent item is not present, throw a new ExceptionHashTableAccess
template <typename T>
T HashTable<T> :: find(T item) const {
	unsigned long bucket = getBucketNumber(item);

	if (table[bucket] == NULL) {
		throw new ExceptionHashTableAccess;
	}
	
	// Try to return the item;
	try {
		// Return the item
		return table[bucket]->find(item);
	}
	// Item is not in list, therefore throw exception
	catch (ExceptionLinkedListAccess* e) {
		throw new ExceptionHashTableAccess;
	}
}

template<typename T>
void HashTable<T>::resize(void) {
	// Create a temp table at the base capacity
	// Initialize array at baseCapaticty
	OULinkedList<T>** tempTable = new OULinkedList<T>*[baseCapacity];

	unsigned int minSize = (unsigned int) (size / maxLoadFactor); // This gives the min number of necessary buckets
	scheduleIndex = 0;

	// Loops through the schedule until a size is found greater than minSize
	// >=?
	while (minSize > SCHEDULE[scheduleIndex]) {
		scheduleIndex++;
	}

	// Base capacity of the table
	baseCapacity = SCHEDULE[scheduleIndex];

	// Initialize array at baseCapaticty
	table = new OULinkedList<T> * [baseCapacity];
	if (table == NULL) {
		throw new ExceptionMemoryNotAvailable;
	}

	for (unsigned int i = 0; i < baseCapacity; i++) {
		table[i] = new OULinkedList<T>(comparator);
		if (table[i] == NULL) {
			throw new ExceptionMemoryNotAvailable;
		}
	}

	// Resets size and total capacity
	size = 0;
	totalCapacity = baseCapacity;

	// Loops through old table
	// Inserts all items in new table
	for (unsigned int i = 0; i < sizeof(tempTable); i++) {
		OULinkedListEnumerator<T> enumerator = tempTable[i]->enumerator();

		while (enumerator.hasNext()) {
			insert(enumerator.next());
		}
	}
}

// returns the current number of items in the table
template <typename T>
unsigned long HashTable<T> :: getSize() const {
	return size;
}

// returns the current base capacity of the table
template <typename T>
unsigned long HashTable<T> :: getBaseCapacity() const {
	return baseCapacity;
}

// returns the current total capacity of the table
template <typename T>
unsigned long HashTable<T> :: getTotalCapacity() const {
	return totalCapacity;
}

// returns the current load factor of the table
template <typename T>
float HashTable<T> :: getLoadFactor() const {
	return (float)size / totalCapacity;
}

// returns the current bucket number for an item
template <typename T>
unsigned long HashTable<T> :: getBucketNumber(T item) const {
	// Return the key
	return hasher->hash(item) % baseCapacity;
}

#endif // !HASH_TABLE