/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the implementation file for the Vampire class.
*/

#include <iostream>
#include "Vampire.hpp"

//methods

/*
*The attack method for vampire calls rollDie() from the attackDie object and then returns this value.
*It also changes the attacker vairiable to false so that the program knows it is vampire's turn to defend.
*/
int Vampire::attack(std::string p)
{
	int roll = this->attackDie->rollDie();
	std::cout << "Player " << p << " " << type << " rolled an attack of "  << roll << "." << std::endl;
	attacker = false;
	return roll;
}

/*
*The defend method for vampire calls rollDie() from the defenseDie object and then adds the armor value to the roll.
*Then the function genereates a 1 or 0 randomly. If 0 returns, the vampire uses charm and no damage is recorded.
*Otherwise, the total damage is subtracted from the vampire's strength points. 
*Lastly, the attacker variable is changed to true so that the program knows it is vampire's turn to attack.
*/
void Vampire::defend(int attackRoll, std::string p)
{	
	int charm = (rand () % 2);
	
	if(charm == 1)
	{
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
		
		std::cout << std::endl;
		std::cout << "Player " << p << " " << type << " strength equals " << strength << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "The Vampire has charmed you! Your attack was blocked!" << std::endl;
		std::cout << "Player " << p << " " << type << " strength is still equal to " << strength << std::endl;
	}
	//change this creature to the attacker for the next round
	attacker = true;
}

std::string Vampire::getCharacter()
{
	return type;
}
