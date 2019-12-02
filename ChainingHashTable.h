#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"



class ChainingHashTable: public HashTable {			//chaining hash table class
private:
	vector< vector<Key> > vec;						/**Hash Table:  vector of buckets that stack strings
													   Bucket    :  a vector of strings using vector stl	**/
public:
	ChainingHashTable();
    ~ChainingHashTable();
    void insert(string key);
    int remove(string key);
    int get(string key);
    void printAll(string filename);
};

#endif