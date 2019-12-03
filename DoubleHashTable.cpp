#include "DoubleHashTable.h"


DoubleHashTable::DoubleHashTable() {
	vector<Key> v(116009);						//116009 will be the number of Keys to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
}


DoubleHashTable::~DoubleHashTable() {			//vector already has built in destructors

}


void DoubleHashTable::insert(std::string key, int val) {
	int h = hash(key);									//find the initial position of the word
	int i = 0;

	while (vec[h].getWord().size() != 0) {				//while the position we are on is taken
		if (vec[h].getWord() == key) {					//if that position already contains the word
			vec[h].setRep(vec[h].getRep() + 1);			//then just add 1 to the value
			return;										//and return
		}
		else {											//if not, then that means a collision occured
			i++;
			h = hash(key) + i * secondHash(key);		//on to the next hash position (hash +1)
		}
	}
														//for loop exited that means the position is empty
	Key k;												//initialize a key
	k.setWord(key);										//with the input word
	vec[h] = k;											//the vector with set position is now the intended key
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {

}

 
int DoubleHashTable::secondHash(std::string s) {
	int ascii = 0;								//initialize var ascii as an integer
	int size = s.size();						//number of characters in the string

	for (int i = 0; i < size; i++) {			//for loop into each letter of each string
		ascii = ascii + (s[i] * cst);			//ascii will be equal to the addition of each letter multiplied by a cst
	}


	return 1 + (ascii % (mod - 1));				//the second hash will be total according to the given formula
}
