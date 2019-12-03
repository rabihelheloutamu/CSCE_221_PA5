#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

struct Key {		//defenition of a key for our purpose in hash tables:
	string word;	//1) a string of characters aka a word
	int rep;		//2) how many times it was repeated
};

class HashTable{				//Universal Hash Table Definition
protected:
	int mod;					//remainder of what? = mod
	int cst;					//constant to be multiplied to each ascii value
	int size;					//number of words ( to make isEmpty() O(1) )
	int hash(string s);			//returns the position key s needs to be placed in hash table

public: 
	HashTable();				//constructor
	~HashTable();				//destructor

	virtual void insert(string key) = 0;					//function to insert a string key into a known position in the hash table
	virtual int remove(string key) = 0;						//function to remove key string from hash table
	virtual int get(string key) = 0;						//get information (# of repetitions) of certain key
	virtual void printAll(string filename) = 0;				//print all unique words with info next to them
	bool isEmpty();											//is hash empty? -- where hash is represented by the protected vector
};

#endif