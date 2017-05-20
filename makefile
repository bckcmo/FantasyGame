#Program Name: Project 3
#Author: Brendan Corazzin
#Date: 5/05/2017
#Description: This is the makefile for Project 3.


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = main.o validateInput.o menu.o Game.o Creature.o Die.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o waitForKey.o

SRCS = main.cpp validateInput.cpp menu.cpp Game.cpp Creature.cpp Die.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp waitForKey.cpp

HEADERS = validateInput.hpp menu.hpp Game.hpp Creature.hpp Die.hpp Vampire.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp waitForKey.hpp

langstonsAnt: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o fantasy
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean: 
	rm *.o fantasy
