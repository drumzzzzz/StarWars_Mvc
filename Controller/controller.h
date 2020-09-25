#include "../Model/model.h"
#include "../View/view.h"

class Controller {
private:
    Model model;
    View view;

public:
	vector<string> sortEntities()
	{
		return model.sortLevels();
	}

    string getJediWinners()
    {
        return model.getJediWinners();
    }

    string getSithWinners()
    {
        return model.getSithWinners();
    }

	void updateView(vector<string> sortLevels, string jediwinners, string sithwinners)
    {
        view.printValues(sortLevels);
        view.printValues(jediwinners);
        view.printValues(sithwinners);
    }
};