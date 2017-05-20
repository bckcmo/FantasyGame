/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/11/2017
*Description: This is the header file for the Creature class.
*/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <string>
#include "Die.hpp"
#include "validateInput.hpp"

class Creature
{
protected:
	int armor;
	int strength;
	Die* defenseDie;
	Die* attackDie;
	std::string player;
	std::string type;
	bool attacker;
public:
	virtual ~Creature();
	virtual int attack(std::string p) = 0;
	virtual void defend(int attackRoll, std::string p) = 0;
	int getStrength();
	virtual std::string getCharacter() = 0;
	void setData(std::string p, std::string t, int attackNum, int attackSides, int defNum, int defSides, int a, int s);
	void setAttacker(bool attack);
	bool getAttacker();
};

#endif