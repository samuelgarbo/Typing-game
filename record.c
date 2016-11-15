#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void ScreedRanking(), ScreedRecordWrite(); // �� �� ��ŷ �Լ�, �� �� ��� ���� �Լ�.
void ShortRanking(), ShortRecordWrite(); // ª�� �� ��ŷ �Լ�, ª�� �� ��� ���� �Լ�.
void WordRanking(), WordRecordWrite(); // �ܾ� ��ŷ �Լ�, �ܾ� ��� ���� �Լ�.
void GameRanking(), GameRecordWrite(); // ���� ��ŷ �Լ�, ���� ��� ���� �Լ�.

typedef struct {
	int rank; // ����.
	char name[20]; // �̸�.
	int TypingSpeed; // Ÿ���� �ӵ�.
	int accuracy; // ��Ȯ��.
	int point; // ����.
	char date[20]; // ��¥.
}RECORD;

int main()
{
	int MenuSelect;

	while(1)
	{
	printf("1. �� �� ���\n2. ª�� �� ���\n3. �ܾ� ���\n4. ���� ���\n\n");
	printf("�޴� ���� : ");
	scanf("%d", &MenuSelect);

	switch(MenuSelect)
	{
	case 1:
		ScreedRanking();
		getch();
		system("cls");
		break;
	case 2:
		ShortRanking();
		getch();
		system("cls");
		break;
	case 3:
		WordRanking();
		getch();
		system("cls");
		break;
	case 4:
		GameRanking();
		getch();
		system("cls");
		break;
	}
	}
}
 
