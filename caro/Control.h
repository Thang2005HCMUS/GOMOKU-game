#pragma once
#include<iostream>
#include<Windows.h>
#include"View.h"
#include<conio.h>
#include"Allmenu.h"
#include<vector>
#include"Model.h"
#include"Graphics.h"
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
	UnNocursortype();
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
			x1 = 0;   x2 = 0;
			win1 = 0; win2 = 0;
			lose1 = 0;	lose2 = 0;
			draw1 = 0; draw2 = 0;
			break;
		}
		else if (_COMMAND == 13 or _COMMAND == 32) {
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1;
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
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2;
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
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
				cout << "Player2: " << player2;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
				cout << "Step:" << x2 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
				cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2;
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
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
				cout << "Player1: " << player1;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
				cout << "Step:" << x1 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1;
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
			x1 = 0;
			x2 = 0;
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
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 30, 15);
			owin();
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			while (1) {
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 15 + 1);
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
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}	
		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 30, 15);
			xwin();
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			while (1) {
				
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 15 + 1);
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
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 0) {
			GotoXY(80, 25); cout << "Hoa!";  break;
		}
	}

}

void PlayPVC() {
	vector<int> mapx;
	vector<int> mapy;
	UnNocursortype();
	GotoXY(_X, _Y);
	ResetData();
	int x, y;
	_TURN = false;
	while (1) {
		switch (_TURN) {
		case 1:
			GotoXY(_X, _Y);
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'A' ) {
				MoveLeft();
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'W' ) {
				MoveUp();
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'S' ) {
				MoveDown();
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (_COMMAND == 'D' ) {
				MoveRight();
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
			else if (_COMMAND == 13 ) {
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				switch (CheckBoard(_X, _Y)) {
				case -1:
					SetColor(15, 5);
					cout << "X";
					mapx.push_back(_X);
					mapy.push_back(_Y);
					x1++;
					GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
					cout << "Player1: " << player1;
					GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
					cout << "Step:" << x1 << " ";
					GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
					cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1;
					x = _X;
					y = _Y;
					_TURN = false;
					break;
				}
			}
			//NEW GAME
			else if (_COMMAND == 59) {
				StartGame();
				x1 = 0;
				x2 = 0;
				_TURN = false;
			}
			//SAVE
			else if (_COMMAND == 60) {
				Save();
				SaveFileName();
				break;
			}
			//LOAD
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
				if(x1>0) x1--;
				GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
				cout << "Player1: " << player1;
				GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
				cout << "Step:" << x1 << " ";
				GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
				cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1;
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
				_TURN = true;
			}
			break;
		case 0: 
			int dem = 0;
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (_A[i][j].c == 0) {
						dem += 1;
					}
				}
			}
			if (dem == BOARD_SIZE * BOARD_SIZE) {
				_X = (BOARD_SIZE * 4 / 2) - 3;
				_Y = (BOARD_SIZE * 2 / 2) - 1;
				CheckBoard(_X, _Y);
				GotoXY(_X, _Y);
				SetColor(15, 2);
				cout << "O";
				_TURN = true;
			}
			else {
				_X = Tim_Kiem_NuocDi().x;
				_Y = Tim_Kiem_NuocDi().y;
				CheckBoard(_X, _Y);
				GotoXY(_X, _Y);
				SetColor(15, 2);
				cout << "O";
				mapx.push_back(_X);
				mapy.push_back(_Y);
				
				_TURN = true;
			}
			break;
		}
		if (testBoard(_X, _Y, BOARD_SIZE) == 1) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 30, 15);
			owin();
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			while (1) {
				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 15 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win2++;
				lose1++;
				StartGame(); PlayPVP(); break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
				break;
			}
		}
		else if (testBoard(_X, _Y, BOARD_SIZE) == -1) {
			x1 = 0;
			x2 = 0;
			HighLight(65, 0, 60, 30, 15);
			xwin();
			GotoXY(80, 25); cout << "Ban co muon tiep tuc choi khong!";
			GotoXY(80, 26); cout << "Bam Y de tiep tuc!";
			while (1) {

				if (_kbhit()) {
					break;
				}
				SetColor(15, rand() % 15 + 1);
				DrawLineWin(_X, _Y);
				Sleep(100);
				SetColor(15, 0);
			}
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'Y') {
				win1++;
				lose2++;
				StartGame(); PlayPVP();  break;
			}
			else {
				win1 = 0; win2 = 0;
				lose1 = 0; lose2 = 0;
				draw1 = 0; draw2 = 0;
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
	Remote_Graphic();
	menu_display();
	int s[2] = { 4,0 };
	int getkey = -1;
	int count = 1;

	while (1) {

		SetColor(15, s[0]);
		GotoXY(55, 16);
		cout << "1.Play vs Player";

		SetColor(15, s[1]);
		GotoXY(55, 17);
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
				GotoXY(20, 10);
				cout << "Player1 name: ";
				getline(cin, player1);
				GotoXY(20, 12);
				cout << "Player2 name: ";
				getline(cin, player2);
				StartGame();
				PlayPVP();
				system("cls");
				break;
				
			}
			if (count == 2) {
				system("cls");
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
	int countall = 0, callfail = 0;
	while (getline(SaveName1, read1)) {
		countall++;
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
						_TURN = false;
					}
					if (_A[i][j].c == 1) {
						SetColor(15, 2);
						cout << "O";
						_TURN = true;

					}
					if (_A[i][j].c == 0) {
						cout << " ";
					}
				}
			}
			_X = _A[0][0].x; _Y = _A[0][0].y;

			PlayPVP();
		}
		else callfail++;
	}
	if (callfail == countall) {
		system("cls");
		GotoXY(55, 20);
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
	
	int set[] = { 4,0,0,0,0 };
	char key;
	int counter = 1;
	while (1) {
		Nocursortype();
		menu_display();
		Remote_Graphic();
		XO_Graphic();

		GotoXY(58, 17);
		SetColor(15, set[0]);
		cout << "1.New Game";

		GotoXY(58, 18);
		SetColor(15, set[1]);
		cout << "2.Help";

		GotoXY(58, 19);
		SetColor(15, set[2]);
		cout << "3.Load game";

		GotoXY(58, 20);
		SetColor(15, set[3]);
		cout << "4.About";

		GotoXY(58, 21);
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

