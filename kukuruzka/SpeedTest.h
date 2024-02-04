#pragma once


#include "Keyboard.h"

void TimeCount(int& seconds) {
	seconds++;
	this_thread::sleep_for(chrono::seconds(1));
}

class SpeedTest { //��� ������ ���������� ������������ ������ �������
	vector<char> TextSymbols;
	string text = " ";
	int BukwaKey = 0; //������ � ������� ����
	int TimeSeconds = 0;
	int seconds = 0;
	bool Mistake = 0;
	int Mistake_Count = 0;
	int Tap_Count = 0;
	float speedtextclear = 0;
	float speedtext = 0;
	float Prosent_Result;
	int mistake_key;


	void KBOut() {
		for (size_t i = 0; i < kb.size(); i++)
		{
			for (size_t j = 0; j < kb[i].size(); j++)
			{
				if (text[BukwaKey] == kb[i][j].name_klik)
				{
					kb[i][j].out(Blue_White);
				}
				else
				{
					kb[i][j].out(White);
				}
			}
			cout << endl;
		}
		
	}


	void Out() {
		for (size_t i = 0; i < TextSymbols.size(); i++)
		{

			if (Mistake == true)
			{
				if (i == mistake_key && BukwaKey == mistake_key)
				{
					SetConsoleTextAttribute(hand, WORD(BACKGROUND_GREEN));
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
				else if (i >= mistake_key && i < BukwaKey)
				{
					SetConsoleTextAttribute(hand, Red);
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
				else if (i == BukwaKey)
				{
					SetConsoleTextAttribute(hand, WORD(BACKGROUND_RED));
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
				else
				{
					cout << TextSymbols[i];
				}
			}
			else //Mistake == false
			{
				if (i == BukwaKey)
				{
					SetConsoleTextAttribute(hand, WORD(BACKGROUND_GREEN));
					cout << TextSymbols[i];
					SetConsoleTextAttribute(hand, White);
				}
				else
				{
					cout << TextSymbols[i];
				}
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
				
				if (k == 8)
				{
					BukwaKey--;
					Tap_Count--;
				}
				else
				{
					if (Mistake == false)
					{
						if (k == TextSymbols[BukwaKey])
						{
							//Mistake = false;
						}
						else
						{
							Mistake = true;
							Mistake_Count++;
							mistake_key = BukwaKey;
						}
					}
					else
					{
						if (mistake_key == BukwaKey)
						{
							if (k == TextSymbols[BukwaKey])
							{
								Mistake = false;
							}
						}
						
					}
					BukwaKey++;
				}

				Tap_Count++;
				Prosent_Result = 100 - (Mistake_Count * 100 / Tap_Count);
				if (BukwaKey >= TextSymbols.size())
				{
					if (BukwaKey <= 0)
					{
						BukwaKey++;
					}
					else
					{
						break;
					}
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
		speedtext = float(text.size()) / float(seconds) * float(60);
		cout << "���� �������� ���������� " << fixed << setprecision(2) << speedtext << " �������� � ������" << endl;
		cout << "�������� - " << Prosent_Result << endl;
 	}

	void Get_Text() {
		string text1 = "������ ������ ���� ����� ������ ���������� ����������� ���. � ������ �������� � ���-������ ��� ���� � ����� ������ ������ 3 ������������, ����� ����� ������ ����� �� �� ������������. ���� ������ ��������� ������� ������� ������, ���� �� ������ ������ ����-���������. ����� ��� 70 % ��������� ������� ������� �� ������� ������ ��������. � ������ ������ ���� �� 40 ������� ����� �������. ���� ��������� ����� ������� ��� ����.";
		string text2 = "�������� ��������� ��� �����. ����������� ������ ���� � ���� - �������� ������ ����. ������������ �������� ���������� � ������� 15 ��������� ������� �������� ����� � �������. ���� �������� ����� ������������� �� ���� �� 150�� ����. ���� ����� ���� ������ �� ���������� 25 ��. ��������� ����� ����� ������� �������� 160 ���������� � ���.";
		string text3 = "������ ������ �������� ������� � ���� ������ �������, ��� �����. ������� �������� � ������������ ���� ������������ �� ��������� �������� 90 ������ � �������. ������ � ������� �������� �������� ��� �������� ������������ ����. � ����� ��� ������� - ���� ��� ����, ������ ��� ����. ���������� ����� 100 ��������� �������, ���������� �������.";
		string text4 = "����� �� ������� ��� ���� �������� ����! �-�, ���������� �����. ������� ��� ������, ����������! � ���� ��� ������ �����. �� � ��� ��� � ������� ������ �� ������ �������? �������� �������... �� � �� ������. ��� �� ���� ���������? � �� �� ������! ������� ������ ����. ���������, ��������. �� ���� ���������, ��������.";
		string text5 = "����������! �� ��� ������ � ���������� �����������. ���� ������! �� ��� ������ �������������, ��� � ���� �� ������ �������. ����� ���� �����. � �������� ���� ��������, ������ �� ���������. � ������ ������������� - ��������� �����. ������� ��������, �� �� ����, �� �� ����, �� �� ����, �� �� ����, �� �� ����, ����� ���������? ��. ����������� ���� �� ����������. ����� ����������� �����, ���� �� ���������� ����� ��������.";
		string text6 = "����� ���� � ��� ������! ��� ����� ������. � ������ ���� �� ���������? � ���� ��� �� � ������� ������? ��? ��������� �������. ��, �����, �����. ������ ������ �� �����. �������, ����� ��������� ���� ������. ��, ���! �������� ��������� ������! �� ����� ���� ����, ����� �������� �����������! ��� � ������ �����, ����� ��� ���������. � ����� ��� ����� ������ ����������, ��� �� � ������ ����� ����. ������ ����� �������� ��������, � ����������� - ����� ������.";
		string text7 = "��� ���� ������� �����, ������ ������� ����. ����� ���� � �����, ����� ���� � ����, ����� � ������ � ����, ������� � ����. ���������� �� ����� ���� ��� ����������� ��� ����������. ���� ���� � �������� �� ����� �� �����. ����, ������ ������� ��������, ����� �������� ����� ���. ������ � ���, �� ������ - ������� ������. ���, �� ����� �� � ���.";
		int Random_Text_Chouse = rand() % 7 + 1;
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
		case 4:
			text = text4;
			break;
		case 5:
			text = text5;
			break;
		case 6:
			text = text6;
			break;
		case 7:
			text = text7;
			break;
		default:
			break;
		}
	}
public:
	void start() {
		Get_Text();
		
		for (size_t i = 0; i < text.size(); i++)
		{
			TextSymbols.push_back(text[i]);
		}
		go();
	}
};


