#include "binarytree.h"

int main() {

	BinaryTree morseCode;
	
	// display tree in order
	morseCode.displayInOrder();

	// input file stream open
	ifstream convert;
	convert.open("Convert.txt", ios::in);

	string notConverted, temp;
	
	// create string of data from file
	while (!convert.eof())
	{
		getline(convert, temp, '\n');
		notConverted.append(temp);
	}

	// close input file stream
	convert.close();

	int i = 0;
	// skip spaces in string
	while (notConverted[i] != NULL)
	{
		if(notConverted[i] != ' ')
		cout << morseCode.searchNode(toupper(notConverted[i])) << " ";

		i++;
	}

	return 0;
}