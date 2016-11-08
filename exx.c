#include<stdio.h>
#include <Windows.h>
#include<string.h>

#pragma warning(disable:4996) // scanf 보안 경고 제거용




int main(void) {

	char str1[20];

	char str2[20];

	printf("문자열 입력 1: ");

	scanf("%s", str1);

	printf("문자열 입력 2: ");

	scanf("%s", str2);

	

	if (!strcmp(str1, str2)) {

		puts("두 문자열은 완벽히 동일합니다.");

	}

	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		puts(str2,"Light Red");
 
		
	}

	return 0;

}
