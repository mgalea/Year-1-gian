/*

1. Start by defining a 2D array of asterisks.

2. Impliment a function to display the array of asterisks.

3. Decide which 4 words to use for this puzzle.

4. Populate the 2D array of asterisks with the words that the user will have to guess.
    i)   do not allow words to go out of the puzzle space
    ii)  do not allow words to overwrite eachother
    iii) do allow words to overlap if they share a letter

5. Fill the rest of the 2D array with randomly generated characters.

6. Allow the user to play the game by guessing the words.
    i)   Main menu to select New Game or Exit
    ii)  show word bank and indicate found words
    iii) show found words on puzzle (uppercase --> lowercase?)
    iv)  win condition on finding all words
    V)   timer??

----------------------------------------------------------------------------------------
*/

#include "Definitions.h"
#include "Globals.h"

extern char puzzle[ROWS][COLUMNS];

extern char dictionary[][10];

extern int remainingWords;

extern time_t startTime;

void newPuzzle() {
    found = 0;
    createBlankPuzzle();
    fillPuzzleWithWords();
    fillRandom();
    remainingWords = wordBankSize;
}

void game() {
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