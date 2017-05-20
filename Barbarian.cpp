/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/06/2017
*Description: This is the implementation file for the Barbarian class.
*/

#include <iostream>
#include "Barbarian.hpp"

//methods

/*
*The attack method for Barbarian calls rollDie() from the attackDie object and returns the roll.
*It also changes the attacker vairiable to false so that the program knows it is Barbarian's turn to defend.
*/
int Barbarian::attack(std::string p)
{
	int roll = this->attackDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled an attack of "  << roll << "." << std::endl;
	//change this creature to the defender for the next round
	attacker = false;
	return roll;
}

/*
*The defend method for Barbarian calls rollDie() from the defenseDie object and then adds the armor value to the roll.
*Next, the total damage is subtracted from the Barbarian's strength points. 
*Then the attacker variable is changed to true so that the program knows it is Barbarian's turn to attack.
*/
void Barbarian::defend(int attackRoll, std::string p)
{
	//declare variable to hold the total damage the creature must take from the attack
	int damage;
	int roll = this->defenseDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled a defense of "  << roll << "." << std::endl;
	//add armor to roll
	roll += armor;
	std::cout << "Player " << p << " " << type << " has " << armor << " armor." << std::endl; 
		std::cout << "Player " << p << " " << type << "'s " << "total defense is "<< roll << "." << std::endl;
	
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
	std::cout << "Player " << p << " " << type << " strength equals " << strength << "." << std::endl;
}

std::string Barbarian::getCharacter()
{
	return type;
}
