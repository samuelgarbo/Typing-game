#include<stdio.h>
#pragma warning(disable: 4996)
#define buf 128
void menu();
void word(FILE *fp);
int shortw(FILE *fp);
void longw(FILE *fp);
int main()
{
   FILE *fp=NULL;
   int num = 0;
   int select;
   fp = fopen("word.txt", "r");

   
   
   while (1) {
      menu();
      printf("정수값을 입력하시오: ");
      scanf("%d", &select);
      switch (select) {
      case 1: word(fp); break;
      case 2: shortw(fp); break;
      case 3: longw(fp); break;
      case 4: return 0;
      }
   }
   fclose(fp);
   return 0;
}
   void menu() {
      int num = 0;
      
         printf("\n");
         puts("1.낱말 연습");
         puts("2.짧은글 연습");
         puts("3.긴글 연습");
         puts("4.종료");
      
      

   }

   void word(FILE *fp)
   {
   
      char str[buf];
      int fputs(const char *s, FILE *fp);
      fgets(str, buf, fp);
      printf("%s", str);//한줄씩 읽기
      scanf("%s", &str);
      return 0;
   
   }
   int shortw(FILE *fp) {
      return 0;
   }
   void longw(FILE *fp) {
      return 0;
   }
