#pragma once
#include <string>
using namespace std;

#include "AVL_ADT_EXT.h"



class Dictionary
{
private:
	AvlTreeExt<DATA, string> _dictionary;
	
	string trim(string input);
	
public:
	void addToDictionary();
	void addToDictionaryPhrases();	
	
	void printDictionary();
	void printMetaData();
	
	void deleteLowFrequency();

	void search(string input);

	void importDictionary();
	void exportDictionary();
	





};