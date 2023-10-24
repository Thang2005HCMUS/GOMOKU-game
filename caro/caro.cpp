#include<iostream>
#include"Control.h"
#include"View.h"
#include<conio.h>
#pragma once 

using namespace std;


void Menu() {
	system("cls");
	Background();
	HighLight(0, 0, 0, 0, 0);

	int set[] = { 4,0,0,0 };
	char key;
	int counter = 1;
	for (int i;;) {

		GotoXY(60, 18);
		SetColor(15, set[0]);
		cout << "1.New game";

		GotoXY(60, 19);
		SetColor(15, set[1]);
		cout << "2.Help";

		GotoXY(60, 20);
		SetColor(15, set[2]);
		cout << "3.Option";

		GotoXY(60, 21);
		SetColor(15, set[3]);
		cout << "4.Exit";

		key = toupper(_getch());

		if ((key == 72 or key == 'W') and (counter >= 2 and counter <= 4)) {
			counter--;
		}
		if ((key == 80 or key == 'S') and (counter >= 1 and counter <= 3)) {
			counter++;
		}
		if (key == 13) {
			if (counter == 1) {
				StartGame();
				Move();
				Menu();
				break;
			}
			if (counter == 2) {
				system("cls");
				GotoXY(5, 2);
				cout << "Help cc";
				
				break;
			}
			if (counter == 3) {
				system("cls");
				GotoXY(5, 2);
				cout << "Cai dat cc";
				
				break;

			}
			if (counter == 4) {
				system("cls");
				GotoXY(5, 2);
				cout << "Khong cho thoat!";
				
				break;
			}

		}
		set[0] = 0;
		set[1] = 0;
		set[2] = 0;
		set[3] = 0;
		if (counter == 1) {
			set[0] = 4;
		}
		if (counter == 2) {
			set[1] = 4;
		}
		if (counter == 3) {
			set[2] = 4;
		}
		if (counter == 4) {
			set[3] = 4;
		}
	}

}


void main() {
	Menu();
	_getch();
}