#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include "ChainingHashTable.h"
#include "StopWatch.h"

int main()
{
	vector<string> v;
	v.emplace_back("rep1"); v.emplace_back("rep2"); v.emplace_back("rep3");	//this is the set of strings inserted
	v.emplace_back("rep4"); v.emplace_back("rep2"); v.emplace_back("rep3");
	v.emplace_back("rep3"); v.emplace_back("rep4"); v.emplace_back("rep4");
	v.emplace_back("rep4");

	ProbingHashTable p;
	DoubleHashTable d;
	ChainingHashTable c;

	for (int i = 0; i < 10; i++) {	//inserting the elements of the vector one by one for the 3 methods
		p.insert(v[i]);
		d.insert(v[i]);
		c.insert(v[i]);
	}
	cout << "All 10 elements have been inserted.\n\n"
		<< "isEmpty for all three: " << p.isEmpty() << " " << d.isEmpty() << " " << c.isEmpty()
		<< "\n\nget rep1 for ProbingHashTable: " << p.get("rep1")
		<< "\n\nget rep2 for ProbingHashTable: " << p.get("rep2")
		<< "\n\nget rep3 for ProbingHashTable: " << p.get("rep3")
		<< "\n\nget rep4 for ProbingHashTable: " << p.get("rep4")
		<< "\n\nget rep1 for DoublingHashTable: " << d.get("rep1")
		<< "\n\nget rep2 for DoublingHashTable: " << d.get("rep2")
		<< "\n\nget rep3 for DoublingHashTable: " << d.get("rep3")
		<< "\n\nget rep4 for DoublingHashTable: " << d.get("rep4")
		<< "\n\nget rep1 for ChainingHashTable: " << c.get("rep1")
		<< "\n\nget rep2 for ChainingHashTable: " << c.get("rep2")
		<< "\n\nget rep3 for ChainingHashTable: " << c.get("rep3")
		<< "\n\nget rep4 for ChainingHashTable: " << c.get("rep4");

	cout << "\n\nremove rep1 for ProbingHashTable: " << p.remove("rep1")
		<< "\n\nremove rep2 for ProbingHashTable: " << p.remove("rep2")
		<< "\n\nremove rep3 for ProbingHashTable: " << p.remove("rep3")
		<< "\n\nremove rep4 for ProbingHashTable: " << p.remove("rep4")
		<< "\n\nremove rep1 for DoublingHashTable: " << d.remove("rep1")
		<< "\n\nremove rep2 for DoublingHashTable: " << d.remove("rep2")
		<< "\n\nremove rep3 for DoublingHashTable: " << d.remove("rep3")
		<< "\n\nremove rep4 for DoublingHashTable: " << d.remove("rep4")
		<< "\n\nremove rep1 for ChainingHashTable: " << c.remove("rep1")
		<< "\n\nremove rep2 for ChainingHashTable: " << c.remove("rep2")
		<< "\n\nremove rep3 for ChainingHashTable: " << c.remove("rep3")
		<< "\n\nremove rep4 for ChainingHashTable: " << c.remove("rep4");

	cout << "\n\nisEmpty for all three: " << p.isEmpty() << " " << d.isEmpty() << " " << c.isEmpty() << "\n\n";



	ProbingHashTable P;
	DoubleHashTable D;
	ChainingHashTable C;

	//P.printAll("dictionary.txt");
	//D.printAll("dictionary.txt");
	//C.printAll("dictionary.txt");

	vector<string> vec;								//creating a vector to store several words and use for testing
	string str;										//string variable to fill each position in vector
	ifstream intxt("dictionary.txt");				//initialize the ifstream operator

	int i = 0;										//iterator to save time for our purpose of only 2000 words
	while (getline(intxt, str) && i != 20001) {		//while getting the string of each line and saving it as str, also not exceeding 2000 words
		vec.push_back(str);							//push the str to the back of the vector
		i++;										//iterate
	}

	StopWatch t;

	cout << "We will record the time taken to insert i times into different Hash Tables where i starts from zero and increases " <<
		"by 100 until it reaches 2000.\n\n\n";

	cout << "ProbingHashTable: \n\n";
	t.start();
	for (int i = 0; i <= 20000; i++) {
		if (i % 1000 == 0) {				//every multiple of 100
			cout << t.ms() << endl;		//output the time taken since we started
		}
		P.insert(vec[i]);				//we insert 100 before the if statement is tested
	}
	t.stop();

	cout << "DoubleHashTable: \n\n";
	t.start();
	for (int i = 0; i <= 20000; i++) {
		if (i % 1000 == 0) {				//every multiple of 100
			cout << t.ms() << endl;		//output the time taken since we started
		}
		D.insert(vec[i]);				//we insert 100 before the if statement is tested
	}
	t.stop();

	cout << "ChainingHashTable: \n\n";
	t.start();
	for (int i = 0; i <= 20000; i++) {
		if (i % 1000 == 0) {				//every multiple of 100
			cout << t.ms() << endl;		//output the time taken since we started
		}
		C.insert(vec[i]);				//we insert 100 before the if statement is tested
	}
	t.stop();
}