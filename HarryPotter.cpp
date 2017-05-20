/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/06/2017
*Description: This is the implementation file for the HarryPotter class.
*/

#include <iostream>
#include "HarryPotter.hpp"

//methods

/*
*The attack method for HarryPotter calls rollDie() from the attackDie object and returns the roll.
*It also changes the attacker vairiable to false so that the program knows it is Harrys's turn to defend.
*/
int HarryPotter::attack(std::string p)
{
	int roll = this->attackDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled an attack of "  << roll << "." << std::endl;
	//change this creature to the defender for the next round
	attacker = false;
	return roll;
}

/*
*The defend method for HarryPotter calls rollDie() from the defenseDie object and then adds the armor value to the roll.
*Then the function checks the lifetracker variable to see if Harry is on his first or second life.
*If Harry is on his first life and the damage exceeds his strength, Harry is revived and the lifeTrackers records this event.
*If Harry is not revived then the total damage is subtracted from his strength points. 
*Lastly, the attacker variable is changed to true so that the program knows it is Harry's turn to attack.
*/
void HarryPotter::defend(int attackRoll, std::string p)
{
	//declare variable to hold the total damage the creature must take from the attack
	int damage;
	int roll = this->defenseDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled a defense of "  << roll << "." << std::endl;
	//add armor to roll
	roll += armor;
	std::cout << "Player " << p << " " << type << " has " << armor << " armor." << std::endl; 
	std::cout << "Player " << p << " " << type << "'s " << "total defense is "<< roll << "." << std::endl;
	
	if(attackRoll < roll && lifeTracker == 1)
	{
		//if attack is less than defense, no damage was done
		damage = 0;
	}
	else
	{
		//if attack is greater than damage then subtract the difference between the attack and the defense
		damage = attackRoll - roll;
	}
	
	//if killed on first life, Harry is revived and his strength is set to 20!!!!
	if(strength <= damage && lifeTracker == 1)
	{
		std::cout << std::endl;
		std::cout << "Harry died, but don't despair. Through the power of Hogwarts, he has revived!" << std::endl;
		std::cout << "Now he is even stronger than before." << std::endl;
		strength = 20;
		lifeTracker--;
	}
	else if(strength <= damage && lifeTracker == 0)
	{
		//prevents strength from printing out at less than 0
		strength = 0;
	}
	else
	{
		strength -= damage;
	}
	
	//change this creature to the attacker for the next round
	attacker = true;
	
	std::cout << std::endl;
	std::cout << "Player " << p << " " << type << " strength equals " << strength << "." << std::endl;
}

std::string HarryPotter::getCharacter()
{
	return type;
}