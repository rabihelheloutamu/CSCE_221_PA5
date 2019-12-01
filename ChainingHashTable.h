#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"

class ChainingHashTable: public HashTable {			//chaining hash table class
private:
	vector< vector<string> > vec;					/**Hash Table:  vector of buckets that stack strings
													   Bucket    :  a vector of strings using vector stl	**/
public:
	ChainingHashTable();
    ~ChainingHashTable();
    void insert(std::string key, int val);
    int remove(std::string key);
    int get(std::string key);
    void printAll(std::string filename);
};

#endif