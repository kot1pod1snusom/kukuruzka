#pragma once


#include "Keyboard.h"

void TimeCount(int& seconds) {
	seconds++;
	this_thread::sleep_for(chrono::seconds(1));
}

class SpeedTest { //Для вывода клавиатуры использовать курсок позицию
	vector<char> TextSymbols;
	string text = " ";
	int BukwaKey = 0; //индекс в массиве букв
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
		cout << "Точность на данный момент равна " << Prosent_Result << endl;
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
		cout << "Ваша скорость составляет " << fixed << setprecision(2) << speedtext << " сивмовол в минуту" << endl;
		cout << "Точность - " << Prosent_Result << endl;
 	}

	void Get_Text() {
		string text1 = "Сердце белого кита имеет размер автомобиля Фольксваген Жук. В городе Крескилл в Нью-Джерси все коты и кошки должны носить 3 колокольчика, чтобы птицы всегда знали об их расположении. Если желтую канарейку кормить красным перцем, цвет ее перьев станет ярко-оранжевым. Более чем 70 % населения планеты никогда не слышали звонка телефона. В Африке только один из 40 человек имеет телефон. Язык хамелеона вдвое длиннее его тела.";
		string text2 = "Бегемоты рождаются под водой. Большинство частиц пыли в доме - отмершие клетки кожи. Человеческий организм производит и убивает 15 миллионов красных кровяных телец в секунду. Одна пчелиная семья заготавливает за лето до 150кг меда. Гром может быть слышен на расстоянии 25 км. Хоккейная шайба может развить скорость 160 километров в час.";
		string text3 = "Правое легкое человека вмещает в себя больше воздуха, чем левое. Нервные импульсы в человеческом теле перемещаются со скоростью примерно 90 метров в секунду. Первый в истории одеколон появился как средство профилактики чумы. У пчелы два желудка - один для меда, другой для пищи. Существует более 100 различных вирусов, вызывающих насморк.";
		string text4 = "Какая же гадость эта ваша заливная рыба! О-о, тепленькая пошла. Потрите мне спинку, пожалуйста! У меня там ценный веник. Ну а как Вас в самолет сажали Вы должны помнить? Ппомнить ддолжен... но я не ппомню. Что вы меня поливаете? Я же не клумба! Нашлись добрые люди. Подогрели, обобрали. То есть подобрали, обогрели.";
		string text5 = "Поздравляю! Ты уже начала в транспорте знакомиться. Черт побери! Вы так вкусно рассказываете, что у меня аж слюнки потекли. Ждите меня здесь. В квартиру всех впускать, никого не выпускать. В случае сопротивления - открывать огонь. Георгий Иванович, он же Гога, он же Гоша, он же Юрий, он же Гора, он же Жора, здесь проживает? Да. Интеллектом явно не изуродован. Чтобы генеральшей стать, надо за лейтенанта замуж выходить.";
		string text6 = "Какие люди и без охраны! Это комок нервов. А шнурки тебе не погладить? А чего это вы в темноте сидите? Мы? Телевизор смотрим. Ну, ладно, ладно. Москва слезам не верит. Кажется, вечер перестает быть томным. Ну, все! Засосало мещанское болото! Не учите меня жить, лучше помогите материально! Все в Москву лезут, будто она резиновая. В сорок лет жизнь только начинается, это уж я теперь точно знаю. Иногда такую глупость услышишь, а оказывается - точка зрения.";
		string text7 = "Мне надо принять ванну, выпить чашечку кофе. Будет тебе и ванна, будет тебе и кофа, будет и какава с чаем, поехали к шефу. Шампанское по утрам пьют или аристократы или дегенераты. Наши люди в булочную на такси не ездят. Сеня, быстро объясни товарищу, зачем Володька сбрил усы. Будете у нас, на Колыме - милости просим. Нет, уж лучше вы к нам.";
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


