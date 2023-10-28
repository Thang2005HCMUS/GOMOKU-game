#pragma once
#include<iostream>
#include<Windows.h>
#include"Control.h"
#include<conio.h>
using namespace std;


#define BOARD_SIZE 15
#define LEFT 1									 
#define TOP 1	

struct _POINT {
	int x, y, c;
};
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X;
int _Y;

void GotoXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int backgound_color, int text_color) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}


void Background() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	// Đặt màu nền cho toàn bộ console thành màu trắng
	FillConsoleOutputAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
}

void HighLight(int x, int y, int w, int h, int color) {
	SetColor(color, color);
	for (int i = x; i < x + w; i++)
		for (int j = y; j < y + h; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	SetColor(15, 0);

}

// ham ve bang
void DrawBoard(int _size, int _top, int _left) {
	GotoXY(1, 1);
	HighLight(0, 0, 0, 0, 0);
	for (int i = 1; i <= _left + 4 * _size; i++)
	{

		if (i == 1) putchar(201);
		else if (i == _left + 4 * _size) putchar(187);
		else putchar(205);

	}
	for (int i = 2; i <= _top + 2 * _size; i++)
	{
		GotoXY(1, i); putchar(186);
		GotoXY(_left + 4 * _size, i); putchar(186);
	}
	GotoXY(1, _top + 2 * _size);
	for (int i = 1; i <= _left + 4 * _size; i++)
	{
		if (i == 1) putchar(200);
		else if (i == _left + 4 * _size) putchar(188);
		else putchar(205);

	}
	for (int j = 1; j <= _size - 1; j++) {
		GotoXY(2, j * 2 + 1);
		for (int i = 2; i <= _left + 4 * _size - 1; i++) {
			putchar(196);
		}

	}
	for (int j = 1; j <= _size; j++) {
		for (int i = 1; i <= _size - 1; i++) {
			GotoXY(4 * i + 1, 2 * j); putchar(179);
			GotoXY(4 * i + 1, 2 * j + 1); putchar(197);

		}
		GotoXY(2, _top + 2 * _size);
		for (int i = 2; i <= _left + 4 * _size - 1; i++) {
			putchar(205);

		}

	}
}


void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}


int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) //Lượt của người 1 
					_A[i][j].c = -1; //c= -1 tức là người 1
				else _A[i][j].c = 1; //c=1 tức là người chơi
				return _A[i][j].c;
			}
		}
	}
	return 0;
}


void StartGame() {
	system("cls");

	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE, TOP, LEFT); // Vẽ màn hình
}

int CheckTick(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY)
				return _A[i][j].c;
		}
	}
}

// thang thua hoa

int testBoard(int pX, int pY, int _size)
{
	// Xu ly hoa
	bool check = true;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_A[i][j].c == 0)
			{
				check = false;
				break;
			}
		}
	}
	if (check) return 0;

	//Xu ly thang/thua
	int x = 0;
	int y = 0;

	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_A[i][j].x == pX && _A[i][j].y == pY)
			{
				x = i;
				y = j;
				break;
			}
		}
	}

	int res = 0;
	int xStart = (x - 4 > 0) ? x - 4 : 0;
	int yStart = (y - 4 > 0) ? y - 4 : 0;

	int xEnd = (x + 4 >= _size) ? _size - 1 : x + 4;
	int yEnd = (y + 4 >= _size) ? _size - 1 : y + 4;

	int x1, x2, y1, y2;

	for (int i = xStart; i <= x; i++)
	{
		if (i + 4 < _size)
		{
			res = _A[i][y].c + _A[i + 1][y].c + _A[i + 2][y].c
				+ _A[i + 3][y].c + _A[i + 4][y].c;

			x1 = i - 1 >= 0 ? i - 1 : xStart;
			y1 = y;

			x2 = i + 5 >= _size ? x + 4 : i + 5;
			y2 = y;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			pX = i;
			pY = y;
			return 1;
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			pX = i;
			pY = y;
			return -1;
		}
	}

	for (int i = yStart; i <= y; i++)
	{
		if (i + 4 < _size)
		{
			res = _A[x][i].c + _A[x][i + 1].c + _A[x][i + 2].c
				+ _A[x][i + 3].c + _A[x][i + 4].c;

			x1 = x;
			y1 = i - 1 >= 0 ? i - 1 : yStart;

			x2 = x;
			y2 = i + 5 >= _size ? y + 4 : i + 5;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			pX = x;
			pY = i;
			return 1;
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			pX = x;
			pY = i;
			return -1;
		}
	}

	for (int i = xStart; i <= x; i++)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i - j == x - y && i + 4 < _size && j + 4 < _size)
			{
				res = _A[i][j].c + _A[i + 1][j + 1].c + _A[i + 2][j + 2].c
					+ _A[i + 3][j + 3].c + _A[i + 4][j + 4].c;
				x1 = i - 1;
				y1 = j - 1;
				if (x1 < 0 || y1 < 0)
				{
					x1 = i;
					y1 = j;
				}
				x2 = i + 5;
				y2 = j + 5;
				if (x2 >= _size || y2 >= _size)
				{
					y2 = j;
					x2 = i;
				}
			}

			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}

	for (int i = xEnd; i >= x; i--)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i + j == x + y && j + 4 < _size && i - 4 >= 0)
			{
				res = _A[i][j].c + _A[i - 1][j + 1].c + _A[i - 2][j + 2].c
					+ _A[i - 3][j + 3].c + _A[i - 4][j + 4].c;
				x1 = i + 1;
				y1 = j - 1;
				if (x1 >= _size || y1 < 0)
				{
					x1 = i;
					y1 = i;
				}
				x2 = i - 5;
				y2 = j + 5;
				if (x2<0 || y2>_size)
				{
					x2 = i;
					y2 = j;
				}
			}
			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}

	return 2;
}