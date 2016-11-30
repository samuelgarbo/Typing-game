#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#define X 60
#define Y 20
#define word_N 6
#define buf_N 100
#define keyb_N 100

typedef struct invaders {
	char alien[20];
	int length, location;
}word;

void printScreen();							//print out screen array
void screenInitialize();					//initial screen array values
void createWordArray(char *buffer,word *w);	//word in file to array
void wordToScreen( word *w);				//move word in array to screen array
int moveWordDown(word *w);					//move screen array content 1 row down
int randNum(int num);						//random number generator. "high" is the limit
void gotoxy(int x, int y);					//cursor location
int wordCheck(word *w);
int wordRemove(int y,word *w);

char screen[Y][X], keyboard[keyb_N];
int wcount = 0;

int main() {
	word w[word_N];
	int c, len,res;
	char buffer[buf_N], ch;
	
	srand(time(NULL));
	createWordArray(buffer,w); //create word array
	screenInitialize();	//initialize screen array value to " "
	while (1) {
		wordToScreen(w);
		system("cls");
		printScreen();		
		while (_kbhit()) {	//if keyboard pressed gets input. Backspace erases one character from string
			c = _getch();			
			if (c == 13) {
				res = wordCheck(w);	//checks if word exists
				if (res > -1) {
					res=wordRemove(res,w);	//removes and checks if all the words are go
					if (res == 1) {
						return 0;
					}
				}
				continue;
			}
			else if (c == 8) {	//backspace
				len = strlen(keyboard) - 1;
				if (len >= 0) {	//erase
					keyboard[len] = '\0';
				}
				continue;
			}
			ch = c;
			strncat(keyboard, &ch, 1);	//add char to string			
		}
		
		res = moveWordDown(w);
		if (res == 1) {
			return 0;
		}
		system("cls");
		printScreen();
		Sleep(500);
	}
	return 0;
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
			if (w[i].location >= Y) {				
				return 1;
			}
		}
	}
	return 0;
}
void gotoxy(int x, int y)//ÁÂÇ¥ÇÔ¼ö
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int wordCheck(word *w) {
	int i, j, tmp;
	for (i = 0; i < word_N; i++) {	//checks if word entered is correct
		if (strcmp(w[i].alien, keyboard) == 0) {
			for (j = 0; j < keyb_N; j++) {	//clear keyboard input
				keyboard[j] = '\0';
			}
			tmp = w[i].location;
			w[i].location = -2;	//change location as hit
			return tmp;
		}
	}
	for (j = 0; j < keyb_N; j++) {	//clear keyboard input
		keyboard[j] = '\0';
	}
	return -1;
}
int wordRemove(int y,word *w) {
	int i;
	for (i = 0; i < X; i++) {
		screen[y][i] = ' ';
	}	
	for (i = 0; i < word_N; i++) {
		if (w[i].location > -1) {
			return 0;
		}
	}
	return 1;
}