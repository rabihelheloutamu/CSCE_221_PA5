#include "ChainingHashTable.h"

Key::Key() {
	rep = 1;		//each key alone has one repetition untill added to another key
}

Key::~Key() {
}

void Key::setWord(string str) {
	word = str;
}

void Key::setRep(int val) {
	rep = val;
}

string Key::getWord() {
	return word;
}

int Key::getRep() {
	return rep;
}

ChainingHashTable::ChainingHashTable() {		//vector and list constructors already built in stl
	vector< vector<Key> > v(53000);				//53000 will be the number of buckets to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 53000

	mod = 53000;								//to reduce collisions, mod was chosen to be the number of unique words

	cst = 181;									/**taking "cab" to be the smallest ascii valued 3 letter word, 181 is the
												   smallest integer we can multiply such that every final ascii value is
												   is greater than 53000, so that ascii % mod is a valid return number   **/
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

	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(string filename) {

}