#include "HashTable.h"

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

HashTable::HashTable() {  //default constructor
	mod = 116009;								/**to reduce collisions, the mod chosen is 1) more than 2 times larger than the unique # of words
												   2) a prime number to reduce divisibility which will decrease hash division**/

	cst = 395;									/**taking "cab" to be the smallest ascii valued 3 letter word, 395 is the
												   smallest integer we can multiply such that every final ascii value is
												   is greater than 116009, so that ascii % mod is a valid return number   **/
}

HashTable::~HashTable() { //default destructor
}

int HashTable::hash(string s) {					//hash function to determine index where string key goes
	int ascii = 0;								//initialize var ascii as an integer
	int size = s.size();						//number of characters in the string

	for (int i = 0; i < size; i++) {			//for loop into each letter of each string
		ascii = ascii + (s[i] * cst);			//ascii will be equal to the addition of each letter multiplied by a cst
	}

	return ascii % mod;							//the hash will be total ascii mod some number chosen
}

/** NOTE: I did not include isEmpty here because the vec representing the hash will be defined separately...
          in each HashTable method itself.  **/