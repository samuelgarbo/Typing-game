#include<stdio.h>
#include<stdlib.h>
 #pragma warning(disable: 4996) 
/*
#pragma comment(lib, "mylibrary.lib");
*/
 #define buf 128 
 void menu(); 
 void WordP();
 void LongSP();
 void ShortSP();

  //---------------------------------------------------------

 int main() 
{ 
    FILE *fp=NULL; 
    int num = 0; 
    int select; 
  
 
     
     
    while (1) { 
		
       menu(); //menu함수 출력

       printf("정수값을 입력하시오: ");//메뉴선택
       scanf("%d", &select);  //사용자의 선택값입력

		   if(select == 3 ){//긴글연습 선택할경우 LongSP함
			   system("cls");
			   LongSP();}// LongSP함수 출력

		   else if(select == 2 ){
			   system("cls");
			   ShortSP();}

		   else if(select == 1){
			   system("cls");
			   WordP();}

       switch (select) { 
       case 1: WordP(); break;
       case 2: ShortSP(fp); break;
      case 3: LongSP(fp); break;
       case 4: return 0; 
       } 
    } 
    fclose(fp); 
    return 0; 
 }

 //---------------------------------------------------------

   void menu() { 
       int num = 0; 
        
          printf("\n"); 
          puts("1.단어 연습");
          puts("2.짧은글 연습"); 
          puts("3.긴글 연습"); 
          puts("4.종료"); 


        
 
    } 


	//--------------------------------------------------------

	void LongSP() //LongSP함수 생성
{
	FILE *fp = fopen("긴글연습 예문.txt","r"); // 긴글연습 예문을 읽기로 열기
	
	if( fp !=NULL)
	{
		int c=0;
		char sentence;

		do{
		c = fgetc(fp); 
		if( c != EOF) // 문장이 끝에 도달하지 않을때 까지
		printf("%c",c);
	}while (c != EOF);

		scanf("%c",&sentence);

		fclose(fp); //txt폴더 닫기
		fp = NULL;
	}
}
//--------------------------------------------------------

	void ShortSP() //ShortSP함수 생성
{
	FILE *fp = fopen("짧은글연습 예문.txt","r"); // 짧은글연습 예문을 읽기로 열기
	
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
	
	//--------------------------------------------------------

    void WordP() //WordP함수 생성
{
	FILE *fp = fopen("단어연습 예문.txt","r"); // 단어연습 예문을 읽기로 열기문을 읽기로 열기

	if(fp != NULL)
	{
		int c = 0;
		do{
			c=fgetc(fp);
			if(c !=EOF) // 문장이 끝에 도달하지 않을때 까지 
				printf("%c",c);
		}while(c != EOF);

		fclose(fp); //txt폴더 닫기
		fp = NULL;
	}
}
   