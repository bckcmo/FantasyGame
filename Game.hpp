/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 5/05/2017
*Description: This is the header file for the Game class.
*/

#ifndef GAME_HPP
#define GAME_HPP
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "validateInput.hpp"
#include "waitForKey.hpp"

class Game
{
private:
	Creature* pOne;
	Creature* pTwo;
public:
	~Game();
	void play();
	int creatureMenu();
	void fight();
};

#endif