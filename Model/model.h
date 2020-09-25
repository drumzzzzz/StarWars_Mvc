#include <string>
#include <vector>
#include "../Entity/Jedi.h"
#include "../Entity/Sith.h"


// Macro functions: calculates highest level per array
#define MaxJedi for (Jedi j : jedi_entities) { if (jedi_max == -1 || j.getPowerLevel() > jedi_max) jedi_max = j.getPowerLevel(); }
#define MaxSith for (Sith s : sith_entities) { if (sith_max == -1 || s.getPowerLevel() > sith_max) sith_max = s.getPowerLevel(); }

// Inline function: returns formatted string of values
inline string FormatString(int rank, int level, string name)
{
    return to_string(rank) + "\t" + to_string(level) + "\t" + name;
}

using namespace std;

class Model
{
private:
	// Template function: returns if two levels are equal
    template <typename T>
    T IsMatch(T level1, T level2)
	{
        return (level1 == level2) ? true : false;
    }

	// Arrays and vars
    vector <Sith> sith_entities;
    vector <Jedi> jedi_entities;
    int ranks = 0;
    int jedi_max = -1;
    int sith_max = -1;
	
public:
    // Constructor: Init entity arrays and max values
    Model()
    {
        sith_entities.push_back(Sith("Darth Vader", 100));
        sith_entities.push_back(Sith("Darth Maul", 80));
        sith_entities.push_back(Sith("Darth Sidious", 95));
        jedi_entities.push_back(Jedi("Luke Skywalker", 90));
        jedi_entities.push_back(Jedi("Yoda", 100));
        jedi_entities.push_back(Jedi("Obi-Wan Kenobi", 80));

        MaxJedi
    	MaxSith
    }

	// Returns an array of entities sorted by rank/level
	vector<string> sortLevels()
    {
        vector<string> sorted;
        ranks = 1;
        bool isRank = false;

        sorted.push_back("Entities sorted and ranked by level:");
        sorted.push_back("Rank\tLevel\tType\tName");
    	
    	for (int level = LEVEL_MAX; level > LEVEL_MIN - 1; level--)
    	{
            if (isRank)
            {
                isRank = false;
                ranks++;
            }
    		
            for (Jedi j : jedi_entities)
            {
                if (IsMatch(j.getPowerLevel(), level))
                {
                    sorted.push_back(FormatString(ranks, j.getPowerLevel(), j.getName()));
                    isRank = true;
                }
            }
    		
    		for (Sith s : sith_entities)
    		{
                if (IsMatch(s.getPowerLevel(), level))
                {
                    sorted.push_back(FormatString(ranks, s.getPowerLevel(), s.getName()));
                    isRank = true;
                }
    		}
    	}

		return sorted;
    }

	// Returns string of highest level Jedi winners and Sith losers
    string getJediWinners()
    {
        string svalue = "Highest Level Jedi(s) (lvl " + to_string(jedi_max) + "):\n";
        bool isWinner = false;

    	for (Jedi j : jedi_entities)
    	{
            if (j.getPowerLevel() == jedi_max)
            {
                svalue.append(j.sgetName() + "\n");
            }
    	}
    	
        svalue.append("Win against Sith(s):\n");
    	
        for (Sith s : sith_entities)
        {
	        if (s.getPowerLevel() < jedi_max)
	        {
                svalue.append(s.sgetName() + "\n");
                isWinner = true;
	        }
        }

        if (!isWinner)
            svalue.append("none\n");
    	
        return svalue;
    }

    // Returns string of the highest level Sith winners and Jedi losers
    string getSithWinners()
    {
        string svalue = "Highest Level Sith(s) (lvl " + to_string(sith_max) + "):\n";
        bool isWinner = false;

        for (Sith s : sith_entities)
        {
            if (s.getPowerLevel() == sith_max)
            {
                svalue.append(s.sgetName() + "\n");
            }
        }

        svalue.append("Win against Jedi(s):\n");

        for (Jedi j : jedi_entities)
        {
            if (j.getPowerLevel() < sith_max)
            {
                svalue.append(j.sgetName() + "\n");
                isWinner = true;
            }
        }

        if (!isWinner)
            svalue.append("none\n");
    	
        return svalue;
    }
};