#pragma once
#include<iostream>
#include"Control.h"
#include"View.h"
#include<conio.h>
#include"Allmenu.h"
#include<fstream>
#include<string>

using namespace std;

void Save() {
	GotoXY(70, 5);
	cout << "Nhap ten file de luu: ";
	cin >> filename;
	ofstream SaveGame(filename);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			SaveGame << _A[i][j].c << " ";
		}
		SaveGame << endl;
	}
	SaveGame << player1;
	SaveGame << endl;
	SaveGame << x1 << " " << win1 << " " << " " << lose1 << " " << draw1 << endl;
	SaveGame << player2 << endl;
	SaveGame << x2 << " " << win2 << " " << lose2 << " " << draw1 << endl;

	SaveGame.close();
}



void Load() {
	ifstream LoadGame;
	LoadGame.open(filename);
	
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			LoadGame >> _A[i][j].c;
		}
	}
	LoadGame >> player1;
	LoadGame >> x1; LoadGame >> win1; LoadGame >> lose1; LoadGame >> draw1;
	LoadGame >> player2;
	LoadGame >> x2; LoadGame >> win2; LoadGame >> lose2; LoadGame >> draw2;
	LoadGame.close();
 }


void SaveFileName() {
	ofstream SaveName;
	SaveName.open("filename.txt",ios::app);
	SaveName << filename << endl;
	SaveName.close();
}