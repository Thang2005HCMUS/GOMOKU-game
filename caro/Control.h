#pragma once
#include<iostream>
#include<Windows.h>
#include"View.h"
#include<conio.h>
#include"Allmenu.h"
#include<vector>
#include"Model.h"



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

void PlayPVP() {
	vector<int> mapx;
	vector<int> mapy;

	
	GotoXY(_X, _Y);

	while (1) {

		GotoXY(_X, _Y);
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'A' or _COMMAND == 75) {
			MoveLeft();
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'W' or _COMMAND == 72) {
			MoveUp();
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'S' or _COMMAND == 80) {
			MoveDown();
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 'D' or _COMMAND == 77) {
			MoveRight();
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (_COMMAND == 27) {
			system("cls");
			break;
		}
		else if (_COMMAND == 13 or _COMMAND == 32) {
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			switch (CheckBoard(_X, _Y)) {
			case -1:
				SetColor(15, 5);
				cout << "X";
				_TURN = false;
				mapx.push_back(_X);
				mapy.push_back(_Y);
				break;
			case 1:
				SetColor(15, 2);
				cout << "O";
				_TURN = true;
				mapx.push_back(_X);
				mapy.push_back(_Y);
				break;
			}

		}
		else if (_COMMAND == 62 && mapx.size() > 0 && mapy.size() > 0) {
			switch (CheckTick(mapx[mapx.size() - 1], mapy[mapy.size() - 1])) {
			case 1:
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
		else if (_COMMAND == 60) {
			Save();
			SaveFileName();
			break;
		}
		else if (_COMMAND == 61) {
			GotoXY(70, 5);
			cout << "Nhap ten file muon choi ";
			GotoXY(70, 6);
			cout << "Nhap cho dung ten gium tui!";
			cin >> filename;
			Load();

			system("cls");
			DrawBoard(BOARD_SIZE, TOP, LEFT);
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					_X = _A[i][j].x;
					_Y = _A[i][j].y;
					GotoXY(_X, _Y);
					if (_A[i][j].c == -1) {
						SetColor(15, 5);
						cout << "X";
					}
					if (_A[i][j].c == 1) {
						SetColor(15, 2);
						cout << "O";

					}
					if (_A[i][j].c == 0) {
						cout << " ";
					}
				}
			}
		}

		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			GotoXY(80, 15); cout << "O thang!";
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { StartGame(); PlayPVP(); break; }
			else {
				break;

			}

		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			GotoXY(80, 15); cout << "X thang!";
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') { StartGame(); PlayPVP();  break; }
			else {
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			GotoXY(80, 25); cout << "Hoa!";  break;
		}
	}

}

void Newgame() {
	system("cls");
	int s[2] = { 4,0 };
	int getkey = -1;
	int count = 1;

	while (1) {

		SetColor(15, s[0]);
		GotoXY(50, 13);
		cout << "1.Play vs Player";

		SetColor(15, s[1]);
		GotoXY(50, 14);
		cout << "2.Play vs Computer";

		getkey = toupper(_getch());
		if (getkey == 'W' && count == 2) {
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			count--;
		}
		if (getkey == 'S' && count == 1) {
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			count++;
		}
		if (getkey == 13) {
			if (count == 1) {
				system("cls");
				StartGame();
				PlayPVP();
				system("cls");
				break;
				
			}
			if (count == 2) {
				system("cls");
				StartGame();
				PlayPVP();
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
	system("cls");
	string name;
	int line = 0;
	GotoXY(50, 5);
	cout << "LIST FILE NAME:";

	ifstream SaveName("filename.txt");
	string read;
	while (getline(SaveName, read)) {
		GotoXY(50, 6 + line);
		cout << "-" << read;
		line++;
	}
	SaveName.close();
	GotoXY(50, 20);
	cout << "Enter the file name: ";
	cin >> name;
	ifstream SaveName1("filename.txt");
	string read1;
	
	while (getline(SaveName1, read1)) {
		if (read1 == name) {
			filename = name;
			system("cls");
			ResetData();
			DrawBoard(BOARD_SIZE, TOP, LEFT);
			Load();
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					_X = _A[i][j].x;
					_Y = _A[i][j].y;
					GotoXY(_X, _Y);
					if (_A[i][j].c == -1) {
						SetColor(15, 5);
						cout << "X";
					}
					if (_A[i][j].c == 1) {
						SetColor(15, 2);
						cout << "O";

					}
					if (_A[i][j].c == 0) {
						cout << " ";
					}
				}
			}
			_X = _A[0][0].x; _Y = _A[0][0].y;
			PlayPVP();

		}
	}
	SaveName1.close();
}



void Menu() {
	system("cls");
	Background();
	HighLight(0, 0, 0, 0, 0);
	
	int set[] = { 4,0,0,0,0 };
	char key;
	int counter = 1;
	while (1) {
		menu_display();
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
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			counter--;
		}
		if ((key == 80 or key == 'S') and (counter >= 1 and counter <= 4)) {
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			counter++;
		}
		if (key == 13) {
			if (counter == 1) {
				Newgame();
			
			}

			if (counter == 2) {
				system("cls");
				Help();
			}
			if (counter == 3) {
				system("cls");
				LoadGame();

				

			}
			if (counter == 4) {
				system("cls");
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

