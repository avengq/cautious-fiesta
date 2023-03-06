#pragma once
#include <string>

class PasswordGenerator
{
public:

	PasswordGenerator();
	int Run(int PassSize, bool SpecChar);

	std::string printPassword();

	void savePassword();
private:

	char* Password;
	int PasswordSize;
	bool YesOrNo;
	std::string FinishPass;

	void shuffle(char* arr, int N);

	void generatePassword(char* arr, int N);

	
};

