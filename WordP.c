#include "System.h"

int WordP() //WordP함수 생성
{

	{
 FILE *in= fopen("단어연습 예문.txt", "r");
 char ch;

 system("cls");

     printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  데이터를 불러오는중 입니다  ▲\n");
	 printf("                                            ◁  ▷\n");
	 printf("                                              ▽\n ");
	 Sleep(1000);

	 system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  데이터를 불러오는중 입니다  △\n");
	 printf("                                            ◁  ▶\n");
	 printf("                                              ▽\n ");
	 Sleep(1000);

	 system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  데이터를 불러오는중 입니다  △\n");
	 printf("                                            ◁  ▷\n");
	 printf("                                              ▼\n ");
	 Sleep(1000);

	  system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  데이터를 불러오는중 입니다  △\n");
	 printf("                                            ◀  ▷\n");
	 printf("                                              ▽\n ");
	 Sleep(1000);

	 system("cls");

 while (!feof(in))
 {
	 fscanf(in, "%c" , &ch);
	 printf("%c",ch);
 }
 fclose(in);
}
	getche();
	
}
