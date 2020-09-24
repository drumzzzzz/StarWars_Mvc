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
 //
	vector<string> sortEntities()
	{
		return model.sortLevels();
	}

    vector<string> getWinners()
    {
        return model.getWinners();
    }

	void updateView(vector<string> sortLevels, vector<string> winners)
    {
        view.printValues(sortLevels);
        view.printValues(winners);
    }
};