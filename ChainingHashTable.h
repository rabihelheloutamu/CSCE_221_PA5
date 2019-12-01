#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"

class Key {		//defenition of a key for our purpose in chaining hash table:
private:
	string word;	//1) a string of characters aka a word
	int rep;		//2) how many times it was repeated
public:
	Key();
	~Key();

	void setWord(string str);			//function to set the string of a key
	void setRep(int val);
	string getWord();
	int getRep();
};

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