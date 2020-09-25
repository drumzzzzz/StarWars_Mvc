// StarWars_Mvc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Controller/controller.h"

int main()
{
    Controller controller;
    controller.updateView(controller.sortEntities(), controller.getJediWinners(), controller.getSithWinners());
}
