#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char dictionary[][10];
extern int dictSize;
extern int wordBankSize;
extern char wordBank[WORDSTOCHOOSE][10];
extern int found;

// shifts the array forward, and logs the given word into the array at index 0
void logWord(char* array, char word[10]) {
	memcpy(array + 10, array, (WORDSTOCHOOSE - 1) * 10);
	memcpy(array, word, 10);
}

// used to account for words that were meant to be chosen, but could't be placed
void getWordBankSize() {
	int i;
	for (i = 0; i < WORDSTOCHOOSE*10; i++) {
		//checks the first letter in every entry in wordBank for a NULL character.
		if (wordBank[i][0] == '\0') {
			wordBankSize = i;
			break;
		}
	}
}

void displayWordBank() {
	int i;
	getWordBankSize();
	printf("\n%i Words to Find:\n", wordBankSize);
	for (i = 0; i < WORDSTOCHOOSE; i++) {
		//printf("\n%i: %i ",i, binaryRead(found, i));
		printf(binaryRead(0,i) ? GRNBACK"%s"RESET", " : REDBACK"%s"RESET", ", wordBank[i]);
	}
	printf("\b\b \b\n"); // erase the final ", "
}