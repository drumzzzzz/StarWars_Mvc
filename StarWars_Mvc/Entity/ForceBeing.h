#ifndef FORCEBEING_H
#define FORCEBEING_H

#include <iostream>
#include <string>

#define LEVEL_MAX 100
#define LEVEL_MIN 0

using namespace std;

// ForceBeing as abstract class
class ForceBeing
{
private:
	int power_level;
	string name;
	bool evil = false;

protected:
	ForceBeing(int level)
	{
		// Validate
		if (level > LEVEL_MAX)
			level = LEVEL_MAX;
		if (level < LEVEL_MIN)
			level = LEVEL_MIN;
		
		power_level = level;
	}

	virtual void setPowerLevel(int level)
	{
		power_level = level;
	}

	virtual void setName(string characterName)
	{
		name = characterName;
	}

public:
	virtual int getPowerLevel()
	{
		return power_level;
	}

	virtual string getName()
	{
		return name;
	}

	virtual void setEvil()
	{
		evil = true;
	}

	virtual void setGood()
	{
		evil = false;
	}
};
#endif