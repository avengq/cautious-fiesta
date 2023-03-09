#include "PasswordGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <random>


PasswordGenerator::PasswordGenerator()
{
	PasswordSize = 0;
	YesOrNo = true;
	FinishPass = "";
}

int PasswordGenerator::Run(int PassSize, bool SpecChar)
{
	YesOrNo = SpecChar;
	if (YesOrNo == true || YesOrNo == false)
	{
		PasswordSize = PassSize;

		generatePassword(PasswordSize);

		return 1;
	}
}

std::string PasswordGenerator::printPassword()
{
	return FinishPass;
}

void PasswordGenerator::savePassword()
{
	if (!FinishPass.empty())
	{
		std::ofstream outputFile("New Password.txt");

		if (outputFile.is_open())
		{
			outputFile << FinishPass;
			outputFile.close();
			std::cout << "Пароль записан в файл";
		}
	}
}


void PasswordGenerator::generatePassword(int PasswordSize)
{
	char alphabet[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	
	char special_chars[] = { '!', '@', '#', '$', '%', '&', '*', '?' };

	std::random_device rd;
	std::mt19937 gen(rd());

	FinishPass.clear();



	if (YesOrNo) // Если TRUE то генерируется пароль с добавление в конец массива специального символа.
	{
		for (int i = 0; i < PasswordSize; i++)
		{
			std::uniform_int_distribution<> dis(0, sizeof(alphabet));
			int value = dis(gen);
			FinishPass += alphabet[value];
		}
		//Добавление специального символа в конец.
		std::uniform_int_distribution<> dis(0, sizeof(special_chars));
		int value = dis(gen);
		int last = PasswordSize - 1;
		FinishPass[last] = special_chars[value];

	}	
	else
	{
		for (int i = 0; i < PasswordSize; i++)
		{
			std::uniform_int_distribution<> dis(0, sizeof(alphabet));
			int value = dis(gen);
			FinishPass += alphabet[value];
		}
	}
	//std::shuffle(FinishPass.begin(), FinishPass.end(), gen);
	//std::cout << FinishPass << std::endl;
}



