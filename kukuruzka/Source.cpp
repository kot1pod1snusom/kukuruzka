#include "SpeedTest.h"
#include "Player.h"
#include "Keyboard.h"
SpeedTest speedtest;


void main() {
	SetConsoleTextAttribute(hand, White);
	GetKeyboardFromFile();
	srand(time(NULL));
	setlocale(0, "RUSSIAN");
	speedtest.start();
	
	
	/*for (size_t i = 0; i < 200; i++)
	{
		SetConsoleTextAttribute(hand, i);
		cout << "Hello, word!    " << i << endl;
	}*/



}