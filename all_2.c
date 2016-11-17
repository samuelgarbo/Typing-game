#include<stdio.h>

typedef struct setting //관리자모드 예매가격 변경 구조체
{
   char adult_m[10]; //어른 가격
   char teen_m[10]; //청소년 가격
   char senior[10]; //우대 가격
   char child[10]; //어린이 가격
}setting;

void print_setting();

void main()
{
   struct setting adult_m1, teen_m1, senior_m1, child_m1;

   FILE *fpout; //파일 포인터 변수선언

   fpout = fopen("data.txt", "w"); //텍스트파일을 쓰기전용으로 열기
   
   if (fpout == NULL)
   {
      return;
   }

   
   
      printf("변경할 어른표의 가격을 입력하세요\n");
      fputs("%s", adult_m1);

      printf("변경할 청소년표의 가격을 입력하세요\n");
      fputs("%s", teen_m1);

      printf("변경할 우대표의 가격을 입력하세요\n");
      fputs("%s", senior_m1);

      printf("변경할 어린이표의 가격을 입력하세요\n");
      fputs("%s", child_m1);

      fclose(fpout);
   
   print_setting();

   return ;
}