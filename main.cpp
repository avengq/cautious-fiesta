#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <random>

using namespace std;


class PasswordGenerator 
{
private:

	char* Password;
	int PasswordSize = 0;
	bool SpecChar = true;

	int TempSize = 0;

	void shuffle(char* arr, int N)
	{
		// инициализация генератора случайных чисел
		srand(time(NULL));

		// реализация алгоритма перестановки
		for (int i = N - 1; i >= 1; i--)
		{
			int j = rand() % (i + 1);
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}

	void generatePassword(char* arr, int N)
	{
		char alphabet[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

		char special_chars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '|', '?' };

		random_device rd;
		mt19937 gen(rd());
		


		if (SpecChar) // Если TRUE то генерируется пароль с добавление в конец массива специального символа.
		{
			for (int i = 0; i < N - 1; i++)
			{
				uniform_int_distribution<> dis(0, sizeof(alphabet));
				shuffle(alphabet, sizeof(alphabet));
				int value = dis(gen);
				arr[i] = alphabet[value];
			}
			//Добавление специального символа в конец
			uniform_int_distribution<> dis(0, sizeof(special_chars));
			int value = dis(gen);
			arr[N - 1] = special_chars[value];

			shuffle(arr, N); //Перемешивание готового пароля
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				uniform_int_distribution<> dis(0, sizeof(alphabet));
				int value = dis(gen);
				arr[i] = alphabet[value];
			}
		}
	}


public:
	PasswordGenerator()
	{
		Password = nullptr;
	}

	int Run()
	{
		int PassSize = 0, YesOrNo = 0;
		while (true)
		{
			cout << "Нужны ли специальные символы в пароле? 1 - да, 0 - нет: ";
			cin >> YesOrNo;
			cout << endl;

			if (YesOrNo == 1 || YesOrNo == 0)
			{
				cout << "Введите длину пароля: ";
				cin >> PassSize;
				cout << endl;

				SpecChar = YesOrNo;
				PasswordSize = PassSize;
				Password = new char[PasswordSize];

				generatePassword(Password, PasswordSize);

				return 1;
			}
			else
			{
				cout << "Значение должно быть равно 1 или 0" << endl << endl;
			}

		}	
	}

	

	void printPassword()
	{
		if (Password != nullptr)
		{
			for (int i = 0; i < PasswordSize; i++)
			{
				cout << Password[i];
			}
		}
		
	}

	void savePassword()
	{
	
		if (Password != nullptr)
		{
			ofstream outputFile("New Password.txt");

			if (outputFile.is_open())
			{
				for (int i = 0; i < PasswordSize; i++)
				{
					outputFile << Password[i];
				}
				outputFile.close();
				cout << "Пароль записан в файл";
			}
		}
	}
	
};




int main()
{	
	setlocale(LC_ALL, "RU");
	
	
	PasswordGenerator pg;
	
	pg.Run();
	pg.printPassword();

	


}