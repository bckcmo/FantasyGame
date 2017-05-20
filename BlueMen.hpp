/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the header file for the BlueMen class.
*/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Die.hpp"
#include "validateInput.hpp"

class BlueMen : public Creature
{
private:

public:
	int attack(std::string p);
	void defend(int attackRoll, std::string p);
	std::string getCharacter();
};

#endif