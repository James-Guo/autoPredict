#pragma once
#include "AVL_ADT.h"
#include <string>
#include <iostream>

using namespace std;

struct DATA
{
	string key;
	int data;
};


class Dictionary
{
public:
	void addToDictionary();
	AvlTree<DATA, string> _dictionary;
	void printDictionary();
	void printMetaData();
	void search(string input);
	


private:


};