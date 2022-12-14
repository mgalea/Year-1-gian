#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char dictionary[][10];
extern int dictSize;
extern int wordBankSize;
extern char wordBank[WORDSTOCHOOSE][10];

// used to account for words that were meant to be chosen, but could't be placed
void getWordBankSize() {
	int i;
	for (i = 0; i < WORDSTOCHOOSE; i += 10) {
		//checks the first letter in every entry in wordBank for a NULL character.
		if (!wordBank[i]) {
			wordBankSize = i / 10;
			break;
		}
	}
}

void displayWordBank() {
	int i;
	getWordBankSize();
	printf("\nWord Bank:\n");
	for (i = 0; i < wordBankSize; i++) {
		printf("%s, ", wordBank[i]);
	}
}