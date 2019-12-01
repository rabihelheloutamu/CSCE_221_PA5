#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class HashTable{				//Universal Hash Table Definition
protected:
	int mod;					//remainder of what? = mod
	int cst;					//constant to be multiploed to each ascii value
	int hash(string s);			//returns the position key s needs to be placed in hash table

public: 
	HashTable();				//constructor
	~HashTable();				//destructor

	virtual void insert(string key) = 0;					//function to insert a string key into a known position in the hash table
	virtual int remove(string key) = 0;						//function to remove key string from hash table
	virtual int get(string key) = 0;						//get information (# of repetitions) of certain key
	virtual void printAll(string filename) = 0;				//print all unique words with info next to them
	virtual bool isEmpty() const = 0;						//is hash empty? -- where hash is represented by the protected vector
};

#endif