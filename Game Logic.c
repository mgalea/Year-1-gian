#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char wordBank[WORDSTOCHOOSE][10];
extern int wordBankSize;
extern int ansField[2];
extern int logField[2];
extern int found;
int coord[4]; // startRow, startColumn, endRow, endColumn
extern int* orientationToOffsets(orientation);


extern int remainingWords;

//displays all game elements
void refresh() {
	displayPuzzle();
	displayWordBank();
	printf("\nEnter Coordinates:\t\n(e.g a1 d4) Type menu to pause the fame and open the menu\n");
	printLine(COLUMNS * 2 + 10);
}


//returns 1 if the string is a letter followed by some numbers, else retuns 0.
int isValidInput(char input[11]) {
	int i;
	int letter = input[0];

	//test for starting letter
	binaryWrite(&letter, 5, 0); // ignore case by converting to uppercase
	if (letter < 65 || letter > 90) {
		return 0;
	}

	// test for following numbers
	for (i = 1; i < strlen(input); i++) {
		if (input[i] < 48 || input[i] > 57) {
			return 0;
		}
	}
	return 1;
}

int  acceptAnswer() {
	char answer[11] = "";
	char* token;
	char* context;
	gets(answer);
	if (!answer[0]) { // prevent crash if user enters a blank answer
		setCursorPos(logField);
		printf(CLEARFIELD REDFORE"Cannot leave field blank"RESET);
		return 0;
	}
	if (strcmp(answer,"menu") == 0) { // allows the user to open the pause menu
		pauseTimer();
		pauseMenu();
		return -1;
	}
	if (!strchr(answer, ' ')) { // prevents crash if answer does not contain a space
		setCursorPos(logField);
		printf(CLEARFIELD REDFORE"Coordinates format is <letter><number> <letter><number>"RESET);
		return 0;
	}
	// start coordinate:
	token = strtok_s(answer, " ",&context);
	if (!isValidInput(token)) {
		return 0;
	}
	//start row no.
	binaryWrite(token, 5, 0); // ignore case by converting to uppercase
	coord[0] = *token - 65;
	//start column no.
	token += 1;
	coord[1] = atoi(token) - 1;

	//end row no.
	token = strtok_s(NULL, " ", &context);
	if (!isValidInput(token)) {
		return 0;
	}
	binaryWrite(token, 5, 0); // ignore case by converting to uppercase
	coord[2] = *token - 65;
	//end column no.
	token += 1;
	coord[3] = atoi(token) - 1;
	return 1;
	
	//printf("\n\n (%c,%c) -> (%c,%c)", answer[0], answer[1], answer[3], answer[4]);
	//printf("\n\n (%i,%i) -> (%i,%i)",coord[0],coord[1], coord[2], coord[3]);
}									 
									 
//returns relative orientation of coordinates. returns -1 if orientation is invlaid
int cardinalDirection() {
	int colDiff = coord[2] - coord[0];
	int rowDiff = coord[3] - coord[1];
	if (colDiff < 0 || rowDiff < 0) {
		return -1;
	}
	return !rowDiff ? 0 : rowDiff == colDiff ? 1 : !colDiff ? 2 : -1;
}

void searchBoard() {
	int orientation = cardinalDirection();
	int* offsets = orientationToOffsets(orientation);
	int yo = *offsets, xo = *(offsets + 1);
	int x = 0, y = 0, i;
	char word[11] = " ";
	char letter;
	char* bankWord = NULL;

	if (orientation == -1) {
		setCursorPos(logField);
		printf(CLEARFIELD REDFORE"Invalid Orientation, words may be vertical, horizontal, or diagonal only."RESET);
		return 0;
	}
	x = coord[0]; // column
	y = coord[1]; // row
	i = 0;
	do {
		if (i >= 10) {
			setCursorPos(logField);
			printf(CLEARFIELD REDFORE"Words cannot be longer than 10 letters."RESET);
			strcpy_s(word, 10, "");
			return 0;
		}
		letter = puzzle[y][x];
		binaryWrite(&letter, 5, 0); // remove highlight data from letter
		word[i] = letter;
		i++;
		x += xo;
		y += yo;
	} while (!(x > coord[2] || y > coord[3]));

	if (!word) {
		return 0;
	}
	
	// compare word to wordbank
	for (i = 0; i < wordBankSize; i++) {
		bankWord = wordBank[i];
		if (strcmp(bankWord, word) == 0) {
			if (getBit(found, i)) {
				setCursorPos(logField);
				printf(CLEARFIELD"You already found %s.", word);
				return 0;
			}
			binaryWrite(&found,i,1);
			displayWordBank();
			x = coord[0];
			y = coord[1];
			// highlihght word in puzzle
			do {
				binaryWrite(&puzzle[y][x],5,1);
				x += xo;
				y += yo;
			} while (!(x > coord[2] || y > coord[3]));
			refresh();
			setCursorPos(logField);
			remainingWords--;
			printf(CLEARFIELD GRNFORE"You Found %s!"RESET, word);
			return 1;
		}
	}
	setCursorPos(logField);
	printf(CLEARFIELD REDFORE"%s is not in the word bank."RESET, word);
	
}

void win() {
	extern time_t startTime;
	extern time_t timeToComplete;
	printf(CLRSCREEN GRNBACK BOLD
		"  __     __   ____    _    _    __          __  _____   _   _   _   \n"
		"  \\ \\   / /  / __ \\  | |  | |   \\ \\        / / |_   _| | \\ | | | |  \n"
		"   \\ \\_/ /  | |  | | | |  | |    \\ \\  /\\  / /    | |   |  \\| | | |  \n"
		"    \\   /   | |  | | | |  | |     \\ \\/  \\/ /     | |   | . ` | | |  \n"
		"     | |    | |__| | | |__| |      \\  /\\  /     _| |_  | |\\  | |_|  \n"
		"     |_|     \\____/   \\____/        \\/  \\/     |_____| |_| \\_| (_)  \n"
		"                                                                    "
		"\n\n"RESET);

	timeToComplete += difftime(time(NULL), startTime);
	printf("You completed a " HIGHLIGHT "%ix%i" RESET " crossword with " HIGHLIGHT "%i words" RESET " in: " HIGHLIGHT "%i:%02i:%02i\n\n" RESET
		, COLUMNS, ROWS, wordBankSize, timeToComplete / 3600, (timeToComplete% 3600) / 60, timeToComplete % 60);
	endMenu();
}




