// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "AVL_ADT.h"
#include <string>
#include <iostream>
#include "dictionary.h"
#include "predict.h"

using namespace std;


void print(DATA ss) {
	cout << ss.key << ": " << ss.data << endl;

}

int main()
{
	Predict p;
	p.predictWord();


	//Dictionary d;
	//d.addToDictionary();
	//string input = "St";
	//d.search(input);
	//d.addToDictionary();
	//
	//d.printDictionary();
	//d.printMetaData();





	return 0;
}

