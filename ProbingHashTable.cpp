#include "ProbingHashTable.h"


ProbingHashTable::ProbingHashTable() {
	vector<Key> v(116009);						//116009 will be the number of Keys to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
}


ProbingHashTable::~ProbingHashTable() {			//vector already has built in destructors

}


void ProbingHashTable::insert(string key) {
	int h = hash(key);

	while (vec[h].getWord().size() != 0) {
		if (vec[h].getWord() == key) {
			vec[h].setRep(vec[h].getRep() + 1);
			return;
		}
		else {
			h++;
		}
	}

	Key k;
	k.setWord(key);
	vec[h] = k;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(string filename) {

}