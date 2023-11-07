#pragma once
#include<iostream>
#include<Windows.h>
#include"Control.h"
#include<conio.h>

using namespace std;

void menu_display() {
	// C (black)
	HighLight(35, 4, 2, 1, 0);
	HighLight(35, 9, 2, 1, 0);
	HighLight(42, 9, 2, 1, 0);
	HighLight(42, 4, 2, 1, 0);
	for (int i = 0; i <= 5; i++)
	{
		HighLight(36 + i, 3, 2, 1, 0);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(34, 5 + i, 2, 1, 0);
	}
	for (int i = 0; i <= 5; i++)
	{
		HighLight(36 + i, 10, 2, 1, 0);
	}
	//chu C ( blue)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(33, 5 + i, 1, 1, 11);
	}

	HighLight(34, 4, 1, 1, 11);
	HighLight(36, 3, 1, 1, 11);
	HighLight(34, 9, 1, 1, 11);
	HighLight(35, 10, 1, 1, 11);
	HighLight(41, 4, 1, 1, 11);
	HighLight(41, 9, 1, 1, 11);
	// chu C ( red)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(36, 5 + i, 1, 1, 4);
	}
	HighLight(37, 4, 1, 1, 4);
	HighLight(37, 9, 1, 1, 4);
	HighLight(44, 4, 1, 1, 4);
	HighLight(43, 3, 1, 1, 4);
	HighLight(44, 9, 1, 1, 4);
	HighLight(43, 10, 1, 1, 4);
	// A (black)
	for (int i = 0; i <= 5; i++) {

		HighLight(50, 10 - i, 2, 1, 0);
	}
	HighLight(51, 4, 2, 1, 0);
	for (int i = 0; i <= 4; i++) {

		HighLight(52 + i, 3, 2, 1, 0);
	}
	HighLight(57, 4, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(58, 10 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {

		HighLight(52 + i, 7, 2, 1, 0);
	}
	// chu A (blue)
	for (int i = 0; i <= 5; i++)
	{
		HighLight(49, 5 + i, 1, 1, 11);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(57, 5 + i, 1, 1, 11);
	}
	HighLight(56, 4, 1, 1, 11);
	HighLight(50, 4, 1, 1, 11);
	HighLight(51, 3, 1, 1, 11);
	//chu A( red) 
	for (int i = 0; i <= 5; i++)
	{
		HighLight(60, 5 + i, 1, 1, 4);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(52, 5 + i, 1, 1, 4);
	}
	HighLight(59, 4, 1, 1, 4);
	HighLight(53, 4, 1, 1, 4);
	HighLight(58, 3, 1, 1, 4);
	// R (black)
	for (int i = 0; i <= 7; i++) {

		HighLight(66, 10 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 6; i++) {

		HighLight(66 + i, 3, 2, 1, 0);
	}
	HighLight(72, 4, 2, 1, 0);
	HighLight(73, 4, 2, 1, 0);
	HighLight(73, 5, 2, 1, 0);
	HighLight(72, 6, 2, 1, 0);
	HighLight(73, 9, 2, 1, 0);
	HighLight(72, 8, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(66 + i, 7, 2, 1, 0);
	}
	HighLight(71, 8, 2, 1, 0);
	HighLight(72, 9, 2, 1, 0);
	HighLight(73, 10, 2, 1, 0);
	// R(blue)
	for (int i = 0; i <= 7; i++)
	{
		HighLight(65, 3 + i, 1, 1, 11);
	}
	HighLight(71, 4, 1, 1, 11);
	HighLight(72, 5, 1, 1, 11);
	HighLight(71, 6, 1, 1, 11);
	HighLight(70, 8, 1, 1, 11);
	HighLight(71, 9, 1, 1, 11);
	HighLight(72, 10, 1, 1, 11);
	// R(red)
	for (int i = 0; i <= 6; i++)
	{
		if (i == 3) {
			continue;
		}
		HighLight(68, 4 + i, 1, 1, 4);
	}
	HighLight(74, 3, 1, 1, 4);
	HighLight(75, 4, 1, 1, 4);
	HighLight(75, 5, 1, 1, 4);
	HighLight(74, 6, 1, 1, 4);
	HighLight(73, 7, 1, 1, 4);
	HighLight(74, 8, 1, 1, 4);
	HighLight(75, 9, 1, 1, 4);
	HighLight(75, 10, 1, 1, 4);

	//O (black)
	for (int i = 0; i <= 3; i++) {

		HighLight(80, 8 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {
		HighLight(82 + i, 3, 2, 1, 0);
	}
	for (int i = 0; i <= 3; i++) {

		HighLight(88, 8 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {
		HighLight(82 + i, 10, 2, 1, 0);
	}
	HighLight(81, 9, 2, 1, 0);
	HighLight(87, 9, 2, 1, 0);
	HighLight(81, 4, 2, 1, 0);
	HighLight(87, 4, 2, 1, 0);
	// O (blue)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(79, 5 + i, 1, 1, 11);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(87, 5 + i, 1, 1, 11);
	}
	HighLight(86, 4, 1, 1, 11);
	HighLight(86, 9, 1, 1, 11);
	HighLight(80, 4, 1, 1, 11);
	HighLight(80, 9, 1, 1, 11);
	HighLight(81, 3, 1, 1, 11);
	HighLight(81, 10, 1, 1, 11);
	// 0 (red)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(82, 5 + i, 1, 1, 4);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(90, 5 + i, 1, 1, 4);
	}
	HighLight(83, 4, 1, 1, 4);
	HighLight(83, 9, 1, 1, 4);
	HighLight(89, 4, 1, 1, 4);
	HighLight(89, 9, 1, 1, 4);
	HighLight(88, 3, 1, 1, 4);
	HighLight(88, 10, 1, 1, 4);

	// logo game 
// BLACK
	//2 thanh d?c
}

void Remote_Graphic() {
	HighLight(78, 16, 2, 6, 0);
	HighLight(110, 16, 2, 6, 0);
	// trên
	HighLight(80, 15, 2, 1, 0);
	HighLight(82, 14, 8, 1, 0);
	HighLight(90, 15, 10, 1, 0);
	HighLight(108, 15, 2, 1, 0);
	HighLight(100, 14, 8, 1, 0);
	//d??i
	HighLight(80, 22, 2, 1, 0);
	HighLight(108, 22, 2, 1, 0);
	HighLight(82, 23, 6, 1, 0);
	HighLight(102, 23, 6, 1, 0);
	HighLight(88, 21, 2, 2, 0);
	HighLight(100, 21, 2, 2, 0);
	HighLight(90, 20, 10, 1, 0);
	//GREY
	HighLight(80, 20, 2, 1, 8);
	HighLight(88, 20, 2, 1, 8);
	HighLight(100, 20, 2, 1, 8);
	HighLight(108, 20, 2, 1, 8);
	HighLight(80, 21, 8, 1, 8);
	HighLight(102, 21, 8, 1, 8);
	HighLight(82, 22, 6, 1, 8);
	HighLight(102, 22, 6, 1, 8);
	//chu thap 4 màu
	HighLight(104, 16, 2, 1, 2);
	HighLight(102, 17, 2, 1, 1);
	HighLight(106, 17, 2, 1, 4);
	HighLight(104, 18, 2, 1, 6);

	//chu thap BLACK
	HighLight(84, 16, 2, 1, 0);
	HighLight(82, 17, 2, 1, 0);
	HighLight(86, 17, 2, 1, 0);
	HighLight(84, 18, 2, 1, 0);
	HighLight(84, 17, 2, 1, 0);

}

void XO_Graphic() {
	// CH? X, O ngoài MENU
		//ch? X
	for (int i = 0; i <= 10; i++) {
		HighLight(14 + 2 * i, 14 + i, 2, 1, 11);
		HighLight(34 - 2 * i, 14 + i, 2, 1, 11);
	}
	// 4 ch? O
	HighLight(22, 23, 2, 1, 4);
	HighLight(24, 22, 2, 1, 4);
	HighLight(24, 24, 2, 1, 4);
	HighLight(26, 23, 2, 1, 4);

	HighLight(22, 15, 2, 1, 4);
	HighLight(24, 14, 2, 1, 4);
	HighLight(24, 16, 2, 1, 4);
	HighLight(26, 15, 2, 1, 4);

	HighLight(30, 19, 2, 1, 4);
	HighLight(32, 18, 2, 1, 4);
	HighLight(32, 20, 2, 1, 4);
	HighLight(34, 19, 2, 1, 4);

	HighLight(14, 19, 2, 1, 4);
	HighLight(16, 18, 2, 1, 4);
	HighLight(16, 20, 2, 1, 4);
	HighLight(18, 19, 2, 1, 4);
}


void xwin() {
	// ch? X

	// black
	for (int i = 0; i <= 8; i++) {
		HighLight(84 + 2 * i, 4 + i, 2, 1, 0);
		HighLight(100 - 2 * i, 4 + i, 2, 1, 0);
	}
	// blue
	for (int i = 0; i <= 8; i++) {
		HighLight(83 + 2 * i, 4 + i, 1, 1, 11);
		HighLight(99 - 2 * i, 4 + i, 1, 1, 11);
	}
	//red
	for (int i = 0; i <= 8; i++) {
		HighLight(86 + 2 * i, 4 + i, 1, 1, 4);
		HighLight(102 - 2 * i, 4 + i, 1, 1, 4);
	}
	//W
	for (int i = 0; i <= 6; i++) {
		HighLight(67 + i, 16 + i, 2, 1, 0);
		HighLight(66 + i, 16 + i, 1, 1, 11);
		HighLight(69 + i, 16 + i, 1, 1, 4);

		HighLight(89 - i, 16 + i, 2, 1, 0);
		HighLight(88 - i, 16 + i, 1, 1, 11);
		HighLight(91 - i, 16 + i, 1, 1, 4);

	}
	for (int i = 0; i <= 2; i++) {
		HighLight(79 + i, 19 + i, 2, 1, 0);
		HighLight(78 + i, 19 + i, 1, 1, 11);
		HighLight(81 + i, 19 + i, 1, 1, 4);

		HighLight(77 - i, 19 + i, 2, 1, 0);
		HighLight(76 - i, 19 + i, 1, 1, 11);
		if (i != 0) {
			HighLight(79 - i, 19 + i, 1, 1, 4);
		}
	}
	//I
	HighLight(95, 16, 2, 7, 0);
	HighLight(94, 16, 1, 7, 4);
	HighLight(97, 16, 1, 7, 11);
	//N

	HighLight(102, 16, 2, 7, 0);
	HighLight(101, 16, 1, 7, 11);
	HighLight(104, 16, 1, 7, 4);

	HighLight(112, 16, 2, 7, 0);
	HighLight(111, 16, 1, 7, 11);
	HighLight(114, 16, 1, 7, 4);

	for (int i = 0; i <= 6; i++) {
		HighLight(104 + i, 16 + i, 2, 1, 0);
		if (i <= 4) {
			HighLight(106 + i, 16 + i, 1, 1, 4);
		}
		if (i >= 2) {
			HighLight(103 + i, 16 + i, 1, 1, 11);
		}

	}

}
void owin() {
	// ch? O
	for (int i = 0; i <= 5; i++) {

		HighLight(88, 11 - i, 2, 1, 0);
		HighLight(87, 11 - i, 1, 1, 11);
		HighLight(90, 11 - i, 1, 1, 4);
	}
	for (int i = 0; i <= 6; i++) {
		HighLight(92 + i, 4, 2, 1, 0);
	}
	for (int i = 0; i <= 5; i++) {

		HighLight(102, 11 - i, 2, 1, 0);
		HighLight(101, 11 - i, 1, 1, 11);
		HighLight(104, 11 - i, 1, 1, 4);
	}
	for (int i = 0; i <= 6; i++) {
		HighLight(92 + i, 13, 2, 1, 0);
	}
	HighLight(89, 12, 4, 1, 0);
	HighLight(89, 5, 4, 1, 0);
	HighLight(99, 12, 4, 1, 0);
	HighLight(99, 5, 4, 1, 0);

	// mau xanh
	HighLight(91, 4, 1, 1, 11);
	HighLight(91, 13, 1, 1, 11);
	HighLight(88, 12, 1, 1, 11);
	HighLight(88, 5, 1, 1, 11);
	HighLight(98, 12, 1, 1, 11);
	HighLight(98, 5, 1, 1, 11);
	// mau ??
	HighLight(100, 4, 1, 1, 4);
	HighLight(100, 13, 1, 1, 4);
	HighLight(93, 12, 1, 1, 4);
	HighLight(93, 5, 1, 1, 4);
	HighLight(103, 12, 1, 1, 4);
	HighLight(103, 5, 1, 1, 4);

	//W
	for (int i = 0; i <= 6; i++) {
		HighLight(67 + i, 16 + i, 2, 1, 0);
		HighLight(66 + i, 16 + i, 1, 1, 11);
		HighLight(69 + i, 16 + i, 1, 1, 4);

		HighLight(89 - i, 16 + i, 2, 1, 0);
		HighLight(88 - i, 16 + i, 1, 1, 11);
		HighLight(91 - i, 16 + i, 1, 1, 4);

	}
	for (int i = 0; i <= 2; i++) {
		HighLight(79 + i, 19 + i, 2, 1, 0);
		HighLight(78 + i, 19 + i, 1, 1, 11);
		HighLight(81 + i, 19 + i, 1, 1, 4);

		HighLight(77 - i, 19 + i, 2, 1, 0);
		HighLight(76 - i, 19 + i, 1, 1, 11);
		if (i != 0) {
			HighLight(79 - i, 19 + i, 1, 1, 4);
		}
	}
	//I
	HighLight(95, 16, 2, 7, 0);
	HighLight(94, 16, 1, 7, 4);
	HighLight(97, 16, 1, 7, 11);
	//N

	HighLight(102, 16, 2, 7, 0);
	HighLight(101, 16, 1, 7, 11);
	HighLight(104, 16, 1, 7, 4);

	HighLight(112, 16, 2, 7, 0);
	HighLight(111, 16, 1, 7, 11);
	HighLight(114, 16, 1, 7, 4);

	for (int i = 0; i <= 6; i++) {
		HighLight(104 + i, 16 + i, 2, 1, 0);
		if (i <= 4) {
			HighLight(106 + i, 16 + i, 1, 1, 4);
		}
		if (i >= 2) {
			HighLight(103 + i, 16 + i, 1, 1, 11);
		}

	}
}
