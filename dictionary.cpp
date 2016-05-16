#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

#include "dictionary.h"


ofstream FOUT;


void Dictionary::addToDictionary()
{
	string input;
	printf("Enter the file you would like to read from:\n");
	cin >> input;

	ifstream fin;

	fin.open(input);
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}
	
	while (!fin.eof()) {
		DATA newItem;

		fin >> newItem.key;

		// Removes special characters
		newItem.key = trim(newItem.key);	

		newItem.data = 1;
	
		// If word isnt in tree, insert
		if (!_dictionary.AVL_Retrieve(newItem.key, newItem))
		{
			_dictionary.AVL_Insert(newItem);
		}
		else
		{
			newItem.data++;
			_dictionary.update(newItem.key, newItem);
		}		
	}

	printf("%s successfully read\n", input.c_str());

	fin.close();
}





void Dictionary::addToDictionaryPhrases()
{
	string input;
	printf("Enter the file you would like to read from:\n");
	cin >> input;

	ifstream fin;

	fin.open(input);
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	int i = 0;
	string phrase[3];
	string completePhrase;
	bool arrayFull = false;

	while (!fin.eof()) {
		DATA newItem;
		
		fin >> newItem.key;

		newItem.key = trim(newItem.key);
		phrase[i] = newItem.key;
		
		// Maybe change this to mod
		if (i == 2)
		{
			i = 0;
			arrayFull = true;
		}

		// For inserting phrases
		if (arrayFull)
		{
			DATA phraseData;
			
			// This is used to put the words in the order they are read forming a phrase.
			completePhrase = phrase[i % 3] + " " + phrase[(i + 1)%3] + " " + phrase[(i + 2)%3 ];
			
			phraseData.key = completePhrase;
			phraseData.data = 1;

			if (!_dictionary.AVL_Retrieve(phraseData.key, phraseData))
			{
				_dictionary.AVL_Insert(phraseData);
			}
			else
			{
				phraseData.data++;
				_dictionary.update(newItem.key, phraseData);
			}
		}

		newItem.data = 1;
		
		// for inserting words
		if (!_dictionary.AVL_Retrieve(newItem.key, newItem))
		{
			_dictionary.AVL_Insert(newItem);
		}
		else
		{
			newItem.data++;
			_dictionary.update(newItem.key, newItem);
		}

		i++;
	}

	printf("%s successfully read\n", input.c_str());

	fin.close();
}


string Dictionary::trim(string input)
{
	stringstream ss;
	for (int x = 0; x < (int)input.size(); x++)
	{
		if (isalpha(input[x]))
		{
			ss << input[x];
		}
	}

	if (ss.str().length() > 0)
		return ss.str();
	else
		return "";
}


void _print(DATA ss)
{
	cout << ss.key << ": " << ss.data << endl;
}

void Dictionary::printDictionary()
{
	_dictionary.AVL_Traverse(_print);
	printf("Number of word/phrases in the dictionary: %i\n", _dictionary.AVL_Count());
}

void Dictionary::printMetaData()
{
	_dictionary.AVL_Print();
	printf("Number of word/phrases in the dictionary: %i\n",_dictionary.AVL_Count());
}

void Dictionary::search(string input)
{

	priority_queue< DATA, vector<DATA>, dataComparision> pq;
	_dictionary.search(input, &pq);

	for (int i = 0; i < 3 && !pq.empty(); i++)
	{
		cout << pq.top().key << " (" << pq.top().data << ")" << endl;
		pq.pop();
	}

	cout << "...and " << pq.size() << " other entries" << endl << endl;	
	
}

// Used for exporting dictionary
void _save(DATA ss)
{
	FOUT << ss.key << endl;
	
	FOUT << ss.data << endl;
	//cout << ss.key << endl;
	//cout << ss.data << endl;
}


void Dictionary::exportDictionary()
{
	FOUT.open("dictionary.txt");

	if (FOUT.fail())
		cout << "Output file opening failed.\n";

	_dictionary.breadthFirstTraverse(_save);
	FOUT.close();

	printf("Dictionary successfully saved\n");
}

void Dictionary::importDictionary()
{
	ifstream fin;

	fin.open("dictionary.txt");
	if (fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}

	while (!fin.eof() ) {
		DATA newItem;
	
		string strTemp;
		getline(fin, newItem.key);

		// Prevents errors if the last line is empty
		if (newItem.key == "")
			break;
		
		getline(fin, strTemp);
		newItem.data = stoi(strTemp);
	
		if (!_dictionary.AVL_Retrieve(newItem.key, newItem))
		{
			_dictionary.AVL_Insert(newItem);
		}		
	}

	fin.close();

	printf("Dictionary successfully loaded\n");
}


void Dictionary::deleteLowFrequency()
{
	int frequency;

	printf("Enter the frequency:\n");
	cin >> frequency;
	_dictionary.deleteLowFrequency(frequency);
}

