#include "TEAInfo.h"
#include <string>

TEAInfo::TEAInfo(string Name)
{
	string temp = ".dat";
	string FM = Name + temp;
	uniqueAddress = "TEAInfo\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

TEAInfo::TEAInfo() 
{
	uniqueAddress = "TEAInfo\\";
	fileName = "testTeacher.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}


TEAInfo::~TEAInfo(){}