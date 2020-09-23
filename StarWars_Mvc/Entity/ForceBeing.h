#ifndef FORCEBEING_H
#define FORCEBEING_H

#include <iostream>
#include <string>

using namespace std;

// ForceBeing as abstract class
class ForceBeing
{
private:
	int power_level;
	string name;
	bool evil;

protected:
	ForceBeing(int level)
	{
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