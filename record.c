#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void screed_record();
void swap(int *x, int *y);
void recordWrite();

typedef struct {
	char name[20];
	int TypingSpeed;
	int accuracy;
	char date[20];
}RECORD;

int main()
{
	screed_record();
	recordWrite();
}

void screed_record()
{
	int i;
	int a, b;
	FILE *r1 = fopen("screed record.txt", "r");
	RECORD sr[10];
	for (i = 0; i < 10; i++)
		fscanf(r1, "%s %d %d %s", sr[i].name, &sr[i].accuracy, &sr[i].TypingSpeed, sr[i].date);

	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			if (sr[a].accuracy > sr[b].accuracy)
			{
				swap(&sr[a].accuracy, &sr[b].accuracy);
			}
			else if (sr[a].accuracy == sr[b].accuracy)
			{
				if (sr[a].TypingSpeed > sr[b].TypingSpeed)
					swap(&sr[a].accuracy, &sr[b].accuracy);
			}
			else
				continue;
		}
	}
	for (i = 0; i < 10; i++)
		printf(" %d.   이름 : %2s\t정확도 : %2d\t타이핑 속도 : %2d\t날짜 : %2s\n", i + 1, sr[i].name, sr[i].accuracy, sr[i].TypingSpeed , sr[i].date);

	fclose(r1);
}

void swap(int *x, int *y)
{
	int tem;
	tem = *x;
	*x = *y;
	*y = tem;
}

void recordWrite()
{
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);

	FILE *rf = fopen("screed record.txt", "a");

	char name[20] = "홍길동";
	int Ts = 45;
	int ac = 99;

	fprintf(rf, "%s %d %d %d. %d. %d\n", name, Ts, ac, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	fclose(rf);
}
