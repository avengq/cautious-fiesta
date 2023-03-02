#pragma once
class PasswordGenerator
{
public:

	PasswordGenerator();
	int Run();

	void printPassword();

	void savePassword();
private:

	char* Password;
	int PasswordSize = 0;
	bool SpecChar = true;

	void shuffle(char* arr, int N);

	void generatePassword(char* arr, int N);

	
};

