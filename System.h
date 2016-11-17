#define __SYSTEM_H__

#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include<stdlib.h>

int startingMenu(int choice);
int secondMenu(int choice);
int rankingMenu(int choice);

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 12);
#define GRAY SetConsoleTextAttribute(COL, 7);
#define buf 128

int WordP();
void LongSP();
void ShortSP();
void printLogo();	//print out logo
void printMenu(int choice);	//print out starting menu