#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>

#define X 60
#define Y 20
#define word_N 6
#define buf_N 100
#define keyb_N 100
#define click 30000

typedef struct invaders {
	char alien[20];
	int length, location;
}word;

void wordGame();							//Game
void printScreen();							//print out screen array
void screenInitialize();					//initial screen array values
void createWordArray(char *buffer,word *w);	//word in file to array
void wordToScreen( word *w);				//move word in array to screen array
int moveWordDown(word *w);					//move screen array content 1 row down
int randNum(int num);						//random number generator. "high" is the limit
void gotoxy(int x, int y);					//cursor location
int wordCheck(word *w);						//checks if entered word is correct
int wordRemove(int y,word *w);				//removes word from screen array
void clearKeyboardInput();					//clear user's received input
void loseGame(float result);				//When LOSE
void winGame(float result);					//When WIN

char screen[Y][X], keyboard[keyb_N];
int wcount = 0, points = 0;

int main() {
	wordGame();
	return 0;
}
void wordGame() {
	float result;
	clock_t before;
	word w[word_N];
	int c, len, res, t = 0;
	char buffer[buf_N], ch;
	srand(time(NULL));
	createWordArray(buffer, w); //create word array
	screenInitialize();	//initialize screen array value to " "
	before = clock();	//start timer
	while (1) {
		if (t % click == 0) {
			wordToScreen(w);
			system("cls");
			printScreen();
		}
		while (_kbhit()) {	//checks if key is pressed
			c = _getch();
			if (c == 13) {	//"ENTER" key
				res = wordCheck(w);	//checks if word exists
				clearKeyboardInput();	//clear keyboard input			
				if (res > -1) {
					res = wordRemove(res, w);	//removes and checks if all the words are gone
					system("cls");
					printScreen();
					if (res == 1) {	
						result = (float)(clock() - before) / CLOCKS_PER_SEC;	//end Timer
						winGame(result);	//WIN
						return 0;
					}
				}
				continue;
			}
			else if (c == 8) {	//backspace
				len = strlen(keyboard) - 1;
				if (len >= 0) {	//erase last char from string
					keyboard[len] = '\0';
				}
				continue;
			}
			ch = c;
			strncat(keyboard, &ch, 1);	//add char to string	
			gotoxy(1, 1);
			printf("%s", keyboard);
			//printScreen();
		}
		if (t % click == 0) {
			res = moveWordDown(w);	//moves all the screen content one row down
			if (res == 1) {
				result = (float)(clock() - before) / CLOCKS_PER_SEC;	//end Timer
				loseGame(result);	//LOSE
				return 0;
			}
		}
		t++;
		//Sleep(1000);
	}	
}
void printScreen() {
	int i, j;

	printf("\n\n");
	//top frame
	for (i = 0; i < X + 2; i++) {
		printf("#");
	}
	printf("\n");
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			//left frame
			if (j == 0) {
				printf("#");
			}
			//content
			printf("%c",screen[i][j]);
			//right frame
			if (j == X - 1) {
				printf("#");
			}
		}
		printf("\n");
	}	
	//bottom frame
	for (i = 0; i < X + 2; i++) {
		printf("#");
	}
	printf("\n");
	gotoxy(1, 1);
	printf("%s", keyboard);
	
}
void screenInitialize() {
	int i, j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			screen[i][j] = ' ';
		}		
	}
}
void createWordArray(char *buffer, word *w) {
	FILE *fp;	
	int i = 0;	
	fp = fopen("level1.txt", "r");
	while (fgets(buffer, 100, fp) != NULL) {	//words from file to array
		w[i].length = strlen(buffer) - 1;
		strcpy(w[i].alien, buffer);
		w[i].alien[w[i].length] = '\0';	//removes the '\n' from he end
		w[i].location = -1;
		i++;
	}
	wcount = i;	//how many words array has
}
void wordToScreen( word *w) {
	int i = 0, j = 0, r;
	if (wcount > 0) {
		r = randNum((X - w[wcount - 1].length));	//Picks a place from the row. Takes into account length of word
		for (i = 0; i < w[wcount-1].length; i++) {
			screen[0][r + i] = w[wcount-1].alien[i];
		}
		w[wcount - 1].location = 0;
		wcount--;
	}
}
int randNum(int num) {
	
	int r;
	do{
		r = rand();
	} while (r >= num);
	//r = rand() % (num + 1);
	return r;
}
int moveWordDown(word *w) {
	int i, j;
	for (i = Y; i > 0; i--) {	//move down 1 row
		for (j = 0; j < X; j++) {
			screen[i][j] = screen[i-1][j];
		}
	}
	for (i = 0; i < X; i++) {
		screen[0][i] =' ';
	}
	for (i = 0; i < word_N; i++) {	//change the location index
		if (w[i].location > -1) {
			w[i].location++;
			if (w[i].location >= Y) {	//if word hits bottom				
				return 1;
			}
		}
	}
	return 0;
}
void gotoxy(int x, int y)//좌표함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int wordCheck(word *w) {
	int i, j, tmp;
	for (i = 0; i < word_N; i++) {	//checks if word entered is correct
		if (strcmp(w[i].alien, keyboard) == 0) {
			clearKeyboardInput();	//clear keyboard input			
			tmp = w[i].location;
			w[i].location = -2;	//mark as hit
			points = points + w[i].length;
			return tmp;
		}
	}	
	return -1;
}
int wordRemove(int y,word *w) {
	int i;
	for (i = 0; i < X; i++) {
		screen[y][i] = ' ';
	}
	for (i = 0; i < word_N; i++) {	//checks if all words are gone
		if (w[i].location > -1) {
			return 0;	//LOSE
		}
	}
	return 1;
}
void clearKeyboardInput() {
	int j;
	for (j = 0; j < keyb_N; j++) {	//clear keyboard input
		keyboard[j] = '\0';
	}
}
void loseGame(float result) {
	system("cls");
	printf("\n\n");
	printf("  _  _  ._   _  ._ _. _|_     |  _. _|_ o  _  ._  | | \n");
	printf(" (_ (_) | | (_| | (_|  |_ |_| | (_|  |_ | (_) | | o o \n");
	printf("             _|                                       \n");
	printf("\n");
		
}
void winGame(float result) {
	system("cls");
	printf("\n\n");
	printf("  _  _  ._   _  ._ _. _|_     |  _. _|_ o  _  ._  | | \n");
	printf(" (_ (_) | | (_| | (_|  |_ |_| | (_|  |_ | (_) | | o o \n");
	printf("             _|                                       \n");
	printf("\n");
	printf("Your time : %.2lf sec\nYour points : %d\n", result, points);
}
