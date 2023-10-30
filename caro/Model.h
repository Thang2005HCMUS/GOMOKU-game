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
	
	LoadGame.close();
 }
void SaveFileName() {
	ofstream SaveName;
	SaveName.open("filename.txt",ios::app);
	SaveName << filename << endl;
	SaveName.close();
}