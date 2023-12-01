#pragma once
#include<iostream>
#include"View.h"
#include<conio.h>
#include"Allmenu.h"
#include<vector>
#include"Model.h"
#include"Graphics.h"

using namespace std;
void Menu();// in ra menu tren ma hinh
void LoadGame();// che do load game da luu
void Newgame(); //hien thi lua chon choi voi may hay choi voi nguoi
void PlayPVC();// choi voi may
void PlayPVP(); //ham choi voi nguoi

//ham di chuyen sang phai
void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X += 4;
		GotoXY(_X, _Y);
	}
}
//ham di chuyen sang trai
void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
//ham si chuyen xuong
void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
//ham di chuyen len
void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

void PlayPVP() {
	bool turn = _TURN;
	vector<int> mapx;
	vector<int> mapy;
	UnNocursortype();
	GotoXY(73, 29);
	SetColor(15, 4);
	cout << "Press T to turn ON/OFF sound!";
	SetColor(15, 0);
	sound_op2();

	GotoXY(108, 29);
	SetColor(15, 1);
	if (sound) cout << "SOUND: ON ";
	else cout << "SOUND: OFF";
	SetColor(15, 0);
	SetColor(15, 2);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
	cout << "Player2: " << player2;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
	cout << "Step:" << x2 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
	cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";

	SetColor(15, 5);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
	cout << "Player1: " << player1;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
	cout << "Step:" << x1 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
	cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
	while (1) {
		if (_TURN == false) {
			GotoXY(LEFT + 4 * BOARD_SIZE + 34, 3);
			cout << "O TURN ";
		}
		if (_TURN == true) {
			GotoXY(LEFT + 4 * BOARD_SIZE + 34, 3);
			cout << "X TURN ";
		}
		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'A' or _COMMAND == 75) {
			MoveLeft();
			if(sound)  PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'W' or _COMMAND == 72) {
			MoveUp();
			if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'S' or _COMMAND == 80) {
			MoveDown();
			if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'D' or _COMMAND == 77) {
			MoveRight();
			if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'T') {
			if (sound) sound = false;
			else sound = true;
			GotoXY(108, 29);
			SetColor(15, 1);
			if (sound) cout << "SOUND: ON ";
			else cout << "SOUND: OFF";
			SetColor(15, 0);
		}
		else if (_COMMAND == 27) {
			system("cls");
			x1 = 0;   x2 = 0;
			win1 = 0; win2 = 0;
			lose1 = 0;	lose2 = 0;
			draw1 = 0; draw2 = 0;
			break;
		}
		else if (_COMMAND == 13 or _COMMAND == 32) {
			if(sound) PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			switch (CheckBoard(_X, _Y)) {
			case -1:
				SetColor(15, 5);
				cout << "X";
				//
				_TURN = false;
				x1++;
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
				cout << "Player1: " << player1;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
				cout<< "Step:" << x1 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
				mapx.push_back(_X);
				mapy.push_back(_Y);
				break;
			case 1:
				SetColor(15, 2);
				cout << "O";
				//
				x2++;
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";
				_TURN = true;
				mapx.push_back(_X);
				mapy.push_back(_Y);
				break;
			}
		}
		else if (_COMMAND == 62 && mapx.size() > 0 && mapy.size() > 0) {
			switch (CheckTick(mapx[mapx.size() - 1], mapy[mapy.size() - 1])) {
			case 1:
				x2--;
				SetColor(15, 2);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";
				GotoXY(mapx[mapx.size() - 1], mapy[mapy.size() - 1]);
				cout << " ";
				_X = mapx[mapx.size() - 1];
				_Y = mapy[mapy.size() - 1];
				GotoXY(_X, _Y);
				if (mapx.size() > 1 && mapy.size() > 1) {
					mapx.erase(mapx.begin() + mapx.size() - 1);
					mapy.erase(mapy.begin() + mapy.size() - 1);
				}
				_TURN = false;
				for (int i = 0; i < BOARD_SIZE; i++) {
					for (int j = 0; j < BOARD_SIZE; j++) {
						if (_A[i][j].x == _X && _A[i][j].y == _Y) {
							_A[i][j].c = 0;
						}
					}
				}
				break;
			case -1:
				x1--;
				SetColor(15, 5);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
				cout << "Player1: " << player1;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
				cout << "Step:" << x1 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
				GotoXY(mapx[mapx.size() - 1], mapy[mapy.size() - 1]);
				cout << " ";
				_X = mapx[mapx.size() - 1];
				_Y = mapy[mapy.size() - 1];
				GotoXY(_X, _Y);
				if (mapx.size() > 1 && mapy.size() > 1) {
					mapx.erase(mapx.begin() + mapx.size() - 1);
					mapy.erase(mapy.begin() + mapy.size() - 1);
				}

				_TURN = true;

				for (int i = 0; i < BOARD_SIZE; i++) {
					for (int j = 0; j < BOARD_SIZE; j++) {
						if (_A[i][j].x == _X && _A[i][j].y == _Y) {
							_A[i][j].c = 0;
						}
					}
				}
				break;
			}
		}
		else if (_COMMAND == 59) {
			StartGame();
			GotoXY(73, 29);
			SetColor(15, 4);
			cout << "Press T to turn ON/OFF sound!";
			SetColor(15, 0);
			sound_op2();

			GotoXY(108, 29);
			SetColor(15, 1);
			if (sound) cout << "SOUND: ON ";
			else cout << "SOUND: OFF";
			SetColor(15, 0);
			x1 = 0;
			x2 = 0;
			_TURN = turn;
		}
		else if (_COMMAND == 60) {
			SavePVP();
		}
		else if (_COMMAND == 61) {
			GotoXY(78, 5);
			cout << "                                           ";
			GotoXY(78, 5);
			cout << "Enter the file name : ";
			cin >> filename;
			ifstream check;
			check.open("filename.txt");
			string read;
			bool kt = 0;
			while (getline(check, read)) {
				if (filename == read) {
					kt = 1;
					GotoXY(78, 5);
					cout << "                                           ";
					Load();
				}
			}
			if (option == "PVC" and kt==1) {
				GotoXY(LEFT + 4 * BOARD_SIZE + 34, 3);
				cout << "               ";
				PlayPVC();
				break;
			}
			else if(kt==0) 
			{
				GotoXY(78, 5);
				cout << "                                           ";
				GotoXY(78, 5);
				cout << "Wrong! press F3 to try again!";
			}
			check.close();
			
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			owin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			SetColor(15, 0);
			Nocursortype();
			srand(time(0));
			while (1) {
				if (_kbhit()) {
					break;
				}
				
				SetColor(15, rand() % 7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win2++;
				lose1++;
				StartGame(); PlayPVP(); break; }
			else {
				system("cls");
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}	
		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			xwin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			SetColor(15, 0);
			Nocursortype();
			srand(time(0));
			while (1) {
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { 
				win1++;
				lose2++;
				StartGame(); PlayPVP();  break; }
			else {
				system("cls");
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			draw();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				draw1++;
				draw2++;
				StartGame(); PlayPVP();  break;

			}
			else break;
		}
	}

}

void PlayPVC() {
	vector<int> mapx;
	vector<int> mapy;
	UnNocursortype();
	GotoXY(73, 29);
	SetColor(15, 4);
	cout << "Press T to turn ON/OFF sound!";
	SetColor(15, 0);
	sound_op2();

	GotoXY(108, 29);
	SetColor(15, 1);
	if (sound) cout << "SOUND: ON ";
	else cout << "SOUND: OFF";
	SetColor(15, 0);

	bool turn = _TURN;
	SetColor(15, 2);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
	cout << "Player2: " << player2;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
	cout << "Step:" << x2 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
	cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";

	SetColor(15, 5);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
	cout << "Player1: " << player1;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
	cout << "Step:" << x1 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
	cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
	SetColor(15, 0);
	while (1) {
		if (_TURN) {

			GotoXY(_X, _Y);
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'A') {
				MoveLeft();
				if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'W') {
				MoveUp();
				if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'S') {
				MoveDown();
				if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'D') {
				MoveRight();
				if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'T') {
				if (sound) sound = false;
				else sound = true;
				SetColor(15, 1);
				GotoXY(108, 29);
				if (sound) cout << "SOUND: ON ";
				else cout << "SOUND: OFF";
				SetColor(15, 0);
			}
			else if (_COMMAND == 27) {
				system("cls");
				x1 = 0;   x2 = 0;
				win1 = 0; win2 = 0;
				lose1 = 0;	lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
			// Danh co
			else if (_COMMAND == 13) {
				if(sound) PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				switch (CheckBoard(_X, _Y)) {
				case -1:
					SetColor(15, 5);
					cout << "X";
					mapx.push_back(_X);
					mapy.push_back(_Y);
					x1++;//tang diem 
					SetColor(15, 5);
					GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
					cout << "Player1: " << player1;
					GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
					cout << "Step:" << x1 << " ";
					GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
					cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
					SetColor(15, 2);
					GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
					cout << "Player2: " << player2;
					GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
					cout << "Step:" << x2 << " ";
					GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
					cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";
					_TURN = false;
					break;
				}
			}
			//NEW GAME
			else if (_COMMAND == 59) {
				StartGame();
				GotoXY(73, 29);
				SetColor(15, 4);
				cout << "Press T to turn ON/OFF sound!";
				SetColor(15, 0);
				sound_op2();

				GotoXY(108, 29);
				SetColor(15, 1);
				if (sound) cout << "SOUND: ON ";
				else cout << "SOUND: OFF";
				SetColor(15, 0);
				x1 = 0;
				x2 = 0;
				_TURN = turn;
			}
			//SAVE
			else if (_COMMAND == 60) {
				SavePVC();
			}
			//LOAD
			else if (_COMMAND == 61) {
				GotoXY(78, 5);
				cout << "                                           ";
				GotoXY(78, 5);
				cout << "Enter the file name : ";
				cin >> filename;
				ifstream check;
				bool kt = 0;
				check.open("filename.txt");
				string read;
				while (getline(check, read)) {
					if (filename == read) {
						kt = 1;
						GotoXY(78, 5);
						cout << "                                           ";
						Load();
					}
				}
				if (option == "PVP" and kt==1) {

					PlayPVP();
					break;
				}
				else if(kt==0)
				{
					GotoXY(78, 5);
					cout << "                                           ";
					GotoXY(78, 5);
					cout << "Wrong! press F3 to try again!";
				}
			
				check.close();
					
			}
			//UNDO
			else if (_COMMAND == 62 && mapx.size() > 0 && mapy.size() > 0) {
				GotoXY(mapx[mapx.size() - 1], mapy[mapy.size() - 1]);
				cout << " ";
				_X = mapx[mapx.size() - 1];
				_Y = mapy[mapy.size() - 1];
				GotoXY(_X, _Y);
				//xoa toa do cuoi cung
				if (mapx.size() > 1 && mapy.size() > 1) {
					mapx.erase(mapx.begin() + mapx.size() - 1);
					mapy.erase(mapy.begin() + mapy.size() - 1);
				}
				// dat lai trang thai cho o vua xoa
				for (int i = 0; i < BOARD_SIZE; i++) {
					for (int j = 0; j < BOARD_SIZE; j++) {
						if (_A[i][j].x == _X && _A[i][j].y == _Y) {
							_A[i][j].c = 0;
						}
					}
				}
				if (x1 > 0) x1--;
				//xoa luon quan o da danh
				GotoXY(mapx[mapx.size() - 1], mapy[mapy.size() - 1]);
				cout << " ";
				_X = mapx[mapx.size() - 1];
				_Y = mapy[mapy.size() - 1];
				GotoXY(_X, _Y);
				if (mapx.size() > 1 && mapy.size() > 1) {
					mapx.erase(mapx.begin() + mapx.size() - 1);
					mapy.erase(mapy.begin() + mapy.size() - 1);
				}
				for (int i = 0; i < BOARD_SIZE; i++) {
					for (int j = 0; j < BOARD_SIZE; j++) {
						if (_A[i][j].x == _X && _A[i][j].y == _Y) {
							_A[i][j].c = 0;
						}
					}
				}
				if (x2 >= 1) x2--;
				SetColor(15, 5);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
				cout << "Player1: " << player1;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
				cout << "Step:" << x1 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
				SetColor(15, 2);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2;
				_TURN = true;
			}
		}
		//kiem tra khi player danh
		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			if (turn == true) _TURN = false;
			else _TURN = true;
			turn = _TURN;
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			owin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			Nocursortype();
			while (1) {
				
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win2++;
				lose1++;
				StartGame(); PlayPVC(); break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			if (turn == true) _TURN = false;
			else _TURN = true;
			turn = _TURN;
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			xwin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			Nocursortype();
			while (1) {
				
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win1++;
				lose2++;
				StartGame(); PlayPVC();  break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			draw();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				draw1++;
				draw2++;
				StartGame(); PlayPVP();  break;

			}
			else break;
		}
		if (!_TURN) {
			
			int dem = 0;
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (_A[i][j].c == 0) {
						dem += 1;
					}
				}
			}
			if (dem == BOARD_SIZE * BOARD_SIZE - 1) {
				MoveRight();
				SetColor(15, 2);
				CheckBoard(_X, _Y);
				x2++;
				cout << "O";
				SetColor(15, 2);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";
				_TURN = true;
			}
			else if (dem == BOARD_SIZE * BOARD_SIZE) {
				_X = (BOARD_SIZE * 4 / 2) - 3;
				_Y = (BOARD_SIZE * 2 / 2) - 1;
				CheckBoard(_X, _Y);
				GotoXY(_X, _Y);
				SetColor(15, 2);
				cout << "O";
				x2++;
				SetColor(15, 2);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";
				_TURN = true;
			}
			else {
				_X = Tim_Kiem_NuocDi().x;
				_Y = Tim_Kiem_NuocDi().y;
				CheckBoard(_X, _Y);
				GotoXY(_X, _Y);
				SetColor(15, 2);
				cout << "O";
				x2++;
				SetColor(15, 2);
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<< " ";
				mapx.push_back(_X);
				mapy.push_back(_Y);

				_TURN = true;
			}
		}
		// kiem tra sau khi computer danh
		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			if (turn == true) _TURN = false;
			else _TURN = true;
			turn = _TURN;
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			owin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			Nocursortype();
			while (1) {
				
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() %7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win2++;
				lose1++;
				StartGame(); PlayPVC(); break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			if (turn == true) _TURN = false;
			else _TURN = true;
			turn = _TURN;
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			xwin();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			Nocursortype();
			while (1) {
				
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 7 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win1++;
				lose2++;
				StartGame(); 
				PlayPVC(); 
				break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 32, 15);
			draw();
			SetColor(15, 4);
			GotoXY(85, 25); cout << "PRESS Y TO CONTINUE!";
			GotoXY(85, 26); cout << "PRESS ANY KEY TO OUT!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				draw1++;
				draw2++;
				StartGame(); PlayPVP();  break;

			}
			else break;
		}
	}
}

