#pragma once
#include "dictionary.h"
#include <iostream>
#include <fstream>


void Dictionary::addToDictionary()
{
	ifstream fin;

	fin.open("article.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	while (!fin.eof()) {
		DATA newItem;
		fin >> newItem.key;
		newItem.data = 1;
		DATA temp;
		DATA temp2;

		if (!_dictionary.AVL_Retrieve(newItem.key, temp))
		{
			_dictionary.AVL_Insert(newItem);
		}
		else
		{
			temp.data++;
			_dictionary.AVL_RetrieveInsert(newItem.key, temp);
		}

	}

	fin.close();
}


void _print(DATA ss)
{
	cout << ss.key << ": " << ss.data << endl;

}

void Dictionary::printDictionary()
{
	_dictionary.AVL_Traverse(_print);
}

void Dictionary::printMetaData()
{
	_dictionary.AVL_Print();
	printf("Number of word in the dictionary: %i\n",_dictionary.AVL_Count());
}


void _search(DATA ss, void *input)
{
	
	cout << ss.key << ": " << ss.data << endl;

}


void Dictionary::search(string input)
{
	//DATA searchKey;
	//searchKey.key = input;

	// int x = 10;
	// _dictionary.something(&x);
	
	// _dictionary.AVL_Traverse(_search);

	_dictionary.search(input);

}