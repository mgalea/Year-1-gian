
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal_defs.h"
#include "globals.h"

char wordBank[][10] = {"GIRL", "BOY", "SOLDIER", "STAR", "SPACESHIP", "ROCKET", "ALIEN", "UFO", "SUN", "PLANET", "ZAPHOD"};

int dictSize = sizeof(wordBank) / sizeof(wordBank[0]);
int wordBankSize = WORDSTOCHOOSE;

// shifts the array forward, and logs the given word into the array at index 0
void logWord(char *array, char word[10])
{
	memcpy(array + 10, array, (WORDSTOCHOOSE - 1) * 10);
	memcpy(array, word, 10);
}

// used to account for words that were meant to be chosen, but could't be placed
void getWordBankSize()
{
	int i;
	for (i = 0; i < WORDSTOCHOOSE; i++)
	{
		// checks the first letter in every entry in wordBank for a NULL character.
		if (wordBank[i][0] == '\0')
		{
			wordBankSize = i;
			break;
		}
	}
}

void displayWordBank(int found)
{
	int i;
	setCursorPos(wordBankField);
	printf("\n" CLEARFIELD "%i Words to Find : \n" CLEARFIELD, wordBankSize);
	for (i = 0; i < WORDSTOCHOOSE; i++)
	{
		printf(getBit(found, i) ? GRNBACK "%s" RESET ", " : REDBACK "%s" RESET ", ", wordBank[i]);
	}
	printf("\b\b \b\n"); // erase the final ", "
}