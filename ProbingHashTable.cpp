#include "ProbingHashTable.h"


ProbingHashTable::ProbingHashTable() {
	vector<Key> v(116009);						//116009 will be the number of Keys to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
}


ProbingHashTable::~ProbingHashTable() {			//vector already has built in destructors

}

void ProbingHashTable::insert(string key) {
	int h = hash(key);									//find the hash of the word
	int p = hash(key);									//position that will change each iteration (starts as hash)
	int i = 0;											//iterator in while loop

	while (vec[p].word.size() != 0) {					//while the position we are on is taken
		if (vec[p].word == key) {						//if that position already contains the word
			vec[p].rep++;								//then just add 1 to the value
			size++;										//size just increased
			return;										//and return
		}
		else {											//if not, then that means a collision occured
			i++;										//iterate i
			p = (h + i) % mod;							//on to the next hash position (hash +1)
		}
	}
														//for loop exited that means the position is empty
	Key k;												//initialize a key
	k.word = key;										//with the input word
	vec[p] = k;											//the vector with set position is now the intended key
	size++;												//size just increased
}

int ProbingHashTable::remove(string key) {
	Key k;																		//initialize a key
	k.rep = 0;																	//make that key completely emtpy

	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].word == key) {												//if the word is found
			int out = vec[i].rep;												//save it's value for outputting
			vec[i] = k;															//set the value to empty
			size--;																//size just decreased
			return out;															//return the old value
		}
	}
	
	throw std::runtime_error("Remove Error: Key not found in Hash Table");		//for loop exited that means the key didn't exist
	return 0;
}

int ProbingHashTable::get(string key) {
	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].word == key) {											//if the word is found
			return vec[i].rep;												//return it's value
		}
	}

	throw std::runtime_error("Remove Error: Key not found in Hash Table");		//for loop exited that means the key didn't exist
	return 0;
}


void ProbingHashTable::printAll(string filename) {
	string str;								//string variable to fill each position in vector
	ifstream intxt(filename);				//initialize the ifstream operator

	while (getline(intxt, str)) {			//while getting the string of each line and saving it as str
		insert(str);						//push the str to the back of the vector
	}

	ofstream outtext("Probing.txt");

	for (int i = 0; i < vec.size(); i++) {									//for every key
		outtext << vec[i].word << ": " << vec[i].rep << endl;		//output its word and give its value of repetition
	}
}