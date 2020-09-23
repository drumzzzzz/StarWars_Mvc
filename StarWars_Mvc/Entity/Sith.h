#include <string>
#include <iostream>
#include "../Entity/ForceBeing.h"

// Sith inherits ForceBeing
class Sith : public ForceBeing
{
public:
	Sith(string sithName, int level) : ForceBeing(level)
	{
		setName(sithName);
		setGood();
	}

	int getPowerLevel()
	{
		return ForceBeing::getPowerLevel() + 1;
	}

	string getName()
	{
		return "Sith Lord: " + ForceBeing::getName();
	}
};