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
		// ������������� ���������� ��������� �����
		srand(time(NULL));

		// ���������� ��������� ������������
		for (int i = N - 1; i >= 1; i--)
		{
			int j = rand() % (i + 1);
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}

	void generatePassword()
	{
		char alphabet[] = { 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

		char special_chars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '|', '?' };

		srand(time(NULL));
		shuffle(alphabet, sizeof(alphabet));
		random_device rd;
		mt19937 gen(rd());
		


		if (SpecChar) // ���� TRUE �� ������������ ������ � ���������� � ����� ������� ������������ �������.
		{
			for (int i = 0; i < PasswordSize - 1; i++)
			{
				uniform_int_distribution<> dis(0, sizeof(alphabet));
				int value = dis(gen);
				Password[i] = alphabet[value];
			}
			//���������� ������������ ������� � �����
			uniform_int_distribution<> dis(0, sizeof(special_chars));
			int value = dis(gen);
			Password[PasswordSize - 1] = special_chars[value];

			shuffle(Password, PasswordSize); //������������� �������� ������
		}
		else
		{
			for (int i = 0; i < PasswordSize; i++)
			{
				uniform_int_distribution<> dis(0, sizeof(alphabet));
				int value = dis(gen);
				Password[i] = alphabet[value];
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
			cout << "����� �� ����������� ������� � ������? 1 - ��, 0 - ���: ";
			cin >> YesOrNo;
			cout << endl;

			if (YesOrNo == 1 || YesOrNo == 0)
			{
				cout << "������� ����� ������: ";
				cin >> PassSize;
				cout << endl;

				SpecChar = YesOrNo;
				PasswordSize = PassSize;
				Password = new char[PasswordSize];

				generatePassword();

				return 1;
			}
			else
			{
				cout << "�������� ������ ���� ����� 1 ��� 0" << endl << endl;
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
				cout << "������ ������� � ����";
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