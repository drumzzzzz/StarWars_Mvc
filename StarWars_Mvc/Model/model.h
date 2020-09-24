#include <string>
#include "../Entity/Jedi.h"
#include "../Entity/Sith.h"
#include "../Entity/ForceBeing.h"
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
    // Employee johnSmith = Employee("John Smith", "920-227-3248", 18, "id-abc-123");
    // SalesLead judySmith = SalesLead("Judy Smith", "920-227-3249", 19, "Apple");
    // Personal bruceSpringsteen = Personal("Bruce Springsteen", "920-227-3249", 19, "BFF");

    template <typename T>
    T IsMatch(T level1, T level2)
	{
        return (level1 == level2) ? true : false;
    }

    vector <Sith> sith_entities;
    vector <Jedi> jedi_entities;
	
public:

    Model()
    {
        sith_entities.push_back(Sith("Darth Vader", 100));
        jedi_entities.push_back(Jedi("Luke Skywalker", 90));
        jedi_entities.push_back(Jedi("Yoda", 100));
    }
	
    string getName()
    {
        return "";
    	
    }

	vector<string> sortLevels()
    {
        vector<string> sorted;
        int rank = 1;
        bool isRank = false;

    	for (int level = MAX_LEVEL; level > 0; level--)
    	{
            if (isRank)
            {
                isRank = false;
                rank++;
            }
    		
            for (Jedi j : jedi_entities)
            {
                if (IsMatch(j.getPowerLevel(), level))
                {
                    // sorted.push_back(to_string(rank) + "\t" + j.getName() + "\t" + to_string(j.getPowerLevel()));
                    sorted.push_back(FormatString(rank, j.getPowerLevel(), j.getName()));
                    isRank = true;
                }
            }
    		
    		for (Sith s : sith_entities)
    		{
                if (IsMatch(s.getPowerLevel(), level))
                {
                    //sorted.push_back(to_string(rank) + "\t" + s.getName() + "\t" + to_string(s.getPowerLevel()));
                    sorted.push_back(FormatString(rank, s.getPowerLevel(), s.getName()));
                    isRank = true;
                }
    		}

    		if (sorted.size() == jedi_entities.size() + sith_entities.size())
                break;
    	}

    	for(string sval : sorted)
    	{
            cout << sval << endl;
    	}

        return sorted;
    }

	vector<string> getSithInfo()
    {
        //vector<string> vs;
    	
        //for (Sith s : sith_entities)
        //{
	       // vs.push_back(s)
        //}
    	
    }

    vector<string> getJediInfo()
    {

    }
	
 //   string sithName()
	//{
 //       return darthVader.getName();
 //   }
 //   string jediName()
	//{
 //       return lukeSkyWalker.getName();
 //   }
};