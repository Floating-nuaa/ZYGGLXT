#pragma warning(disable : 4996)
#include "MainEntrance.h"
int main() 

{
	MainEntrance mainEntrance;
	
	mainEntrance.ShowThe_First();
	mainEntrance.ShowPre_Login();
	int CMDF=0, CMDS=0, CMDT=0;
	bool flag = 0;
	do
	{
		CMDF=mainEntrance.ShowMain_Menu();

		mainEntrance.DealFirt_Comd(CMDF);
		
		system("pause");

		if (CMDF == 9)
		{
		
			do 
			{
				flag = 0;

				CMDS = mainEntrance.ShowInde_Menu();
				mainEntrance.DealSecn_Comd(CMDS);
				system("pause");

				if (CMDS == 0)
				{
					flag = 1;
					continue;
				}
				if (CMDS == 12) 
				{
					do 
					{

						CMDT = mainEntrance.ShowMang_Menu();
						system("pause");

					} while (CMDT != 0);
				}
				

			}while(CMDS != 0);
			
			if (flag) 
			{
				continue;
			}
		}

	}while(CMDF!=0);
	
	if (!CMDF) 
	{
		cout << " 感谢您使用本系统" << endl;

	}
	
	return 0;
	
}






