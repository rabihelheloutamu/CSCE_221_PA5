#include "ChainingHashTable.h"


ChainingHashTable::ChainingHashTable() {		//vector and list constructors already built in stl
	vector< vector<Key> > v(58000);				//58000 will be the number of buckets to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 53000
};


ChainingHashTable::~ChainingHashTable() {		//default destructor already built in vector and list stl

}

// inserts the given string key
void ChainingHashTable::insert(string key) {
	int h = hash(key);										//h is the position of the word in the vector (which bucket)

	Key k;													//initialize a key k
	k.setWord(key);											//set the word of the key to be the input string
	
	for (int i = 0; i < vec[h].size(); i++) {				//for every word in the bucket
		if (vec[h][i].getWord() == k.getWord()) {			//if the word already exists
			vec[h][i].setRep(vec[h][i].getRep() + 1);		//then just add one to the value
			return;											//then return
		}
	}

	vec[h].push_back(k);									/**if it hasn't been returned then either the bucket was empty
															   or a collision occured. In either case push back.**/
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(string key) {
	int h = hash(key);
	for (int i = 0; i < vec[h].size(); i++) {
		if (vec[h][i].getWord() == key) {
			int out = vec[h][i].getRep();
			vec[h].erase(vec[h].begin()+i-1);
			return out;
		}
	}
	throw std::runtime_error("Remove Error: Key not found in Hash Table");
	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(string key) {
	int h = hash(key);
	for (int i = 0; i < vec[h].size(); i++) {
		if (vec[h][i].getWord() == key) {
			int out = vec[h][i].getRep();
			return out;
		}
	}
	throw std::runtime_error("Get Error: Key not found in Hash Table");
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(string filename) {

}