#include "HashTable.h"

HashTable::HashTable() {  //default constructor
}

HashTable::~HashTable() { //default destructor
}

int HashTable::hash(string s) {					//hash function to determine index where string key goes
	int ascii = 0;								//initialize var ascii as an integer

	for (int i = 0; i < s.size(); i++) {		//for loop into each letter of each string
		ascii = ascii + (s[i] * cst);			//ascii will be equal to the addition of each letter multiplied by a cst
	}

	return ascii % mod;							//the hash will be total ascii mod some number chosen
}

/** NOTE: I did not include isEmpty here because the vec representing the hash will be defined separately...
          in each HashTable method itself.  **/