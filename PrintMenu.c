#include "System.h"


void printMenu(int choice) {
	switch (choice) {
	case 0:		
	case 1:	//STARTING MENU
		printf("\t###################\n");
		printf("\t#  --->  START    #\n");
		printf("\t#        RANKING  #\n");
		printf("\t#        EXIT     #\n");
		printf("\t###################\n");
		break;
	case 2:
		printf("\t###################\n");
		printf("\t#        START    #\n");
		printf("\t#  --->  RANKING  #\n");
		printf("\t#        EXIT     #\n");
		printf("\t###################\n");
		break;	
	case 3:
		printf("\t###################\n");
		printf("\t#        START    #\n");
		printf("\t#        RANKING  #\n");
		printf("\t#  --->  EXIT     #\n");
		printf("\t###################\n");
		break;
	case 4:
		printf("\t###################\n");
		printf("\t#  --->  PRACTICE #\n");
		printf("\t#        GAMES    #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 5:
		printf("\t###################\n");
		printf("\t#        PRACTICE #\n");
		printf("\t#  --->  GAMES    #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 6:
		printf("\t###################\n");
		printf("\t#        PRACTICE #\n");
		printf("\t#        GAMES    #\n");
		printf("\t#  --->  BACK     #\n");
		printf("\t###################\n");
		break;
	case 7:	//RANKING MENU
		printf("\t###################\n");
		printf("\t#  --->  WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 8:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#  --->  SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 9:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#  --->  LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 10:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#  --->  GAME     #\n");
		printf("\t#        BACK     #\n");
		printf("\t###################\n");
		break;
	case 11:
		printf("\t###################\n");
		printf("\t#        WORDS    #\n");
		printf("\t#        SHORT    #\n");
		printf("\t#        LONG     #\n");
		printf("\t#        GAME     #\n");
		printf("\t#  --->  BACK     #\n");
		printf("\t###################\n");
		break;	

	}
}