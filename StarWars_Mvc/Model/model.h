#include <string>
#include "../Entity/Jedi.h"
#include "../Entity/Sith.h"
#include <vector>

#define MAX_LEVEL 101
#define MIN_LEVEL 0

inline string FormatString(int rank, int level, string name)
{
    return to_string(rank) + "\t" + to_string(level) + "\t" + name;
}

using namespace std;

class Model
{
private:
    template <typename T>
    T IsMatch(T level1, T level2)
	{
        return (level1 == level2) ? true : false;
    }
	
    vector <Sith> sith_entities;
    vector <Jedi> jedi_entities;
    int ranks;
    int jedi_max;
    int sith_max;
	
public:

    Model()
    {
        sith_entities.push_back(Sith("Darth Vader", 100));
        sith_entities.push_back(Sith("Darth Maul", 80));
        sith_entities.push_back(Sith("Darth Sidious", 95));
        jedi_entities.push_back(Jedi("Luke Skywalker", 90));
        jedi_entities.push_back(Jedi("Yoda", 100));
        jedi_entities.push_back(Jedi("Obi-Wan Kenobi", 80));

    	for (Jedi j : jedi_entities)
    	{
            if (jedi_max == 0 || j.getPowerLevel() > jedi_max)
                jedi_max = j.getPowerLevel();
    	}

        for (Sith s : sith_entities)
        {
            if (sith_max == 0 || s.getPowerLevel() > sith_max)
                sith_max = s.getPowerLevel();
        }
    }

	enum ENTITY_TYPE
    {
	    SITH,
    	JEDI
    };
	
    string getName()
    {
        return "";
    }

	vector<string> sortLevels()
    {
        vector<string> sorted;
        ranks = 1;
        bool isRank = false;

        sorted.push_back("Entities sorted and ranked by level:");
        sorted.push_back("Rank\tLevel\tType\tName");
    	
    	for (int level = MAX_LEVEL; level > 0; level--)
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

    string getJediWinners()
    {
        string svalue = "The Highest Level Jedi(s):\n";
        bool isWinner = false;

    	for (Jedi j : jedi_entities)
    	{
            if (j.getPowerLevel() == jedi_max)
            {
                svalue.append(j.sgetName() + "\n");
            }
    	}
    	
        svalue.append("can win against:\n");
    	
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

    string getSithWinners()
    {
        string svalue = "The Highest Level Sith(s):\n";
        bool isWinner = false;

        for (Sith s : sith_entities)
        {
            if (s.getPowerLevel() == sith_max)
            {
                svalue.append(s.sgetName() + "\n");
            }
        }

        svalue.append("can win against:\n");

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

	int getCount()
    {
        return sith_entities.size() + jedi_entities.size();
    }

	int getCount(ENTITY_TYPE entity_type) 
    {
        (entity_type == JEDI) ? jedi_entities.size() : sith_entities.size();
    }
	
	vector<string> getNames()
    {
        vector<string> names;
    	
        for (Jedi j : jedi_entities)
            names.push_back(j.getName());

        for (Sith s : sith_entities)
            names.push_back(s.getName());

        return names;
    }

    vector<string> getNames(ENTITY_TYPE entity_type)
    {
        vector<string> names;

        if (entity_type == JEDI)
        {
            for (Jedi j : jedi_entities)
                names.push_back(j.getName());
        }
        else
        {
            for (Sith s : sith_entities)
                names.push_back(s.getName());
        }
        return names;
    }

    //static string getWinner(ForceBeing& player1, ForceBeing& player2)
    //{
    //    return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
    //}

    //static void printWinner(string winner)
    //{
    //    cout << "The winner is: " << winner << endl;
    //}
	
};