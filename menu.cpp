/*
*Program Name: Group Project
*Date: 5/18/2017
*Description: This is the implementation file for the menu function.
*/

#include <iostream>
#include <string>
//#include <locale>

/*
*The menu function prints options to the console and prompts the user to select an int 
*value which corresponds to each option. The function returns the value selected.
*/

char menu()
{
	char input;
	
	do
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Select an option from the menu: " << std::endl;
		std::cout << "Enter 1 to enter Fantasy World." << std::endl;
		std::cout << "Enter 2 to exit the program." << std::endl;
		std::cin >> userInput;
		userInput = std::tolower(userInput);
	}while(userInput != 'r' || userInput != 'p' || userInput != 's' || userInput != 'e')
	
	return menuOption;
}

