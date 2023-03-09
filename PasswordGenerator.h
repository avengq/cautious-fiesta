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

	int PasswordSize;
	bool YesOrNo;
	std::string FinishPass;

	void generatePassword(int N);

	
};

