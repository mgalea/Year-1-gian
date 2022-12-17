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

//extern char chosenWords[WORDSTOCHOOSE][10];






int main(void)
{
    extern time_t timer;
    int Continue = 0;
    time(&timer);
    //createMenu()

    srand(time(NULL));
    createBlankPuzzle();
    fillPuzzleWithWords();
    //displayPuzzle();
    fillRandom();
    displayPuzzle();
    displayWordBank();
    remainingWords = wordBankSize;

    // main gameplay loop:
    printf("\nEnter Coordinates:\t\n(e.g A1 D4 or a1 d4)\n");
    printLine(COLUMNS*2 + 10);
   
    //remainingWords = 0; //used for testing post-game
    while (remainingWords) {
        setCursorPos(ansField);
        printf(CLEARFIELD); // erase previous answer
        if(acceptAnswer()){
            searchBoard();
        }
    }
    win();
    getchar();
    return 0;
}