#include "../Model/model.h"
#include "../View/view.h"

class Controller {
private:
    Model model;
    View view;

public:

 //   string modelEntity()
//    {
 //       return model();
 //   }
	
 //   string modelSithName()
	//{
 //       return model.sithName();
 //   }
 //   string modelJediName()
	//{
 //       return model.jediName();
 //   }

	void updateView()
    {
        model.sortLevels();
    }

    void updateView(string personal, string saleslead, string employee)
	{
        view.printRecord(personal);
        view.printRecord(saleslead);
        view.printRecord(employee);
    }

    static string getWinner(ForceBeing& player1, ForceBeing& player2)
    {
        return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
    }

    static void printWinner(string winner)
    {
        cout << "The winner is: " << winner << endl;
    }
};