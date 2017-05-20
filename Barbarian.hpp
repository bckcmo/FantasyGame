/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/06/2017
*Description: This is the header file for the Barbarian class.
*/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Die.hpp"
#include "validateInput.hpp"

class Barbarian : public Creature
{
public:
	int attack(std::string p);
	void defend(int attackRoll, std::string p);
	std::string getCharacter();
};

#endif