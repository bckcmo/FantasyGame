/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the implementation file for the Creature class.
*/

#include <iostream>
#include "Creature.hpp"

//destructor
Creature::~Creature()
{
	delete attackDie;
	delete defenseDie;
}

//getters
int Creature::getStrength()
{
	return strength;
}

bool Creature::getAttacker()
{
	return attacker;
}

//setters
//this function sets all of the data variables for each creature
void Creature::setData(std::string p, std::string t, int attackSides, int attackNum, int defSides, int defNum, int a, int s)
{
	player = p;
	type = t;
	attackDie = new Die(attackSides, attackNum);
	defenseDie = new Die(defSides, defNum);
	armor = a;
	strength = s;
}

void Creature::setAttacker(bool attack)
{
	attacker = attack;
}






