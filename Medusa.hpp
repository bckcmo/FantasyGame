/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the header file for the Medusa class.
*/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Die.hpp"
#include "validateInput.hpp"

#define DEATH 100;

class Medusa : public Creature
{
private:

public:
	int attack(std::string p);
	void defend(int attackRoll, std::string p);
	std::string getCharacter();
};

#endif