#include "DoubleHashTable.h"


DoubleHashTable::DoubleHashTable() {
	vector<Key> v(116009);						//116009 will be the number of Keys to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
}


DoubleHashTable::~DoubleHashTable() {			//vector already has built in destructors

}

void DoubleHashTable::insert(string key) {
	int h1 = hash(key);									//find the hash of the word
	int h2 = secondHash(key);
	int p = hash(key);									//position that will change each iteration (starts as hash)
	int i = 0;											//iterator in while loop

	while (vec[p].word.size() != 0) {					//while the position we are on is taken
		if (vec[p].word == key) {						//if that position already contains the word
			vec[p].rep++;								//then just add 1 to the value
			size++;										//size just increased
			return;										//and return
		}
		else {											//if not, then that means a collision occured
			i++;
			p = (h1 + i * h2) % mod;					//on to the next hash position (hash +1)
		}
	}
														//for loop exited that means the position is empty
	Key k;												//initialize a key
	k.word = key;										//with the input word
	vec[p] = k;											//the vector with set position is now the intended key
	size++;												//size just increased
}

int DoubleHashTable::remove(string key) {
	Key k;																		//initialize a key
	k.rep = 0;																	//make that key completely emtpy

	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].word == key) {												//if the word is found
			int out = vec[i].rep;												//save it's value for outputting
			vec[i] = k;															//set the value to empty
			size = size - out;													//size decreased by value
			return out;															//return the old value
		}
	}

	throw std::runtime_error("Remove Error: Key not found in Hash Table");		//for loop exited that means the key didn't exist
	return 0;
}

int DoubleHashTable::get(string key) {
	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].word == key) {												//if the word is found
			return vec[i].rep;													//return it's value
		}
	}

	return 0;
}


void DoubleHashTable::printAll(string filename) {
	string str;								//string variable to fill each position in vector
	ifstream intxt(filename);				//initialize the ifstream operator

	while (getline(intxt, str)) {			//while getting the string of each line and saving it as str
		insert(str);						//push the str to the back of the vector
	}

	ofstream outtext("DoubleHashing.txt");

	for (int i = 0; i < vec.size(); i++) {							//for every key
		if (vec[i].word.size() != 0) {
			outtext << vec[i].word << ": " << vec[i].rep << endl;		//output its word and give its value of repetition
		}
	}
}

 
int DoubleHashTable::secondHash(std::string s) {
	int ascii = 0;								//initialize var ascii as an integer
	int size = s.size();						//number of characters in the string

	for (int i = 0; i < size; i++) {			//for loop into each letter of each string
		ascii = ascii + (s[i] * cst);			//ascii will be equal to the addition of each letter multiplied by a cst
	}


	return 1 + (ascii % (mod - 1));				//the second hash will be total according to the given formula
}
