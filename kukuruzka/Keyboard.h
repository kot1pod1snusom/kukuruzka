#pragma once
#include "Includes.h"

class KB_Buttion {
public:

	string name_out; //Что выводится 
	char name_klik;  //Что нужно нажать

	KB_Buttion(char name_klik, string name_out) : name_klik(name_klik), name_out(name_out) {}

	void out(int color) {
		Help_Out(color);
	}

private:
	
	void Help_Out(int color) {
		SetConsoleTextAttribute(hand, color);
		cout << name_out;
		SetConsoleTextAttribute(hand, White);
		cout << " ";
	}
};

vector<vector<KB_Buttion>> kb;

void GetKeyboardFromFile() {
	ifstream out;
	out.open("Keyboard.txt");
	if (out.is_open())
	{
		string str;
		int temp_count = 1;
		while (getline(out, str))
		{
	
			vector<KB_Buttion> temp;
			if (temp_count == 4)
			{
				temp.emplace_back(' ', "Space");
	
			}
			else
			{
				for (size_t i = 0; i < str.size(); i++)
				{
					if (str[i] != ' ')
					{
						string st(1, str[i]);
						temp.emplace_back(str[i], st);
					}

				}
			}
			temp_count++;
			kb.push_back(temp);

		}
	}
}





