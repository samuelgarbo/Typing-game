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
		
       menu(); //menu�Լ� ���

       printf("�������� �Է��Ͻÿ�: ");//�޴�����
       scanf("%d", &select);  //������� ���ð��Է�

		   if(select == 3 ){//��ۿ��� �����Ұ�� LongSP��
			   system("cls");
			   LongSP();}// LongSP�Լ� ���

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
          puts("1.�ܾ� ����");
          puts("2.ª���� ����"); 
          puts("3.��� ����"); 
          puts("4.����"); 


        
 
    } 


	//--------------------------------------------------------

	void LongSP() //LongSP�Լ� ����
{
	FILE *fp = fopen("��ۿ��� ����.txt","r"); // ��ۿ��� ������ �б�� ����
	
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
	FILE *fp = fopen("ª���ۿ��� ����.txt","r"); // ª���ۿ��� ������ �б�� ����
	
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

    void WordP() //WordP�Լ� ����
{
	FILE *fp = fopen("�ܾ�� ����.txt","r"); // �ܾ�� ������ �б�� ���⹮�� �б�� ����

	if(fp != NULL)
	{
		int c = 0;
		do{
			c=fgetc(fp);
			if(c !=EOF) // ������ ���� �������� ������ ���� 
				printf("%c",c);
		}while(c != EOF);

		fclose(fp); //txt���� �ݱ�
		fp = NULL;
	}
}
   