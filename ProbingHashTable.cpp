#include "ProbingHashTable.h"


ProbingHashTable::ProbingHashTable() {
	vector<Key> v(116009);						//116009 will be the number of Keys to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
}


ProbingHashTable::~ProbingHashTable() {			//vector already has built in destructors

}


void ProbingHashTable::insert(string key) {
	int h = hash(key);									//find the initial position of the word

	while (vec[h].getWord().size() != 0) {				//while the position we are on is taken
		if (vec[h].getWord() == key) {					//if that position already contains the word
			vec[h].setRep(vec[h].getRep() + 1);			//then just add 1 to the value
			return;										//and return
		}
		else {											//if not, then that means a collision occured
			h++;										//on to the next hash position (hash +1)
		}
	}
														//for loop exited that means the position is empty
	Key k;												//initialize a key
	k.setWord(key);										//with the input word
	vec[h] = k;											//the vector with set position is now the intended key
}


int ProbingHashTable::remove(string key) {
	Key k;																		//initialize a key
	k.setRep(0);																//make that key completely emtpy
	
	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].getWord() == key) {											//if the word is found
			int out = vec[i].getRep();											//save it's value for outputting
			vec[i] = k;															//set the value to empty
			return out;															//return the old value
		}
	}
	
	throw std::runtime_error("Remove Error: Key not found in Hash Table");		//for loop exited that means the key didn't exist
	return 0;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(string key) {
	for (int i = 0; i < vec.size(); i++) {										//iterate through the entire vector since collisions may have occured
		if (vec[i].getWord() == key) {											//if the word is found
			return vec[i].getRep();												//return it's value
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

	for (int i = 0; i < vec.size(); i++) {										//for every key
			cout << vec[i].getWord() << ": " << vec[i].getRep() << endl;		//output its word and give its value of repetition
	}
}