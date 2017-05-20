/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the header file for the HarryPotter class.
*/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Die.hpp"
#include "validateInput.hpp"

class HarryPotter : public Creature
{
private:
	int lifeTracker = 1;
public:
	int attack(std::string p);
	void defend(int attackRoll, std::string p);
	std::string getCharacter();
};

#endif