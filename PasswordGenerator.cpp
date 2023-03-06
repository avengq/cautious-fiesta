#include "PasswordGenerator.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <random>



PasswordGenerator::PasswordGenerator()
{
	Password = nullptr;
	PasswordSize = 0;
	YesOrNo = true;
	FinishPass = "";
}

int PasswordGenerator::Run(int PassSize, bool SpecChar)
{

	while (true)
	{
		YesOrNo = SpecChar;

		if (YesOrNo == true || YesOrNo == false)
		{
			PasswordSize = PassSize;
			Password = new char[PasswordSize];

			generatePassword(Password, PasswordSize);

			return 1;
		}
		else
		{
			std::cout << "Значение должно быть равно 1 или 0" << std::endl << std::endl;
		}

	}
}

std::string PasswordGenerator::printPassword()
{
	if (Password != nullptr)
	{
		for (int i = 0; i < PasswordSize; i++)
		{
			FinishPass += Password[i];
		}
	}
	return FinishPass;
}

void PasswordGenerator::savePassword()
{
	if (Password != nullptr)
	{
		std::ofstream outputFile("New Password.txt");

		if (outputFile.is_open())
		{
			for (int i = 0; i < PasswordSize; i++)
			{
				outputFile << Password[i];
			}
			outputFile.close();
			std::cout << "Пароль записан в файл";
		}
	}
}


void PasswordGenerator::shuffle(char* arr, int N)
{
	srand(time(NULL));

	for (int i = N - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}
}

void PasswordGenerator::generatePassword(char* arr, int N)
{
	char alphabet[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

	char special_chars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '|', '?' };

	std::random_device rd;
	std::mt19937 gen(rd());

	FinishPass.clear();



	if (YesOrNo) // Если TRUE то генерируется пароль с добавление в конец массива специального символа.
	{
		for (int i = 0; i < N - 1; i++)
		{
			std::uniform_int_distribution<> dis(0, sizeof(alphabet));
			shuffle(alphabet, sizeof(alphabet));
			int value = dis(gen);
			arr[i] = alphabet[value];
		}
		//Добавление специального символа в конец.
		std::uniform_int_distribution<> dis(0, sizeof(special_chars));
		int value = dis(gen);
		arr[N - 1] = special_chars[value];

		shuffle(arr, N); //Перемешивание готового пароля.
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			std::uniform_int_distribution<> dis(0, sizeof(alphabet));
			int value = dis(gen);
			arr[i] = alphabet[value];
		}
	}
}
PasswordGenerator::~PasswordGenerator()
{
	delete[] Password;
}


