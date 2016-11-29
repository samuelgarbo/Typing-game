#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void LongRanking(), LongRecordWrite(); // 긴 글 랭킹 함수, 긴 글 기록 쓰기 함수.
void ShortRanking(), ShortRecordWrite(); // 짧은 글 랭킹 함수, 짧은 글 기록 쓰기 함수.
void WordRanking(), WordRecordWrite(); // 단어 랭킹 함수, 단어 기록 쓰기 함수.
void GameRanking(), GameRecordWrite(); // 게임 랭킹 함수, 게임 기록 쓰기 함수.

typedef struct {
	int rank; // 순위.
	char name[20]; // 이름.
	int TypingSpeed; // 타이핑 속도.
	int accuracy; // 정확도.
	int point; // 점수.
	char date[20]; // 날짜.
}RECORD;

int main()
{	
	return 0;
}
 
void LongRanking() // 긴 글 랭킹 함수.
{
	int i = 0, j = 0;
	int count = -1; // 배열 방 갯수 확인 변수 (몇 개의 기록이 저장 되어 있는지 확인).
	FILE *r1 = fopen("LongRecord.txt", "r"); // 텍스트 파일 읽기 모드로 열기.

	RECORD sr[50], temp_sr;

	while(!feof(r1))
	{
		fscanf(r1, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);	
		i++;
		count++;
	}

	for( i = 0; i < count; i++ ) // 정확도를 1순위, 타이핑 속도를 2순위로 내림차순으로 배열 정리.
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

	for (i = 0; i < count; i++) // 정확도를 1순위, 타이핑 속도를 2순위로 순위 매기기.
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
	printf("       ┌──┐       ┌──┐     ┌───┐      ┌──────┐       ┌──┐\n");
	printf("       │순위│       │이름│     │정확도│      │타이핑 속도 │       │날짜│\n");
	printf("       └──┘       └──┘     └───┘      └──────┘       └──┘\n\n");
	if (count >= 10)
	{
		for (i = 0; i < 10; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
	else
	{
		for (i = 0; i < count; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
		
	fclose(r1);
}

void ShortRanking() // 짧은 글 랭킹 함수 (자세한 사항은 "긴 글 랭킹 함수" 참조).
{
	int i = 0, j = 0;
	int count = -1;
	FILE *r2 = fopen("ShortRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r2))
	{
		fscanf(r2, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
		count++;
	}

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
	printf("       ┌──┐       ┌──┐     ┌───┐      ┌──────┐       ┌──┐\n");
	printf("       │순위│       │이름│     │정확도│      │타이핑 속도 │       │날짜│\n");
	printf("       └──┘       └──┘     └───┘      └──────┘       └──┘\n\n");
	if (count >= 10)
	{
		for (i = 0; i < 10; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
	else
	{
		for (i = 0; i < count; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
	fclose(r2);
}

void WordRanking() // 단어 랭킹 함수 (자세한 사항은 "긴 글 랭킹 함수" 참조).
{
	int i = 0, j = 0;
	int count = -1;
	FILE *r3 = fopen("WordRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r3))
	{
		fscanf(r3, "%s %d %d %s", sr[i].name,  &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);
		i++;	
		count++;
	}

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
	printf("       ┌──┐       ┌──┐      ┌───┐      ┌──────┐       ┌──┐\n");
	printf("       │순위│       │이름│      │정확도│      │타이핑 속도 │       │날짜│\n");
	printf("       └──┘       └──┘      └───┘      └──────┘       └──┘\n\n");
	if (count >= 10)
	{
		for (i = 0; i < 10; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
	else
	{
		for (i = 0; i < count; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed, sr[i].date);
	}
	fclose(r3);
}

void GameRanking() // 게임 랭킹 함수 (자세한 사항은 "긴 글 랭킹 함수" 참조).
{
	int i = 0, j = 0;
	int count = -1;
	FILE *r4 = fopen("GameRecord.txt", "r");

	RECORD sr[50], temp_sr;

	//for(i = 0; i < count; i++)
	while(!feof(r4))
	{
		fscanf(r4, "%s %d %s", sr[i].name, &sr[i].point, sr[i].date);
		i++;	
		count++;
	}

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
		printf("       ┌──┐       ┌──┐        ┌──┐              ┌──┐\n");
		printf("       │순위│       │이름│        │점수│              │날짜│\n");
		printf("       └──┘       └──┘        └──┘              └──┘\n\n");

	if (count >= 10)
	{
		for (i = 0; i < 10; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].point, sr[i].date);
	}
	else
	{
		for (i = 0; i < count; i++)
			printf("\t %2d\t       %s\t\t%2d\t\t   %2s\n\n", sr[i].rank, sr[i].name, sr[i].point, sr[i].date);
	}
	fclose(r4);
}

void LongRecordWrite() // 긴 글 기록 쓰기 함수.
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("LongRecord.txt", "a"); // 텍스트 파일 a 모드로 열기.

	char name[20];
	int Ts;
	int ac;
	printf("사용자의 이름을 입력하시오 : ");
	scanf("%s", name);	
	printf("사용자의 타이핑 속도 : ");
	scanf("%d", &Ts);
	printf("사용자의 정확도 : ");
	scanf("%d", &ac);

	fprintf(rf, "%s %d %d %d %d %d\n", name, ac, Ts, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); // 파일에 쓰기.
	fclose(rf);
}

void ShortRecordWrite() // 짧은 글 기록 쓰기 함수 (자세한 사항은 "긴 글 기록 쓰기 함수" 참조).
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

void WordRecordWrite() // 단어 기록 쓰기 함수 (자세한 사항은 "긴 글 기록 쓰기 함수" 참조).
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

void GameRecordWrite() // 게임 기록 쓰기 함수 (자세한 사항은 "긴 글 기록 쓰기 함수" 참조).
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
