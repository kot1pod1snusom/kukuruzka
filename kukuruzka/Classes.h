#pragma once

#include"Includes.h"

class SpeedTest {
public:
	vector<char> TextSymbols;
	string text;
	int BukwaKey;

	void Out() {
		for (size_t i = 0; i < TextSymbols.size(); i++)
		{
			if (BukwaKey == i)
			{
				SetConsoleTextAttribute(hand, Red);
				cout << TextSymbols[i];
				SetConsoleTextAttribute(hand, White);
			}
			else
			{
				cout << TextSymbols[i];
			}
		}
	}

	void go() {
		BukwaKey = 0;
		Out();
		while (BukwaKey != TextSymbols.size())
		{
			if (_kbhit())
			{
				SetConsoleCP(1251);
				char k = _getch();
				SetConsoleCP(866);
				if (k == TextSymbols[BukwaKey])
				{
					BukwaKey++;
					system("cls");
					Out();
				}
			}
		}
	}

	void GetText() {
		fstream out;
		out.open("text.txt");
		if (out.is_open())
		{
			string str;
			while (getline(out, str))
			{
				text += str;
			}
		}
	}


	void start() {
		//GetText();
		text = "����� ���������������� ���� - ���������. � ������ �� ������������������ - ���������. ����������� �� ��������� �������� ������. �������� ���������� � ������������� ����. ������������� ����-���� ���� �������. ������� �������� 75% ����� �� ���. �������� ���� � ����� �������� ������. ����� ���� ������ �������� ����� �����.";
		vector<char> vec;
		for (size_t i = 0; i < text.size(); i++)
		{
			TextSymbols.push_back(text[i]);
		}
		go();
	}
};