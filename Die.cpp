/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/05/2017
*Description: This is the implementation file for the Game class.
*/

#include <iostream>
#include <cstdlib>
#include "Die.hpp"
#include "validateInput.hpp"

//constructor
Die::Die(int d, int s)
{
	numDice = d;
	dieSides = s;
}

//setters
void Die::decNumDice()
{
	numDice -= 1;
}

//getters
int Die::getNumDice()
{
	return numDice;
}

//methods
int Die::rollDie()
{
	
	int roll = 0;
	int totalRoll = 0;
	int counter = 0;
	
	//roll ALL of the character's dice and add total together. Return total.
	while(this->numDice > counter)
	{
		roll = (rand () % dieSides + 1);
		totalRoll += roll;
		counter++;
	}
	
	return totalRoll;
}