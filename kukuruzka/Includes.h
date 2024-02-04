#pragma once


#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <locale>
#include <chrono>
#include <mutex>
#include <thread>
#include <iomanip>

using namespace std;

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);


enum Color {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Yellow = 6,
	White = 7,
	Grey = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightYellow = 13,
	LightWhite = 14,
};

enum Background_Text_color { //Пока здесь те названия , которые мне приглянулись, в будущем думаю можно будет вообще все запихнуть сюда
	//21 - 31 - синий задний фон
	//32 - 47 - зелёный задний фон
	//48 - 63 - голубой задний фон
	//64 - 79 - красный задний фон
	//80 - 95 - фиолетовый задний фон
	//96 - 111 - ораньжевый задний фое
	//122 - 127 - серый задний фон

	Blue_White = 30,	
	Red_White = 71,
	Red_Yellow = 78,



};