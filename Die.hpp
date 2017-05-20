/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/05/2017
*Description: This is the header file for the Die class.
*/

#ifndef DIE_HPP
#define DIE_HPP
#include <iostream>
#include "Die.hpp"
#include "validateInput.hpp"

class Die
{
private:
	int numDice;
	int dieSides;
public:
	Die(int d, int s);
	int rollDie();
	void decNumDice();
	int getNumDice();
};

#endif