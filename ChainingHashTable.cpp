#include "ChainingHashTable.h"

ChainingHashTable::ChainingHashTable() {		//vector and list constructors already built in stl
	vector< vector<Key> > v(116009);			//116009 will be the number of buckets to reduce the number of collisions
	vec = v;									//set the private vector to a vector of buckets of size 116009
};


ChainingHashTable::~ChainingHashTable() {		//default destructor already built in vector and list stl

}


void ChainingHashTable::insert(string key) {
	int h = hash(key);										//h is the position of the word in the vector (which bucket)

	Key k;													//initialize a key k
	k.setWord(key);											//set the word of the key to be the input string
	
	for (int i = 0; i < vec[h].size(); i++) {				//for every word in the bucket
		if (vec[h][i].getWord() == key) {					//if the word already exists
			vec[h][i].setRep(vec[h][i].getRep() + 1);		//then just add one to the value
			return;											//then return
		}
	}

	vec[h].push_back(k);									/**if it hasn't been returned then either the bucket was empty
															   or a collision occured. In either case push back.**/
}


int ChainingHashTable::remove(string key) {
	int h = hash(key);															//locate the bucket position
	for (int i = 0; i < vec[h].size(); i++) {									//for every key in that bucket
		if (vec[h][i].getWord() == key) {										//if the key's word = the input string
			int out = vec[h][i].getRep();										//save the word for outputting
			vec[h].erase(vec[h].begin()+i-1);									//delete it
			return out;															//then output it
		}
	}
	throw std::runtime_error("Remove Error: Key not found in Hash Table");		//if the for loop didn't run that means it was empty
	return 0;
}


int ChainingHashTable::get(string key) {
	int h = hash(key);															//locate the bucket position
	for (int i = 0; i < vec[h].size(); i++) {									//for every key in that bucket
		if (vec[h][i].getWord() == key) {										//if the key's word = the input string
			return vec[h][i].getRep();											//then output it
		}
	}
	throw std::runtime_error("Get Error: Key not found in Hash Table");			//if the for loop didn't run that means it was empty
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(string filename) {
	string str;								//string variable to fill each position in vector
	ifstream intxt(filename);				//initialize the ifstream operator

	while (getline(intxt, str)) {			//while getting the string of each line and saving it as str
		insert(str);						//push the str to the back of the vector
	}

	for (int i = 0; i < vec.size(); i++) {											//for every bucket
		for (int j = 0; j < vec[i].size(); j++) {									//and for every word in each bucket
			cout << vec[i][j].getWord() << ": " << vec[i][j].getRep() << endl;		//output its word and give its value of repetition
		}
	}
}