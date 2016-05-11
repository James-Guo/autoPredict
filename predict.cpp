#include "predict.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;



void Predict::predictWord()
{
	string input = "";
	while (input != "-exit")
	{
		printf("Please enter a word you would like to search. Type '-exit' to quit\n");
		getline(cin, input);
		printf("You entered: %s\n\n", input.c_str());
		
		_dictionary.search(input);
	
	}
}

void Predict::printMenu()
{
	int input = -1;
	while (input != 9)
	{
		cout << "--------------------------------------" << endl
			<< "Choose one of the following functions:" << endl
			<< "1. Import dictionary." << endl
			<< "2. Learn from dictionary (without phrases)." << endl
			<< "3. Learn from dictionary (with phrases)." << endl
			<< "4. Export dictionary." << endl
			<< "5. Print dictionary." << endl
			<< "6. Print the AVL tree of the dictionary." << endl
			<< "7. Predict words." << endl
			<< "8. Delete low frequency words from the dictionary." << endl
			<< "9. Quit." << endl
			<< "--------------------------------------" << endl;
	
		cin >> input;

		cout << endl;

			
		switch (input) {
		case 1:
			_dictionary.importDictionary();
			break;
		case 2:
			cout << "Impliment learn dictionary from file (without phrases)" << endl;
			break;
		case 3:
			_dictionary.addToDictionary();
			break;
		case 4:
			_dictionary.exportDictionary();
			break;
		case 5:
			_dictionary.printDictionary();
			break;
		case 6:
			_dictionary.printMetaData();
			break;
		case 7:
			cout << "Impliment guess word" << endl;
			predictWord();
			break;
		case 8:
			cout << "Impliment delete low frequency words from dictionary" << endl;
			break;
		case 9:
			cout << "Exiting program" << endl;
			break;
		default:
			cout << "Invalid input, please read the options carefully" << endl;
			break;
		}

		

	}

}