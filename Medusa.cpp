/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/06/2017
*Description: This is the implementation file for the Medusa class.
*/

#include <iostream>
#include "Medusa.hpp"

//methods

/*
*The attack method for medusa calls rollDie() from the attackDie object. It then checks if the roll is equal to 12.
*If it is equal to 12, medusa applies glare and returns a constant that holds a number large enough to 
*kill any possible opponent. If the roll is not equal to 12, it returns the roll.
*It also changes the attacker vairiable to false so that the program knows it is medusa's turn to defend.
*/
int Medusa::attack(std::string p)
{
	int roll = this->attackDie->rollDie();
	
	if(roll == 12)
	{
		std::cout << std::endl;
		std::cout << "The defender has looked Mudusa in the eyes!" << std::endl;
		std::cout << "Medusa uses Glare." << std::endl;
		std::cout << std::endl;
		return DEATH;
	}
	else
	{
		roll += armor;
		std::cout << "Player " << p << " " << type << " rolled a defense of "  << roll << "." << std::endl;
		//add armor to roll
		roll += armor;
		std::cout << "Player " << p << " " << type << " has " << armor << " armor." << std::endl; 
		std::cout << "Player " << p << " " << type << "'s " << "total defense is "<< roll << "." << std::endl;
		//change this creature to the defender for the next round
		attacker = false;
		return roll;
	}
}

/*
*The defend method for medusa calls rollDie() from the defenseDie object and then adds the armor value to the roll.
*Then the total damage is subtracted from the medusa's strength points. 
*Lastly, the attacker variable is changed to true so that the program knows it is medusa's turn to attack.
*/
void Medusa::defend(int attackRoll, std::string p)
{
	//declare variable to hold the total damage the creature must take from the attack
	int damage;
	int roll = this->defenseDie->rollDie() + armor;
	std::cout << "Player " << p << " " << type << " rolled a defense of "  << roll << "." << std::endl;
	
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
}

std::string Medusa::getCharacter()
{
	return type;
}