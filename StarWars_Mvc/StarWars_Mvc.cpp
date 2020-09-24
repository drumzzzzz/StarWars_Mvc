// StarWars_Mvc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Controller/controller.h"

int main()
{
	// Note: renaming to main.cpp does not require a .replit file
    Controller controller;
    controller.updateView(controller.sortEntities(), controller.getJediWinners(), controller.getSithWinners());
}
