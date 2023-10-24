#pragma once
#include<iostream>
#include<Windows.h>
#include"View.h"
#include<conio.h>
#include"Allmenu.h"



using namespace std;

void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X += 4;
		GotoXY(_X, _Y);
	}
}

void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}

void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

void StartGame() {
	system("cls");

	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE, TOP, LEFT); // Vẽ màn hình
}
void Move() {
	
	GotoXY(_X, _Y);
	while (1) {

		_COMMAND = toupper(_getch());
		if (_COMMAND == 'A' or _COMMAND == 75) MoveLeft();
		else if (_COMMAND == 'W' or _COMMAND == 72) MoveUp();
		else if (_COMMAND == 'S' or _COMMAND == 80) MoveDown();
		else if (_COMMAND == 'D' or _COMMAND == 77) MoveRight();
		else if (_COMMAND == 27) break;
		else if (_COMMAND == 13 or _COMMAND == 32) {

			switch (CheckBoard(_X, _Y)) {
			case -1:
				SetColor(15, 5);
				cout << "X";
				_TURN = false;
				break;
			case 1:
				SetColor(15, 2);
				cout << "O";
				_TURN = true;
				break;
			}

		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			GotoXY(80, 15); cout << "O thang!";
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { StartGame(); Move(); }
			else {
				break;
			}

		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			GotoXY(80, 15); cout << "X thang!";
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { StartGame();  Move(); }
			else {
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			GotoXY(80, 25); cout << "Hoa!";  break;
		}
	}
	
}

void Menu() {
	system("cls");
	Background();
	HighLight(0, 0, 0, 0, 0);

	int set[] = { 4,0,0,0,0 };
	char key;
	int counter = 1;
	while(1) {

		GotoXY(60, 18);
		SetColor(15, set[0]);
		cout << "1.New game";

		GotoXY(60, 19);
		SetColor(15, set[1]);
		cout << "2.Help";

		GotoXY(60, 20);
		SetColor(15, set[2]);
		cout << "3.Load game";

		GotoXY(60, 21);
		SetColor(15, set[3]);
		cout << "4.About";

		GotoXY(60, 22);
		SetColor(15, set[4]);
		cout << "5.Exit";

		key = toupper(_getch());

		if ((key == 72 or key == 'W') and (counter >= 2 and counter <= 5)) {
			counter--;
		}
		if ((key == 80 or key == 'S') and (counter >= 1 and counter <= 4)) {
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
				Help();
				Menu();

				break;
			}
			if (counter == 3) {
				system("cls");
				GotoXY(5, 2);
				cout << "Tam thoi chua co!";

				break;

			}
			if (counter == 4) {
				system("cls");
				About();
				Menu();

				break;
			}
			if (counter == 5) {
				system("cls");
				GotoXY(5, 2);
				cout << "Tam thoi chua co!";

				break;
			}
		}
		set[0] = 0;
		set[1] = 0;
		set[2] = 0;
		set[3] = 0;
		set[4] = 0;
		
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
		if (counter == 5) {
			set[4] = 4;
		}
	}
}


