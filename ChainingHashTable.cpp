#include "ChainingHashTable.h"

ChainingHashTable::ChainingHashTable() {		//vector and list constructors already built in stl
	vector< vector<string> > v(53000);			//53000 will be the number of buckets to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 53000

	mod = 53000;								//to reduce collisions, mod was chosen to be the number of unique words

	cst = 181;									/**taking "cab" to be the smallest ascii valued 3 letter word, 181 is the
												   smallest integer we can multiply such that every final ascii value is
												   is greater than 53000, so that ascii % mod is a valid return number   **/
};


ChainingHashTable::~ChainingHashTable() {		//default destructor already built in vector and list stl

}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

}