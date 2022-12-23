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

time_t startTime;

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

    return 1;
}

void startTimer() {
    time(&startTime);
}

void pauseTimer() {
    timeToComplete += difftime(time(NULL), startTime);
}

void resumeTimer() {
    time(&startTime);
}

void endTimer() {
    time(&startTime);
}

int main(void)
{
    while(mainMenu()){

        newPuzzle(ROWS, COLUMNS, WORDSTOCHOOSE);        //generate the puzzle

        startTimer();                                   //start the game timer

		//game();                                       //lets watch the game...

    };

    return 0;
}