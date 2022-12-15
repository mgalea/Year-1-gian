#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char wordBank[WORDSTOCHOOSE][10];
extern int ansField[2];
extern int logField[2];
int coord[4]; // startRow, startColumn, endRow, endColumn

void logError(char error[30]) {
	setCursorPos(logField);
	printf("%*c", 50);
	setCursorPos(logField);
	printf(REDFORE"%s"RESET,error);
	setCursorPos(ansField);
}

void acceptAnswer() {
	char answer[10];
	char* token;
	char* context;
	gets(answer);
	// start coordinate:
	token = strtok_s(answer, " ",&context);

	//start row no.
	coord[0] = *token - 65;
	//start column no.
	token += 1;
	coord[1] = atoi(token) - 1;

	//end row no.
	token = strtok_s(NULL, " ", &context);
	coord[2] = *token - 65;
	//end column no.
	token += 1;
	coord[3] = atoi(token) - 1;

	
	//printf("\n\n (%c,%c) -> (%c,%c)", answer[0], answer[1], answer[3], answer[4]);
	//printf("\n\n (%i,%i) -> (%i,%i)",coord[0],coord[1], coord[2], coord[3]);
}									 
									 
									 
int isCardinalDirection() {
	int colDiff = coord[2] - coord[0];
	int rowDiff = coord[3] - coord[1];
	return (!colDiff || !rowDiff || colDiff == rowDiff) ? 1 : 0;
}

