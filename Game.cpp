/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the implementation file for the Game class.
*/

#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "validateInput.hpp"

//destructor
Game::~Game()
{
	delete pOne;
	delete pTwo;
}

//methods
void Game::play()
{
	//print welcome message
	std::cout << std::endl;
	std::cout << "Welcome to the combat lair of Fantasy" << std::endl;
	std::cout << "World where creatures of immense power meet" << std::endl;
	std::cout << "to battle to the death. As overloard of this world," << std::endl;
	std::cout << "you are the master of these battles." << std::endl;
	//call fight function
	fight();
}

//prints menu to select creatures to fight, takes user input, validates, then returns value selected
int Game::creatureMenu()
{	
	std::string strMenuOption = "invalid input";
	int menuOption;
	
	do{
		std::cout << std::endl;
		std::cout << "Enter 1 to select Vampire." << std::endl;
		std::cout << "Enter 2 to select Barbarian." << std::endl;
		std::cout << "Enter 3 to select Blue Men."<< std::endl;
		std::cout << "Enter 4 to select Medusa."<< std::endl;
		std::cout << "Enter 5 to select Harry Potter."<< std::endl;
		getline(std::cin, strMenuOption);
	}while(validateInput(strMenuOption, menuOption) != 0 || menuOption > 5 || menuOption < 1);
	
	return menuOption;
}

/*
*This function creates creature objects based on user input. Then these objects take 
*turns rolling die and fighting or defending. Once a creature loses all their strength points, 
*the other creature is declared the winner. 
*/
void Game::fight()
{
	std::cout << std::endl;
	std::cout << "It is now time for you to oversee a creature battle. I hope you are prepared." << std::endl;
	std::cout << "You must select two creatures to battle." << std::endl;
	std::cout << "Select creature one." << std::endl;
	int creatureOne = creatureMenu();
	
	//create creature object for player 1 based off user input.
	switch (creatureOne)
	{
		case 1: {
						std::cout << std::endl;
						std::cout << "You slected Vampire. Excellent choice." << std::endl;
						pOne = new Vampire;
						pOne->setData("Player 1", "Vampire", 1, 12, 1, 6, 1, 18);
						break;
				}				
		case 2: {
						std::cout << std::endl;
						std::cout << "You slected Barbarian. Wouldn't have been my first choice, but ok." << std::endl;
						pOne = new Barbarian;
						pOne->setData("Player 1", "Barbarian", 2, 6, 2, 6, 0, 12);
						break;
				}
		case 3: {
						std::cout << std::endl;
						std::cout << "You slected Blue Men. There are actually three Blue Men that attack as a mob. Neat!" << std::endl;
						pOne = new BlueMen;
						pOne->setData("Player 1", "Blue Men", 2, 10, 3, 6, 3, 12);
						break;
				}
		case 4: {
						std::cout << std::endl;
						std::cout << "You slected Medusa. This will be interesting." << std::endl;
						pOne = new Medusa;
						pOne->setData("Player 1", "Medusa", 2, 6, 1, 6, 3, 8);
						break;
				}
		case 5: {
						std::cout << std::endl;
						std::cout << "You slected Harry Potter. Gryffindor 4EVER!" << std::endl;
						pOne = new HarryPotter;
						pOne->setData("Player 1", "Harry Potter", 2, 6, 2, 6, 0, 10);
						break;
				}
	}
	
	std::cout << "Select creature two." << std::endl;
	int creatureTwo = creatureMenu();
	
	//create creature object for player 2 based off user input.
	switch (creatureTwo)
	{
		case 1: {
						std::cout << std::endl;
						std::cout << "You slected Vampire. Excellent choice." << std::endl;
						pTwo = new Vampire;
						pTwo->setData("Player 2", "Vampire", 1, 12, 1, 6, 1, 18);
						break;
				}				
		case 2: {
						std::cout << std::endl;
						std::cout << "You slected Barbarian. Wouldn't have been my first choice, but ok." << std::endl;
						pTwo = new Barbarian;
						pTwo->setData("Player 2", "Barbarian", 2, 6, 2, 6, 0, 12);
						break;
				}
		case 3: {
						std::cout << std::endl;
						std::cout << "You slected Blue Men. There are actually three Blue Men that attack as a mob." << std::endl;
						std::cout << "Neat!" << std::endl;
						pTwo = new BlueMen;
						pTwo->setData("Player 2", "Blue Men", 2, 10, 3, 6, 3, 12);
						break;
				}
		case 4: {
						std::cout << std::endl;
						std::cout << "You slected Medusa. This will be interesting." << std::endl;
						pTwo = new Medusa;
						pTwo->setData("Player 2", "Medusa", 2, 6, 1, 6, 3, 8);
						break;
				}
		case 5: {
						std::cout << std::endl;
						std::cout << "You slected Harry Potter. Gryffindor 4EVER!" << std::endl;
						pTwo = new HarryPotter;
						pTwo->setData("Player 2", "Harry Potter", 2, 6, 2, 6, 0, 10);
						break;
				}
	}
	
	//randomly generate number to determine which creature will attack first
	//use resluts to set attacker to true or false
	srand(time(NULL));
	int firstAttack = (rand () % 2);
	
	if(firstAttack == 1)
	{
		pOne->setAttacker(true);
		pTwo->setAttacker(false);
	}
	else
	{
		pOne->setAttacker(false);
		pTwo->setAttacker(true);
	}
	
	//roundNum tracks which game round is currently being played.
	int roundNum = 1;
	
	/*
	*Call fight or defend until one of the creatures strength is at or below 0.
	*Use the attacker variable in each object to determine which character is
	*the attacker and which is the defender. Print message once a character
	*has won the battle.
	*/
	while(pOne->getStrength() > 0 && pTwo->getStrength() > 0)
	{
		if(pOne->getAttacker() == true)
		{
			std::cout << std::endl;
			std::cout << "Press any key to begin Round " << roundNum << std::endl;
			waitForKey();
			std::cout << std::endl;
			std::cout << "***ROUND " << roundNum << "***" << std::endl;
			std::cout << "Player One " << pOne->getCharacter() << " is the attacker!"  << std::endl;
			std::cout << "Player Two " << pTwo->getCharacter() << " is the defender." << std::endl;
			int attackRoll = pOne->attack("One");
			pTwo->defend(attackRoll, "Two");
			roundNum++;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Press any key to begin Round " << roundNum << std::endl;
			waitForKey();
			std::cout << std::endl;
			std::cout << "***ROUND " << roundNum << "***" << std::endl;
			std::cout << "Player Two " << pTwo->getCharacter() << " is the attacker!"  << std::endl;
			std::cout << "Player One " << pOne->getCharacter() << " is the defender." << std::endl;
			int attackRoll = pTwo->attack("Two");
			pOne->defend(attackRoll, "One");
			roundNum++;
		}
	}
	
	if(pOne->getStrength() != 0)
	{
		std::cout << std::endl;
		std::cout << "Congratulations to Player One you are the winner of this battle!!!"  << std::endl;
		std::cout << "You are now leaving Fantasy World. Please come back again soon." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Congratulations to Player Two you are the winner of this battle!!!"  << std::endl;
		std::cout << "You are now leaving Fantasy World. Please come back again soon." << std::endl;
	}
}
