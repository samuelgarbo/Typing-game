#include "System.h"

int main() {

	int choice = 0;
//	system("mode con:cols=100 lines=40"); // 가로 150 세로 40의 콘솔창

	while (1) {

		switch (choice) {
		case 0:
			choice = startingMenu(1);
			break;
		case 1:	//second Menu
			choice = secondMenu(4);

			break;
		case 2:	//ranking			
			choice = rankingMenu(8);
			break;
		case 3:	//exit
			return 0;
		case 4:
			choice = WordP();
			return 0; // break; 출력되고 초기화됨.
		case 5:
		
		
		case 6:
			choice = 0;
			break;
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			choice = 0;
			break;
		}
	}
	return 0;
}