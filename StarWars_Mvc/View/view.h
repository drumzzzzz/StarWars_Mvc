#include <iostream>
#include <string>

using namespace std;

class View
{
public:
    void printValues(vector<string> svalues)
	{
        cout << "-----" << endl;
    	for (string s : svalues)
			cout << s << endl;
        cout << "-----" << endl;
    }

    void printValues(string svalues)
    {
        cout << "-----" << endl;
        cout << svalues << endl;
        cout << "-----" << endl;
    }
};