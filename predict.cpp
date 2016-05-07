#include "predict.h"
#include <iostream>
#include <sstream>
#include <string>

Predict::Predict()
{
	_dictionary.addToDictionary();
}

void Predict::predictWord()
{
	string input = "";
	while (input != "-quit")
	{
		printf("Please enter a word you would like to search\n");
		getline(cin, input);
		printf("You entered: %s\n\n", input.c_str());
		
		_dictionary.search(input);
		
		



	}
}
