#include <iostream>
#include <string>

using namespace std;

class View
{
public:
	// Display a string value
    void printValues(string svalues)
    {
        cout << endl;
        cout << svalues << endl;
    }

	// Overloaded function: Iterate and display an arrays values
    void printValues(vector<string> svalues)
    {
        cout << endl;
        for (string s : svalues)
            cout << s << endl;
    }
};