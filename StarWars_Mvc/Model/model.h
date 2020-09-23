#include <string>
#include "../Entity/Jedi.h"
#include "../Entity/Sith.h"
//#include "../Person/SalesLead.h"

using namespace std;

class Model
{
private:
    // Employee johnSmith = Employee("John Smith", "920-227-3248", 18, "id-abc-123");
    // SalesLead judySmith = SalesLead("Judy Smith", "920-227-3249", 19, "Apple");
    // Personal bruceSpringsteen = Personal("Bruce Springsteen", "920-227-3249", 19, "BFF");

    Sith darthVader = Sith("Darth Vader", 100);
    Jedi lukeSkyWalker = Jedi("Luke Skywalker", 99);
public:
    string sithName()
	{
        return darthVader.getName();
    }
    string jediName()
	{
        return lukeSkyWalker.getName();
    }
};