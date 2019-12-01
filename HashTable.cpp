#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() {
}

// destructor
HashTable::~HashTable() {
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(string s) {
	int ascii = 0;

	for (int i = 0; i < s.size(); i++) {
		ascii = ascii + (s[i] * cst);
	}

	return ascii % mod;
}

/** NOTE: I did not include isEmpty here because the vec representing the hash will be defined separately...
          in each HashTable method itself.  **/