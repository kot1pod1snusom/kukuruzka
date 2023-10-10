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