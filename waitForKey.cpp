/*
*Program Name: Project 3
*Author: Brendan Corazzin
*Date: 4/20/2017
*Description: This is the waitForKey function implementation file.
*/

#include <iostream>
#include "waitForKey.hpp"

/*
*The waitForKey function pauses the terminal and continues once the user has pressed any key.
*Code taken from http://stackoverflow.com/questions/7410447/why-getch-returns-before-press-any-key
*/
void waitForKey()
{
		struct termios oldT,newT;

		tcgetattr(fileno(stdin),&oldT);
		tcgetattr(fileno(stdin),&newT);
		cfmakeraw(&newT);
		tcsetattr(fileno(stdin),TCSANOW,&newT);
		fflush(NULL);
		fgetc(stdin);
		tcsetattr(fileno(stdin),TCSANOW,&oldT);
}