void Newgame() {
	system("cls");
	XO_Graphic();
	menu_display();
	Remote_Graphic();
	int getkey = -1;
	int getkey1 = -1;
	int getkey2 = -1;
	int count = 1;
	int count1 = 1;
	int count2 = 1;
	int s[2] = { 4,0 };
	int ss[2] = { 4,0 };
	int sss[2] = { 4,0 };
	while (1) {
		
		SetColor(15, 0);
		box_newgame();
		GotoXY(42, 29);
		cout << "<----------Press Esc to return menu-------->";
		SetColor(15, s[0]);
		GotoXY(58, 17);
		cout << "Play vs Player";

		SetColor(15, s[1]);
		GotoXY(58, 23);
		cout << "Play vs Computer";

		getkey = toupper(_getch());
		if (getkey == 'W' && count == 2) {
			if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			count--;
		}
		if (getkey == 'S' && count == 1) {
			if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			count++;
		}
		if (getkey == 27) {
			system("cls");
			break;
		}
		if (getkey == 13) {
			
			if (count == 1) {
				system("cls");
				Remote_Graphic();
				GotoXY(20, 10);
				UnNocursortype();
				cout << "Player1 name: ";
				cin >> player1;
				GotoXY(20, 12);
				cout << "Player2 name: ";
				cin >> player2;
				Nocursortype();
				while (1) {
					SetColor(15, 0);
					box_newgamepvp();
					SetColor(15, ss[0]);
					GotoXY(20, 17);
					cout << "-Player1 go first (X)";

					SetColor(15, ss[1]);
					GotoXY(20, 21);
					cout << "-player2 go first (O)";

					getkey1 = toupper(_getch());
					if (getkey1 == 'W' && count1 == 2) {
						if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						count1--;
					}
					if (getkey1 == 'S' && count1 == 1) {
						if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						count1++;
					}
					if (getkey1 == 13) {
						if (count1 == 1) {
							_TURN = true;
							break;
						}
						if (count1 == 2) {
							_TURN = false;
							break;
						}
					}
					ss[0] = 0;
					ss[1] = 0;
					if (count1 == 1) {
						ss[0] = 4;
					}
					if (count1 == 2) {
						ss[1] = 4;
					}
				}
				StartGame();
				PlayPVP();
				system("cls");
				break;
			}
			if (count == 2) {
				system("cls");
				Remote_Graphic();
				GotoXY(20, 10);
				SetColor(15,0);
				UnNocursortype();
				cout << "Player name: ";
				cin >> player1;
				player2 = "COMPUTER";
				Nocursortype();
				while (1) {
					SetColor(15, 0);
					box_newgamepvc();
					SetColor(15, sss[0]);
					GotoXY(20, 17);
					cout << "-Player go first (X)";

					SetColor(15, sss[1]);
					GotoXY(20, 21);
					cout << "-Computer go first (O)";

					getkey2 = toupper(_getch());
					if (getkey2 == 'W' && count2 == 2) {
						if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						count2--;
					}
					if (getkey2 == 'S' && count2 == 1) {
						if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
						count2++;
					}
					if (getkey2 == 27) {
						system("cls");
						break;
					}
					if (getkey2 == 13) {
						if (count2 == 1) {
							_TURN = true;
							break;

						}
						if (count2 == 2) {
							_TURN = false;
							break;
						}
					}
					sss[0] = 0;
					sss[1] = 0;
					if (count2 == 1) {
						sss[0] = 4;
					}
					if (count2 == 2) {
						sss[1] = 4;
					}
				}
				StartGame();
				PlayPVC();
				system("cls");
				break;
			}
		}
		s[0] = 0;
		s[1] = 0;
		if (count == 1) {
			s[0] = 4;
		}
		if (count == 2) {
			s[1] = 4;
		}
	}
}

