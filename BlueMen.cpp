/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/06/2017
*Description: This is the implementation file for the BlueMen class.
*/

#include <iostream>
#include "BlueMen.hpp"

//methods

/*
*The attack method for BlueMen calls rollDie() from the attackDie object and returns the roll.
*It also changes the attacker vairiable to false so that the program knows it is BlueMen's turn to defend.
*/
int BlueMen::attack(std::string p)
{
	int roll = this->attackDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled an attack of "  << roll << "." << std::endl;
	//change this creature to the defender for the next round
	attacker = false;
	return roll;
}

/*
*The defend method for BlueMen calls rollDie() from the defenseDie object and then adds the armor value to the roll.
*Then the total damage is subtracted from the BlueMen's strength points. 
*Then the function changes the attacker variable to true so that the program knows it is BlueMen's turn to attack.
*Then the function checks the strength and number of defense die for BlueMen. For each 4 strength points lost
*one of the defense die is removed.
*/
void BlueMen::defend(int attackRoll, std::string p)
{
	//declare variable to hold the total damage the creature must take from the attack
	int damage;
	int roll = this->defenseDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled a defense of "  << roll << "." << std::endl;
	//add armor to roll
	roll += armor;
	std::cout << "Player " << p << " " << type << " has " << armor << " armor." << std::endl; 
		std::cout << "Player " << p << " " << type << " " << "total defense is "<< roll << "." << std::endl;
	
	if(attackRoll < roll)
	{
		//if attack is less than defense, no damage was done
		damage = 0;
	}
	else
	{
		//if attack is greater than damage then subtract the difference between the attack and the defense
		damage = attackRoll - roll;
	}
	
	if(strength <= damage)
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
	std::cout << "Player " << p << " " << type << " strength equals " << strength << std::endl;
	std::cout << std::endl;
	
	//for every four points of damage, we must kill off one blue man & decrement numDice by 1
	if(strength <= 8 && defenseDie->getNumDice() == 3)
	{
		std::cout << std::endl;
		std::cout << "Oh no! One of the Blue Men lost all his defense power." << std::endl;
		defenseDie->decNumDice();
		std::cout << "Player " << p << " has " << defenseDie->getNumDice() << " defense dice now." << std::endl;
	}
	else if(strength <= 4 && defenseDie->getNumDice() == 2)
	{
		std::cout << std::endl;
		std::cout << "Oh no! One of the Blue Men lost all his defense power." << std::endl;
		defenseDie->decNumDice();
		std::cout << "Player " << p << " has " << defenseDie->getNumDice() << " defense die now." << std::endl;
	}
}

std::string BlueMen::getCharacter()
{
	return type;
}