#include "System.h"


int rankingMenu(int choice) {
	int c;
	printLogo();
	printMenu(choice);
	while (1) {
		c = getch();
		if (c == 13) {	//if ENTER return choice
			return choice;
		}
		if (c == 224) {
			c = getch();
			switch (c) {
			case 72:	//UP
				if (choice > 8) {
					choice--;
				}
				printLogo();
				printMenu(choice);
			
				break;
			
			case 80:	//DOWN
				if (choice < 12) {
					choice++;
				}
				printLogo();
				printMenu(choice);

				break;
			default:
				break;
			}
		}
	}
}