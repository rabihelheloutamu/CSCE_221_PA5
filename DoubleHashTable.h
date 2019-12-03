#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "HashTable.h"


// Double hashing hash table class
class DoubleHashTable : public HashTable {
private:
	vector<Key> vec;							//Hash Table is defined as a vector of keys (no buckets)
    int secondHash(std::string s);				//double hashing requires a secondn hash during collisions
    
public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(string key); 
    int remove(string key); 
    int get(string key); 
    void printAll(string filename);
};

#endif