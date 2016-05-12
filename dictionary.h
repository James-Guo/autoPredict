#pragma once
#include <string>
using namespace std;

#include "AVL_ADT_EXT.h"



class Dictionary
{
private:

public:
	void addToDictionary();
	string trim(string input);
	AvlTreeExt<DATA, string> _dictionary;
	void printDictionary();
	void printMetaData();
	void search(string input);

	void importDictionary();

	void deleteLowFrequency();


	

	void exportDictionary();
	


private:


};