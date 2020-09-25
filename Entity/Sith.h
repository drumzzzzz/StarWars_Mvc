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
		return ForceBeing::getPowerLevel();
	}

	string getName()
	{
		return "Sith\t" + ForceBeing::getName();
	}

	string sgetName()
	{
		return ForceBeing::getName();
	}
};