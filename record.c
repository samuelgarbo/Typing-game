#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX     100

void ScreedRecord(), ScreedRecordWrite();
void ShortRecord(), ShortRecordWrite();
void WordRecord(), WordRecordWrite();
void GameRecord(), GameRecordWrite();

typedef struct {
	int rank;
	char name[20];
	int TypingSpeed;
	int accuracy;
	int point;
	char date[20];
}RECORD;

int main()
{
	int MenuSelect;

	while(1)
	{
		printf("1. 긴 글 기록\n2. 짧은 글 기록\n3. 단어 기록\n4. 게임 기록\n\n");
		printf("메뉴 선택 : ");
		scanf("%d", &MenuSelect);
		
		switch(MenuSelect)
		{
		case 1:
			ScreedRecord();
			getch();
			system("cls");
			break;
		case 2:
			ShortRecord();
			getch();
			system("cls");
			break;
		case 3:
			WordRecord();
			getch();
			system("cls");
			break;
		case 4:
			GameRecord();
			getch();
			system("cls");
			break;
		}
	}
}
 
void ScreedRecord()
{
	int i = 0, j = 0;
	FILE *r1 = fopen("ScreedRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < 50; i++)
	while(!feof(r1))
	{
		fscanf(r1, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
	}

	for( i = 0; i < 50; i++ )
	{
		for( j = i + 1; j < 50; j++ ) 
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

	for(i=0; i < 50 ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < 50; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	for(i = 0; i < 10; i++)
		printf(" %2d.   이름 : %s\t정확도 : %2d\t타이핑 속도 : %2d\t날짜 : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	fclose(r1);
}

void ShortRecord()
{
	int i = 0, j = 0;
	FILE *r2 = fopen("ShortRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < 50; i++)
	while(!feof(r2))
	{
		fscanf(r2, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
	}

	for( i = 0; i < 50; i++ )
	{
		for( j = i + 1; j < 50; j++ ) 
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

	for(i=0; i < 50 ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < 50; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	for(i = 0; i < 10; i++)
		printf(" %2d.   이름 : %s\t정확도 : %2d\t타이핑 속도 : %2d\t날짜 : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	fclose(r2);
}

void WordRecord()
{
	int i = 0, j = 0;
	FILE *r3 = fopen("WordRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < 50; i++)
	while(!feof(r3))
	{
		fscanf(r3, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
	}

	for( i = 0; i < 50; i++ )
	{
		for( j = i + 1; j < 50; j++ ) 
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

	for(i=0; i < 50 ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < 50; j++)
				 {
                         if( sr[i].accuracy < sr[j].accuracy )
							 sr[i].rank++;
						 else if(sr[i].accuracy == sr[j].accuracy)						
							 if(sr[i].TypingSpeed < sr[j].TypingSpeed)
								 sr[i].rank++;
				 }
	}

	for(i = 0; i < 10; i++)
		printf(" %2d.   이름 : %s\t정확도 : %2d\t타이핑 속도 : %2d\t날짜 : %2s\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	fclose(r3);
}

void GameRecord()
{
	int i = 0, j = 0;
	FILE *r4 = fopen("GameRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < 50; i++)
	while(!feof(r4))
	{
		fscanf(r4, "%s %d", sr[i].name, &sr[i].point);
		i++;	
	}


	for( i = 0; i < 50; i++ )
	{
		for( j = i + 1; j < 50; j++ ) 
		{
			if( sr[i].point < sr[j].point ) 
			{
				temp_sr = sr[i];
				sr[i] = sr[j];
				sr[j] = temp_sr;
			}
			
		}
	}

	for(i=0; i < 50 ; i++)
    {
                 sr[i].rank=1;
                 for(j=0; j < 50; j++)
                         if(sr[i].point < sr[j].point)
							 sr[i].rank++;
    }

	for(i = 0; i < 10; i++)
		printf(" %2d.   이름 : %s\t점수 : %2d\n", sr[i].rank, sr[i].name, sr[i].point);
	fclose(r4);
}

void ScreedRecordWrite()
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("ScreedRecord.txt", "a");

	char name[20];
	int Ts;
	int ac;
	printf("사용자의 이름을 입력하시오 : ");
	scanf("%s", name);	
	printf("사용자의 타이핑 속도 : ");
	scanf("%d", &Ts);
	printf("사용자의 정확도 : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}

void ShortRecordWrite()
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("ShortRecord.txt", "a");

	char name[20];
	int Ts;
	int ac;
	printf("사용자의 이름을 입력하시오 : ");
	scanf("%s", name);	
	printf("사용자의 타이핑 속도 : ");
	scanf("%d", &Ts);
	printf("사용자의 정확도 : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}

void WordRecordWrite()
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("WordRecord.txt", "a");

	char name[20];
	int Ts;
	int ac;
	printf("사용자의 이름을 입력하시오 : ");
	scanf("%s", name);	
	printf("사용자의 타이핑 속도 : ");
	scanf("%d", &Ts);
	printf("사용자의 정확도 : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}

void GameRecordWrite()
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("GameRecord.txt", "a");

	char name[20];
	int point;
	int ac;

	printf("사용자의 이름을 입력하시오 : ");
	scanf("%s", name);	
	printf("사용자의 점수 : ");
	scanf("%d", &point);

	fprintf(rf, "%s %d %d.%d.%d\n", name, point, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}
