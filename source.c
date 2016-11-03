#include<stdio.h>

void print_out(int c);	//print out starting menu

int main() {
	int c, dir = 0;
	print_out(dir);
	while (1) {
		c = getch();
		printf("%d", c);
		if (c == 224) {
			c = getch();
			switch (c) {
			case 72:	//UP
				if (dir > 0) {
					dir--;
				}
				print_out(dir);
				break;
			case 80:	//DOWN
				if (dir < 2) {
					dir++;
				}
				print_out(dir);
				if (dir == 3) {
					return 0;
				}
				break;
			default:
					break;
			}

		}
	}
}
void print_out(int c) {
	if (c == 0) {
		system("cls");
		printf("XXXXXXX X     X  XXXX   X  XX     X   XXXXX  \n");
		printf("   X     X   X   X   X  X  X X    X  X     X \n");
		printf("   X      XXX    X   X  X  X  X   X  X       \n");
		printf("   X       X     XXXX   X  X   X  X  X  XXXX \n");
		printf("   X       X     X      X  X    X X  X    X  \n");
		printf("   X       X     X      X  X     XX   XXXXX  \n");
		printf("\n\n");
		printf("--->	START\n");
		printf("        RANKING\n");
		printf("        EXIT\n");
	}
	else if (c == 1) {
		system("cls");
		printf("XXXXXXX X     X  XXXX   X  XX     X   XXXXX  \n");
		printf("   X     X   X   X   X  X  X X    X  X     X \n");
		printf("   X      XXX    X   X  X  X  X   X  X       \n");
		printf("   X       X     XXXX   X  X   X  X  X  XXXX \n");
		printf("   X       X     X      X  X    X X  X    X  \n");
		printf("   X       X     X      X  X     XX   XXXXX  \n");
		printf("\n\n");
		printf("    	START\n");
		printf("--->    RANKING\n");
		printf("        EXIT\n");
	}
	else if (c == 2) {
		system("cls");
		printf("XXXXXXX X     X  XXXX   X  XX     X   XXXXX  \n");
		printf("   X     X   X   X   X  X  X X    X  X     X \n");
		printf("   X      XXX    X   X  X  X  X   X  X       \n");
		printf("   X       X     XXXX   X  X   X  X  X  XXXX \n");
		printf("   X       X     X      X  X    X X  X    X  \n");
		printf("   X       X     X      X  X     XX   XXXXX  \n");
		printf("\n\n");
		printf("    	START\n");
		printf("        RANKING\n");
		printf("--->    EXIT\n");
	}	
}