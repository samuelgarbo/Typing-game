#include<stdio.h>
#include <Windows.h>
#include<string.h>

#pragma warning(disable:4996) // scanf ���� ��� ���ſ�




int main(void) {

	char str1[20];

	char str2[20];

	printf("���ڿ� �Է� 1: ");

	scanf("%s", str1);

	printf("���ڿ� �Է� 2: ");

	scanf("%s", str2);

	

	if (!strcmp(str1, str2)) {

		puts("�� ���ڿ��� �Ϻ��� �����մϴ�.");

	}

	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		puts(str2,"Light Red");
 
		
	}

	return 0;

}
