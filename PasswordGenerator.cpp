#include "PasswordGenerator.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <random>

PasswordGenerator::PasswordGenerator()
{
	Password = nullptr;
}

int PasswordGenerator::Run()
{
	int PassSize = 0, YesOrNo = 0;
	while (true)
	{
		std::cout << "Нужны ли специальные символы в пароле? 1 - да, 0 - нет: ";
		std::cin >> YesOrNo;
		std::cout << std::endl;

		if (YesOrNo == 1 || YesOrNo == 0)
		{
			std::cout << "Введите длину пароля: ";
			std::cin >> PassSize;
			std::cout << std::endl;

			SpecChar = YesOrNo;
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

void PasswordGenerator::printPassword()
{
	if (Password != nullptr)
	{
		for (int i = 0; i < PasswordSize; i++)
		{
			std::cout << Password[i];
		}
	}
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



	if (SpecChar) // 
	{
		for (int i = 0; i < N - 1; i++)
		{
			std::uniform_int_distribution<> dis(0, sizeof(alphabet));
			shuffle(alphabet, sizeof(alphabet));
			int value = dis(gen);
			arr[i] = alphabet[value];
		}
		//
		std::uniform_int_distribution<> dis(0, sizeof(special_chars));
		int value = dis(gen);
		arr[N - 1] = special_chars[value];

		shuffle(arr, N); //
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


