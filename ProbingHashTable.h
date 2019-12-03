#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"


class ProbingHashTable : public HashTable {
private:
	vector<Key> vec;							//Hash Table is defined as a vector of keys (no buckets)

public:
	ProbingHashTable();
	~ProbingHashTable();
	void insert(string key);
	int remove(string key);
	int get(string key);
	void printAll(string filename);
};

#endif