void LoadGame() {
	UnNocursortype();
	system("cls");
	Remote_Graphic();
	listgame_Graphic();
	string name;
	int line = 0;
	GotoXY(50, 5);
	cout << "LIST FILE NAME:";

	ifstream SaveName("filename.txt");
	string read;
	while (getline(SaveName, read)) {
		ifstream Option;
		Option.open(read);
		Option >> _TURN;
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				Option >> _A[i][j].c;
			}
		}
		Option >> player1;
		Option >> x1; Option >> win1; Option >> lose1; Option >> draw1;
		Option >> player2;
		Option >> x2; Option >> win2; Option >> lose2; Option >> draw2;

		Option >> option;
		Option.close();
		GotoXY(50, 6 + line);
		cout << "-" << read;
		GotoXY(73, 6 + line);
		cout << "(" << option << ")";
		line++;
	}
	SaveName.close();
	x1 = 0;
	x2 = 0;
	win1 = 0, lose1 = 0, draw1 = 0;
	win2 = 0, lose2 = 0, draw2 = 0;
	GotoXY(50, 20);
	cout << "Enter the file name: ";
	cin >> name;
	ifstream SaveName1("filename.txt");
	string read1;
	int countall = 0, callfail = 0;
	while (getline(SaveName1, read1)) {
		countall++;
		if (read1 == name) {
			filename = name;
			system("cls");
			Load();
			_X = _A[0][0].x; _Y = _A[0][0].y;
			if (option == "PVP") {
				PlayPVP();
				system("cls");
				break;
			}
			else if (option == "PVC") {
				PlayPVC();
				system("cls");
				break;
			}
		}
		else callfail++;
	}
	if (callfail == countall) {
		system("cls");
		GotoXY(55, 17);
		cout << "FILE NOT EXIT!";
		Sleep(2000);
		system("cls");
	}
	SaveName1.close();
}


