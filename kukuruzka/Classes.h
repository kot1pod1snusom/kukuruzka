#pragma once
#include"Includes.h"



void TimeCount(int& seconds) {
	seconds++;
	this_thread::sleep_for(chrono::seconds(1));
}

class SpeedTest { //��� ������ ���������� ������������ ������ �������
public:
	vector<char> TextSymbols;
	string text = " ";
	int BukwaKey = 0; //������ � ������� ����
	int TimeSeconds = 0;
	int seconds = 0;
	bool Mistake = 0;
	int Mistake_Count = 0;
	int Tap_Count = 0;
	int speedtext = 0;
	float Prosent_Result;

	void KBOut() {
		cout << endl;
		for (size_t i = 0; i < 5; i++)
		{
			cout << endl;
		}

		int d = 0;
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t k = 0; k < 30; k++)
			{
				cout << " ";
			}

			for (size_t k = 0; d < KeyboardOut.size(); d++)
			{
				if (KeyboardOut[d] == '\n' && d != KeyboardOut.size() - 1)
				{
					break;
				}
				else
				{
				
					if (TextSymbols[BukwaKey] == KeyboardOut[d])
					{

						SetConsoleTextAttribute(hand, BACKGROUND_BLUE);
						cout << KeyboardOut[d] <<  " ";
						SetConsoleTextAttribute(hand, White);
					}
					else
					{
						cout << KeyboardOut[d] << " ";
						SetConsoleTextAttribute(hand, White);
					}
					
				}
				
			}
			d++;
			cout << endl;
		}
	}


	void Out() {
		for (size_t i = 0; i < TextSymbols.size(); i++)
		{
			if (BukwaKey == i)
			{
				if (Mistake == true)
				{
					SetConsoleTextAttribute(hand, WORD(BACKGROUND_RED));
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
				else
				{
					SetConsoleTextAttribute(hand, WORD(BACKGROUND_GREEN));
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
			}
			else
			{
				cout << TextSymbols[i];
			}
		}
		cout << endl;
		cout << "�������� �� ������ ������ ����� " << Prosent_Result << endl;
		KBOut();
	}

	void go() {
		BukwaKey = 0;
		Out();
		auto start = chrono::steady_clock::now();
		while (true)
		{
			if (_kbhit())
			{
				SetConsoleCP(1251);
				char k = _getch();
				SetConsoleCP(866);
				if (k == TextSymbols[BukwaKey])
				{
					BukwaKey++;
					Mistake = false;
				}
				else
				{
					Mistake_Count++;
					Mistake = true;
				}

				Tap_Count++;
				Prosent_Result = 100 - (Mistake_Count * 100 / Tap_Count);
				if (BukwaKey >= TextSymbols.size())
				{
					break;
				}
				system("cls");
				Out();
			}
		}
		auto finish = chrono::steady_clock::now();
		auto temp = chrono::duration_cast<chrono::seconds>(finish - start);
		seconds = temp.count();
		system("cls");
		Result();
	}
	 

		

	void Result() {
		speedtext = text.size() / seconds * 60;
		cout << "���� �������� ���������� " << speedtext << " �������� � ������" << endl;
		cout << "�������� - " << Prosent_Result << endl;
	}

	void Get_Text() {
		string text1 = "������ ������ ���� ����� ������ ���������� ����������� ���. � ������ �������� � ���-������ ��� ���� � ����� ������ ������ 3 ������������, ����� ����� ������ ����� �� �� ������������. ���� ������ ��������� ������� ������� ������, ���� �� ������ ������ ����-���������. ����� ��� 70 % ��������� ������� ������� �� ������� ������ ��������. � ������ ������ ���� �� 40 ������� ����� �������. ���� ��������� ����� ������� ��� ����.";
		string text2 = "�������� ��������� ��� �����. ����������� ������ ���� � ���� - �������� ������ ����. ������������ �������� ���������� � ������� 15 ��������� ������� �������� ����� � �������. ���� �������� ����� ������������� �� ���� �� 150�� ����. ���� ����� ���� ������ �� ���������� 25 ��. ��������� ����� ����� ������� �������� 160 ���������� � ���.";
		string text3 = "������ ������ �������� ������� � ���� ������ �������, ��� �����. ������� �������� � ������������ ���� ������������ �� ��������� �������� 90 ������ � �������. ������ � ������� �������� �������� ��� �������� ������������ ����. � ����� ��� ������� - ���� ��� ����, ������ ��� ����. ���������� ����� 100 ��������� �������, ���������� �������.";
		int Random_Text_Chouse = rand() % 3 + 1;
		switch (Random_Text_Chouse)
		{
		case 1:
			text = text1;
			break;
		case 2:
			text = text2;
			break;
		case 3:
			text = text3;
			break;
		default:
			break;
		}
	}

	void start() {
		Get_Text();
	
		//text = "1423523523646223";
		vector<char> vec;
		for (size_t i = 0; i < text.size(); i++)
		{
			TextSymbols.push_back(text[i]);
		}
		go();
	}
};


