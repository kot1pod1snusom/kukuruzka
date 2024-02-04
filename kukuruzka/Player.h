#pragma once

#include "Includes.h"


class Player {

	Player(string name, string login, string password, int Max_SpeedTest_Result, int All_SpeedTest_Results, int Count_SpeedTests, double Average_SpeedTest_Result) {
		this->name = name;
		this->login = login;
		this->password = password;
		this->Max_SpeedTest_Result = Max_SpeedTest_Result;
		this->All_SpeedTest_Results = All_SpeedTest_Results;
		this->Count_SpeedTests = Count_SpeedTests;
		this->Average_SpeedTest_Result = Average_SpeedTest_Result;

	}



	void Rigistr() {
		cout << "������� ���" << endl;
		cin >> name;
		cout << "������� �����" << endl;
		cin >> login;
		cout << "������� ������ " << endl;
		cin >> password;
	}	

	void Check_SpeedTest_Result(int speed_text_result) {
		Count_SpeedTests++; 
		if (Max_SpeedTest_Result < speed_text_result)
		{
			Max_SpeedTest_Result = speed_text_result;
		}
		All_SpeedTest_Results += speed_text_result;
		Average_SpeedTest_Result = All_SpeedTest_Results / Count_SpeedTests;
	}


private:
	string name;
	string login;
	string password;
	int Max_SpeedTest_Result;
	int All_SpeedTest_Results;
	int Count_SpeedTests;
	double Average_SpeedTest_Result;
		
};


//void GetPlayersFromFile() {
//	ofstream out;
//	out.open("PlayerFile.csv");
//	if (out.is_open())
//	{
//		int Count_File = 0; //����� ������ � ����� 
//		string str = "";
//		while (getline(out, str))
//		{
//		}		
//	}
//}


vector<Player> list_player;