void Menu() {
	system("cls");
	Background();
	HighLight(0, 0, 0, 0, 0);
	
	int set[] = { 4,0,0,0,0,0 };
	char key;
	int counter = 1;
	while (1) {
		Nocursortype();
		menu_display();
		Remote_Graphic();
		XO_Graphic();
		box_menu();
		sound_op1();
		GotoXY(83, 28);
		cout << "Press W and S to move up and down";
		GotoXY(89, 29);
		cout << "Press Enter to chose";
		GotoXY(86, 30);

		cout << "Press T to turn ON/OFF sound";
		GotoXY(17, 29);
		if (sound)    cout << "SOUND: ON ";
		else cout << "SOUND: OFF";
		GotoXY(60, 17);
		SetColor(15, set[0]);
		cout << "New Game";

		GotoXY(62, 20);
		SetColor(15, set[1]);
		cout << "Help";

		GotoXY(59, 23);
		SetColor(15, set[2]);
		cout << "Load game";

		GotoXY(62, 26);
		SetColor(15, set[3]);
		cout << "About";

		GotoXY(62, 29);
		SetColor(15, set[4]);
		cout << "Exit";

		key = toupper(_getch());

		if ((key == 72 or key == 'W') and (counter >= 2 and counter <= 5)) {
			if(sound) if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			counter--;
		}
		if ((key == 80 or key == 'S') and (counter >= 1 and counter <= 4)) {
			if (sound) if(sound) PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			counter++;
		}
		if (key == 'T') {
			if (sound)  sound = false;
			else sound = true;
		}
		if (key == 13) {
			if (counter == 1) {
				Newgame();
			}

			if (counter == 2) {
				system("cls");
				Remote_Graphic();
				Help();
			}
			if (counter == 3) {
				system("cls");
				LoadGame();
			}
			if (counter == 4) {
				system("cls");
				Remote_Graphic();
				About();
			}
			if (counter == 5) {
				system("cls");
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

