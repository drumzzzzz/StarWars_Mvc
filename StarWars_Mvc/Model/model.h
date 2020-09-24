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
	
public:

    Model()
    {
        sith_entities.push_back(Sith("Darth Vader", 100));
        sith_entities.push_back(Sith("Darth Maul", 80));
        sith_entities.push_back(Sith("Darth Sidious", 95));
        jedi_entities.push_back(Jedi("Luke Skywalker", 90));
        jedi_entities.push_back(Jedi("Yoda", 100));
        jedi_entities.push_back(Jedi("Obi-Wan Kenobi", 80));
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
                    j.setRank(ranks);
                    sorted.push_back(FormatString(j.getRank(), j.getPowerLevel(), j.getName()));
                    isRank = true;
                }
            }
    		
    		for (Sith s : sith_entities)
    		{
                if (IsMatch(s.getPowerLevel(), level))
                {
                    s.setRank(ranks);
                    sorted.push_back(FormatString(s.getRank(), s.getPowerLevel(), s.getName()));
                    isRank = true;
                }
    		}

    		if (sorted.size() == jedi_entities.size() + sith_entities.size())
                break;
    	}

		return sorted;
    }

    vector<string> getWinners()
    {
        vector<string> jedi_winners;
        vector<string> sith_winners;
        string svalue;

    	svalue = "The highest level Jedis are: "

    	for (Jedi j : jedi_entities)
    	{
    		if (svalue)
            svalue += j;
    	}

    	
        
        sorted.push_back("Rank\tLevel\tType\tName");

        return sorted;
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