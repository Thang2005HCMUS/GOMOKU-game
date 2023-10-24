#pragma once
#include<iostream>
#include"Control.h"
#include"View.h"
#include<conio.h>
#include<Windows.h>

using namespace std;

void Help() {
	GotoXY(10, 5);
	cout << "Use A,D,S,W to move.";
	GotoXY(10, 6);
	cout << "Use Enter to tick! ";
	GotoXY(10, 7);
	cout << "<----Press Esc to quit---->";
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) break;
	}
}

void About() {
	GotoXY(10, 5);
	cout << "GROUP 10";
	GotoXY(10, 6);
	cout << "MENBER:";
	GotoXY(10, 7);
	cout << "1.Vu Nguyen Trung Hieu";
	GotoXY(10, 8);
	cout << "2.Doan Quang Thang";
	GotoXY(10, 9);
	cout << "3.Chau Van Minh Khoa";
	GotoXY(10, 10);
	cout << "4.Phan Ngoc Quan";
	GotoXY(10, 11);
	cout << "<----Press Esc to quit---->";
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) break;
	}
}

void Exit() {
	GotoXY(50, 20);
	
}


