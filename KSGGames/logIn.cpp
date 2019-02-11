#include "logIn.h"
#include <fstream>
#include <string>

using namespace std;

bool logIn(string username, string password)
{
	ifstream fileIn("logIn.in");
	string help1, help2;
	fileIn >> help1 >> help2;
	fileIn.close();
	
	if(help1 == username && help2 == password) return true;
	else return false;
}