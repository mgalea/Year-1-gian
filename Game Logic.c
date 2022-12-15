#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char wordBank[WORDSTOCHOOSE][10];
extern int ansField[2];
extern int logField[2];
int coord[4]; // startRow, startColumn, endRow, endColumn

void logError(char error[30]) {
	setCursorPos(logField);
	printf(REDFORE"%s"RESET,error);
	setCursorPos(ansField);
}

void acceptAnswer() {
	char answer[10];
	gets(answer);
	coord[0] = answer[0]-65;
	coord[1] = answer[1]-49;
	coord[2] = answer[3]-65;
	coord[3] = answer[4]-49;
	//printf("\n\n%s", answer);
	//printf("\n\n (%c,%c) -> (%c,%c)", answer[0], answer[1], answer[3], answer[4]);
	//printf("\n\n (%i,%i) -> (%i,%i)",coord[0],coord[1], coord[2], coord[3]);
}									 
									 
									 
int isCardinalDirection() {
	
}

