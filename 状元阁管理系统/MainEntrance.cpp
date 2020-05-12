#include "MainEntrance.h"

MainEntrance :: MainEntrance(){}
MainEntrance::~MainEntrance(){}

void MainEntrance::ShowPre_Login() 
{
	PremaryMenu *PM;
	PM = new PremaryMenu;
	PM->display();
	delete PM;
	PM = NULL;
	
	LoginMenu* LM;
	LM = new LoginMenu;
	LM->display();
	delete LM;
	LM = NULL;
}
