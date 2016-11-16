#include<stdio.h>
#include <Windows.h>
#include <conio.h>
#include<stdlib.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 12);
#define GRAY SetConsoleTextAttribute(COL, 7);
#define buf 128

int WordP();
void LongSP();
void ShortSP();
void printLogo();	//print out logo
void printMenu(int choice);	//print out starting menu

int startingMenu(int choice);
int secondMenu(int choice);
int rankingMenu(int choice);

int main() {
	int choice = 0;

	while (1) {

		switch (choice) {
		case 0:
			choice = startingMenu(1);
			break;
		case 1:	//second Menu
			choice = secondMenu(4);

			break;
		case 2:	//ranking			
			choice = rankingMenu(8);
			break;
		case 3:	//exit
			return 0;
		case 4:
			
		case 5:
			choice = WordP(); //getche 해서 끊고 커서 맨위로 하게 수정핡것
		
			break;
		case 6:
		
		
		case 7:
			choice = 0;
			break;
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			choice = 0;
			break;
		}
	}
	return 0;
}
int startingMenu(int choice) {
	int c;
	printLogo();
	printMenu(choice);
	while (1) {	
		c = getch();
		if (c == 13) {	//if ENTER return choice
			return choice;
		}
		if (c == 224) {
			c = getch();
			switch (c) {
			case 72:	//UP
				if (choice > 1) {
					choice--;
				}
				printLogo();
				printMenu(choice);			

				break;
			case 80:	//DOWN
				if (choice < 3) {
					choice++;
				}
				printLogo();
				printMenu(choice);			

				break;
			default:
				break;
			}
		}
	}
}
int secondMenu(int choice) {
	int c;
	printLogo();
	printMenu(choice);
	while (1) {
		c = getch();
		if (c == 13) {	//if ENTER return choice
			return choice;
		}
		if (c == 224) {
			c = getch();
			switch (c) {
			case 72:	//UP
				if (choice > 4) {
					choice--;
				}
				printLogo();
				printMenu(choice);

				break;
			case 80:	//DOWN
				if (choice < 7) {
					choice++;
				}
				printLogo();
				printMenu(choice);

				break;
			default:
				break;
			}
		}
	}
}
int rankingMenu(int choice) {
	int c;
	printLogo();
	printMenu(choice);
	while (1) {
		c = getch();
		if (c == 13) {	//if ENTER return choice
			return choice;
		}
		if (c == 224) {
			c = getch();
			switch (c) {
			case 72:	//UP
				if (choice > 8) {
					choice--;
				}
				printLogo();
				printMenu(choice);
			
				break;
			
			case 80:	//DOWN
				if (choice < 12) {
					choice++;
				}
				printLogo();
				printMenu(choice);

				break;
			default:
				break;
			}
		}
	}
}
void printMenu(int choice) {
	switch (choice) {
	case 0:		
	case 1:	//STARTING MENU
		printf("\t###################\n");
		printf("\t#  --->  START    #\n");
		printf("\t#        RANKING  #\n");
		printf("\t#        EXIT     #\n");
		printf("\t###################\n");
		break;
	case 2:
		printf("\t###################\n");
		printf("\t#        START    #\n");
		printf("\t#  --->  RANKING  #\n");
		printf("\t#        EXIT     #\n");
		printf("\t###################\n");
		break;	
	case 3:
		printf("\t###################\n");
		printf("\t#        START    #\n");
		printf("\t#        RANKING  #\n");
		printf("\t#  --->  EXIT     #\n");
		printf("\t###################\n");
		break;
	case 4:	//SECOND MENU
		printf("\t###################\n");
		printf("\t#  --->  LESSONS  #\n");
		printf("\t#        PRACTICE #\n");
		printf("\t#        GAMES    #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 5:
		printf("\t###################\n");
		printf("\t#        LESSONS  #\n");
		printf("\t#  --->  PRACTICE #\n");
		printf("\t#        GAMES    #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;

		
	case 6:
		printf("\t###################\n");
		printf("\t#        LESSONS  #\n");
		printf("\t#        PRACTICE #\n");
		printf("\t#  --->  GAMES    #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 7:
		printf("\t###################\n");
		printf("\t#        LESSONS  #\n");
		printf("\t#        PRACTICE #\n");
		printf("\t#        GAMES    #\n");
		printf("\t#  --->  BACK     #\n");
		printf("\t###################\n");
		break;
	case 8:	//RANKING MENU
		printf("\t###################\n");
		printf("\t#  --->  WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 9:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#  --->  SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 10:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#  --->  LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 11:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#  --->  GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 12:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#  --->  BACK     #\n");
		printf("\t###################\n");
		break;	

	}
}
void printLogo() {
	system("cls");
	printf("XXXXXXX X     X  XXXX   X  XX     X   XXXXX  \n");
	printf("   X     X   X   X   X  X  X X    X  X     X \n");
	printf("   X      XXX    X   X  X  X  X   X  X       \n");
	printf("   X       X     XXXX   X  X   X  X  X  XXXX \n");
	printf("   X       X     X      X  X    X X  X    X  \n");
	printf("   X       X     X      X  X     XX   XXXXX  \n");
	printf("\n\n");
}
/*
void LongSP() //LongSP�Լ� ����
{
FILE *fp = fopen("긴글연습 예문.txt","r"); // ���ۿ��� ������ �б��� ����

if( fp !=NULL)
{
int c=0;
char sentence;

do{
c = fgetc(fp); 
if( c != EOF) // ������ ���� �������� ������ ����
printf("%c",c);
}while (c != EOF);

scanf("%c",&sentence);

fclose(fp); //txt���� �ݱ�
fp = NULL;
}
}
//--------------------------------------------------------

void ShortSP() //ShortSP�Լ� ����
{
FILE *fp = fopen("짧은글연습 예문.txt","r"); // ª���ۿ��� ������ �б��� ����

if( fp !=NULL)
{
int c=0;

do{
c = fgetc(fp); 
if( c != EOF) // ������ ���� �������� ������ ����
printf("%c",c);
}while (c != EOF);

fclose(fp); //txt���� �ݱ�
fp = NULL;
}
}

//--------------------------------------------------------
*/
int WordP() //WordP함수 생성
{
	FILE *fp = fopen("단어연습 예문.txt","r"); // 단어연습 예문을 읽기로 열기
	system("cls");
	if( fp !=NULL)
	{
		int c=0;

		do{
		c = fgetc(fp); 
		if( c != EOF) // 문장이 끝에 도달하지 않을때 까지
		printf("%c",c);
	}while (c != EOF);

		fclose(fp); //txt폴더 닫기
		fp = NULL;
		
	}
	//getche();
	return 10;
}
void ShortSP() //ShortSP함수 생성
{
	FILE *fp = fopen("짧은글연습 예문.txt","r"); // 짧은글연습 예문을 읽기로 열기
	system("cls");
	if( fp !=NULL)
	{
		int c=0;

		do{
		c = fgetc(fp); 
		if( c != EOF) // 문장이 끝에 도달하지 않을때 까지
		printf("%c",c);
	}while (c != EOF);

		fclose(fp); //txt폴더 닫기
		fp = NULL;
	}
	}
void LongSP() //LongSP함수 생성
{
	FILE *fp = fopen("긴글연습 예문.txt","r"); // 긴글연습 예문을 읽기로 열기
	system("cls");
	if( fp !=NULL)
	{
		int c=0;

		do{
		c = fgetc(fp); 
		if( c != EOF) // 문장이 끝에 도달하지 않을때 까지
		printf("%c",c);
	}while (c != EOF);

		fclose(fp); //txt폴더 닫기
		fp = NULL;
	}
	}