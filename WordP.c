#include "System.h"

int WordP() //WordP�Լ� ����
{

	{
 FILE *in= fopen("�ܾ�� ����.txt", "r");
 char ch;

 system("cls");

     printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  �����͸� �ҷ������� �Դϴ�  ��\n");
	 printf("                                            ��  ��\n");
	 printf("                                              ��\n ");
	 Sleep(1000);

	 system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  �����͸� �ҷ������� �Դϴ�  ��\n");
	 printf("                                            ��  ��\n");
	 printf("                                              ��\n ");
	 Sleep(1000);

	 system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  �����͸� �ҷ������� �Դϴ�  ��\n");
	 printf("                                            ��  ��\n");
	 printf("                                              ��\n ");
	 Sleep(1000);

	  system("cls");

	 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	 printf("                  �����͸� �ҷ������� �Դϴ�  ��\n");
	 printf("                                            ��  ��\n");
	 printf("                                              ��\n ");
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
