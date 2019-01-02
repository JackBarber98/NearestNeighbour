#include "Console.h"
using namespace std;

Console::Console()
{
}

Console::~Console()
{

}

//The user is prompted for an integer number of closest matches to locate using the nearest neighbour search, and is returned
int Console::GetN() {
	int input = 0;
	cout << "Enter the number of closest matches to be displayed. " << endl;

	/* If the input cannot be streamed to an integer variable, or the input value is out of reasonable range
	the program will request a new input from the user after displaying an error message
	*/
	while (!(cin >> input) || input < 0 || input > 100) {
		cout << "Only integers in the range 1-100 are valid. Please try again. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}

//The user is prompted to select whether they want similarity calculations to be displayed or not
bool Console::ShowCalculations() {
	char input = ' ';
	cout << "Would you like the top n similarity calculations to be displayed? (y/n)" << endl;

	//If the user does not enter the input 'y' or 'n', they are prompted to insert a new, valid input
	while (!(cin >> input) || (input != 'y' && input != 'n')) {
		cout << "Only inputs of y or n are valid. Please try again. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//False is returned if the user selected 'n', and the reverse if 'y' was inputted
	if (input == 'y') {
		return true;
	}
	else if(input == 'n'){
		return false;
	}
}

bool Console::ShowDetail() {
	char input = ' ';
	cout << "Would you like all matrix values to be displayed? This may take some time. (y/n)" << endl;

	//If the user does not enter the input 'y' or 'n', they are prompted to insert a new, valid input
	while (!(cin >> input) || (input != 'y' && input != 'n')) {
		cout << "Only inputs of y or n are valid. Please try again. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//False is returned if the user selected 'n', and the reverse if 'y' was inputted
	if (input == 'y') {
		return true;
	}
	else if (input == 'n') {
		return false;
	}
}