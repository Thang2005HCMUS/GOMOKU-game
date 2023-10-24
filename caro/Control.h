#pragma once
#include<iostream>
#include<Windows.h>
#include"View.h"
#include<conio.h>



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
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { StartGame(); Move(); }
			else {
				break;
			}

		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			GotoXY(80, 15); cout << "X thang!";
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
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




