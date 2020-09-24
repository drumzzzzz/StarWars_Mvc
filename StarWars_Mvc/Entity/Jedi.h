#include <string>
#include <iostream>
#include "ForceBeing.h"

// Jedi inherits ForceBeing
class Jedi : public ForceBeing
{
public:
	Jedi(string jediName, int level) : ForceBeing(level)
	{
		setName(jediName);
		setGood();
	}

	int getPowerLevel()
	{
		return ForceBeing::getPowerLevel();
	}

	string getName()
	{
		return "Jedi\t" + ForceBeing::getName();
	}

	void setRank(int rank)
	{
		ForceBeing::setRank(rank);
	}

	int getRank()
	{
		return ForceBeing::getRank();
	}
};