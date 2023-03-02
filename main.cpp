#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <random>
#include "PasswordGenerator.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "RU");
	
	
	PasswordGenerator pg;
	
	

	pg.Run();
	pg.printPassword();

	


}