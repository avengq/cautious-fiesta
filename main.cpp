#include <iostream>
#include "PasswordGenerator.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "RU");
	
	
	PasswordGenerator pg;
	
	

	pg.Run();
	pg.printPassword();

	


}