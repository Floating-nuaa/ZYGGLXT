#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "OperateTable.h"
#include "FeasibleCmd.h"
#include "OperateSTD.h"
#include "OperateTEA.h"
#include "Manager.h"
#include "stdafx.h"
#include <time.h>
using namespace std;
int main() 

{

		time_t now;
		int unixTime = (int)time(&now);

		string ans = TimeStampToStandard(unixTime);
		
		cout << ans;
		
		return 0;

}

	