void ScreedRanking() // �� �� ��ŷ �Լ�.
{
	int i = 0, j = 0;
	int count = 0; // �迭 �� ���� Ȯ�� ���� (�� ���� ����� ���� �Ǿ� �ִ��� Ȯ��).
	FILE *r1 = fopen("ScreedRecord.txt", "r"); // �ؽ�Ʈ ���� �б� ���� ����.

	RECORD sr[50], temp_sr;

	while(!feof(r1))
	{				
		fscanf(r1, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);		
		i++;				
		count++;	
	}

	if (count-1 == 0)
		printf("����� ����� �����ϴ�.\n");

	for( i = 0; i < count; i++ ) // ��Ȯ���� 1����, Ÿ���� �ӵ��� 2������ ������������ �迭 ����.
	{
		for( j = i + 1; j < count; j++ ) 
		{
			if( sr[i].accuracy < sr[j].accuracy ) 
			{
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
			else if(sr[i].accuracy == sr[j].accuracy)
			{
				if(sr[i].TypingSpeed < sr[j].TypingSpeed)
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
		}
	}

	for (i = 0; i < count; i++) // ��Ȯ���� 1����, Ÿ���� �ӵ��� 2������ ���� �ű��.
    {
                 sr[i].rank=1;
                 for(j=0; j < count; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	if (count - 1 >= 10) // ����� ����� 10�� �̻��̶�� TOP 10 ���.
		for (i = 0; i < 10; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	else if (0 < count - 1 < 10) // ����� ����� 1~10����� ����� ��� ��� ���.
		for (i = 0; i < count-1; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);

	fclose(r1);
}

void ShortRanking() // ª�� �� ��ŷ �Լ� (�ڼ��� ������ "�� �� ��ŷ �Լ�" ����).
{
	int i = 0, j = 0;
	int count = 0;
	FILE *r2 = fopen("ShortRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r2))
	{
		fscanf(r2, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
		count++;
	}

	if (count - 1 == 0)
		printf("����� ����� �����ϴ�.\n");

	for( i = 0; i < count; i++ )
	{
		for( j = i + 1; j < count; j++ ) 
		{
			if( sr[i].accuracy < sr[j].accuracy ) 
			{
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
			else if(sr[i].accuracy == sr[j].accuracy)
			{
				if(sr[i].TypingSpeed < sr[j].TypingSpeed)
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
		}
	}

	for(i=0; i < count ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < count; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	if (count - 1 >= 10)
		for (i = 0; i < 10; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	else
		for (i = 0; i < count - 1; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	fclose(r2);
}

void WordRanking() // �ܾ� ��ŷ �Լ� (�ڼ��� ������ "�� �� ��ŷ �Լ�" ����).
{
	int i = 0, j = 0;
	int count = 0;
	FILE *r3 = fopen("WordRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r3))
	{
		fscanf(r3, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
		count++;
	}

	if (count - 1 == 0)
		printf("����� ����� �����ϴ�.\n");

	for( i = 0; i < count; i++ )
	{
		for( j = i + 1; j < count; j++ ) 
		{
			if( sr[i].accuracy < sr[j].accuracy ) 
			{
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
			else if(sr[i].accuracy == sr[j].accuracy)
			{
				if(sr[i].TypingSpeed < sr[j].TypingSpeed)
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
		}
	}

	for(i=0; i < count ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < count; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	if (count - 1 >= 10)
		for (i = 0; i < 10; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	else
		for (i = 0; i < count - 1; i++)
			printf(" %2d.   �̸� : %s\t��Ȯ�� : %2d\tŸ���� �ӵ� : %2d\t��¥ : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	fclose(r3);
}

void GameRanking() // ���� ��ŷ �Լ� (�ڼ��� ������ "�� �� ��ŷ �Լ�" ����).
{
	int i = 0, j = 0;
	int count = 0;
	FILE *r4 = fopen("GameRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r4))
	{
		fscanf(r4, "%s %d", sr[i].name, &sr[i].point);
		i++;	
		count++;
	}

	if (count - 1 == 0)
		printf("����� ����� �����ϴ�.\n");

	for( i = 0; i < count; i++ )
	{
		for( j = i + 1; j < count; j++ ) 
		{
			if( sr[i].point < sr[j].point ) 
			{
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
			
		}
	}

	for(i=0; i < count ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < count; j++)
                         if(sr[i].point < sr[j].point)
							 sr[i].rank++;
    }

	if (count - 1 >= 10)
		for (i = 0; i < 10; i++)
			printf(" %2d.   �̸� : %s\t���� : %2d\n", sr[i].rank, sr[i].name, sr[i].point);
	else
		for (i = 0; i < count - 1; i++)
			printf(" %2d.   �̸� : %s\t���� : %2d\n", sr[i].rank, sr[i].name, sr[i].point);
		
	fclose(r4);
}

void ScreedRecordWrite() // �� �� ��� ���� �Լ�.
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("ScreedRecord.txt", "a"); // �ؽ�Ʈ ���� a ���� ����.

	char name[20];
	int Ts;
	int ac;
	printf("������� �̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);	
	printf("������� Ÿ���� �ӵ� : ");
	scanf("%d", &Ts);
	printf("������� ��Ȯ�� : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); // ���Ͽ� ����.
	fclose(rf);
}

void ShortRecordWrite() // ª�� �� ��� ���� �Լ� (�ڼ��� ������ "�� �� ��� ���� �Լ�" ����).
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("ShortRecord.txt", "a");

	char name[20];
	int Ts;
	int ac;
	printf("������� �̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);	
	printf("������� Ÿ���� �ӵ� : ");
	scanf("%d", &Ts);
	printf("������� ��Ȯ�� : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}

void WordRecordWrite() // �ܾ� ��� ���� �Լ� (�ڼ��� ������ "�� �� ��� ���� �Լ�" ����).
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("WordRecord.txt", "a");

	char name[20];
	int Ts;
	int ac;
	printf("������� �̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);	
	printf("������� Ÿ���� �ӵ� : ");
	scanf("%d", &Ts);
	printf("������� ��Ȯ�� : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}

void GameRecordWrite() // ���� ��� ���� �Լ� (�ڼ��� ������ "�� �� ��� ���� �Լ�" ����).
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("GameRecord.txt", "a");

	char name[20];
	int point;
	int ac;
	printf("������� �̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);	
	printf("������� ���� : ");
	scanf("%d", &point);

	fprintf(rf, "%s %d %d.%d.%d\n", name, point, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}