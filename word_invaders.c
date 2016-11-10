#include<stdio.h>
#include<string.h>
#define X 60
#define Y 20
typedef struct invaders {
	char alien[20];
	int point;
}word;

void printScreen();
void screenInitialize();
void wordArray(word *w);
int screen[Y][X];

int main() {
	word w[6];
	wordArray(w); //crreae word array
	screenInitialize();	//initialize screen array value to -1
	printScreen();
	return 0;
}
void printScreen() {
	int i, j;
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
			printf(" ");
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
}
void screenInitialize() {
	int i, j;
	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			screen[i][j] = -1;
		}		
	}
}
void wordArray(word *w) {
	FILE *fp;	
	int i = 0;
	char buffer[20];
	fp = fopen("level1.txt", "r");
	while (fgets(buffer, 20, fp) != NULL) {
		w[i].point = strlen(buffer) - 1;
		strcpy(w[i].alien, buffer);
		i++;
	}
}