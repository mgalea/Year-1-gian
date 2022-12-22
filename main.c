#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "globals.h"
#include "definitions.h"
#include "menu.h"
#include "puzzle_generator.h"
#include "game_logic.h"

char puzzle[ROWS][COLUMNS];

char dictionary[][10];

int remainingWords;

time_t startTime;

void newPuzzle() {
    found = 0;
    createBlankPuzzle();
    fillPuzzleWithWords();
    fillRandom();
    remainingWords = wordBankSize;
}


int game() {

    refresh();

    //remainingWords = 0; //used for testing post-game
    while (remainingWords) {
        setCursorPos(ansField);
        printf(CLEARFIELD); // erase previous answer
        switch (acceptAnswer())
        {
        case 1:
            searchBoard();
            break;

        case -1:
            return 0;
            break;
            
        default:
            break;
        }

    }
    win();
}

void pauseTimer() {
    timeToComplete += difftime(time(NULL), startTime);
}
void resumeTimer() {
    time(&startTime);
}


int main(void)
{
    time(&startTime);
    srand(time(NULL));
    mainMenu();
    return 0;
}