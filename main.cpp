/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/05/2017
*Description: This is the main function for the fantasy combat game program.
*/

#include <iostream>
#include "Game.hpp"
#include "menu.hpp"
#include "validateInput.hpp"

int main(void)
{
	/*
	*The menu function prints the following options and prompts 
	*the user to input an int value which is then returned by the function.
	*Reverse a string - Returns 1
	*Calculate the sum of an array - Returns 2
	*calculate the triangular number for N - Returns 3
	*Exit program - Returns 4
	*int menuReturn holds the value which is then used throughout main.
	*/
	
	//Print game welcome message
	std::cout << std::endl;
	std::cout << "You are now standing at the gates of Fantasy World," << std::endl;
	std::cout << "a place where all your dreams may come true." << std::endl;
	
	int menuReturn = menu();
	
	while(menuReturn == 1)
	{
		Game game;
		game.play();
		menuReturn = menu();
	}
	
	return 0;
}
