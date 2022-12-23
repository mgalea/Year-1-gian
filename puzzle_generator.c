#include "definitions.h"
#include "puzzle_generator.h"

char puzzle[ROWS][COLUMNS];


void logWord(char *array, char word[10]);

int found;
int remainingWords;

static void createBlankPuzzle(int rows, int columns);


void newPuzzle(int rows, int columns, int wordBankSize )
{ 
    createBlankPuzzle(rows, columns);
    fillPuzzleWithWords(wordBankSize);
    fillRandom();
    remainingWords = wordBankSize;
    found = 0;
}

static void createBlankPuzzle(int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            puzzle[i][j] = '@';
        }
    }
}

void displayPuzzle()
{
    int i, j, rowNum = 0;
    int highlight;
    char letter;

    // First display column names
    printf(CLRSCREEN CURSORHOME HIGHLIGHT "     ");
    for (i = 0; i < COLUMNS; i++)
    {
        printf("%c ", 'A' + i);
    }
    printf(RESET "\n" HIGHLIGHT "  \n" RESET);

    for (i = 0; i < ROWS; i++)
    {
        printf(HIGHLIGHT "%2d" RESET "   ", rowNum + 1);
        rowNum++;
        for (j = 0; j < COLUMNS; j++)
        {
            letter = puzzle[i][j];
            highlight = getBit(letter, 5);

            printf(highlight ? GRNBACK "%c " RESET : "%c ", (letter & ~(1 << 5)));
        }
        printf("\n");
    }
}

// outputs booleans for row, column offset for a given orientaion

int *orientationToOffsets(int orientation)
{
    int output[2] = {0, 0};
    switch (orientation)
    {
    case 0:
        output[1] = 1;
        break;
    case 1:
        output[0] = 1;
        output[1] = 1;
        break;
    case 2:
        output[0] = 1;
        break;
    default:
        output[0] = 0;
        output[1] = 0;
        break;
    }
    return output;
}

// returns 1 if word is to long for given orientation, else returns 0
int getValidArea(int *maxColumn, int *maxRow, int orientation, int wordLen)
{
    switch (orientation)
    {
    case 0:                                 // Horizontal
        *maxColumn = 1 + COLUMNS - wordLen; // + 1 added due to rand() % max returning a value between 0 & max-1
        *maxRow = ROWS;
        break;
    case 1: // Diagonal
        *maxColumn = 1 + COLUMNS - wordLen;
        *maxRow = 1 + ROWS - wordLen;
        break;
    case 2: // Vertical
        *maxColumn = COLUMNS;
        *maxRow = 1 + ROWS - wordLen;
        break;
    }

    if (*maxRow <= 0 || *maxColumn <= 0)
    {
        // printf("\nArea check failed!");
        return 1;
    }
    else
    {
        // printf("\nArea check succeded!");
        return 0;
    }
}

// returns 1 if the word will intersect, returns 0 if position is valid
int collisionTest(char word[10], int column, int row, int orientation)
{
    int i;
    char letter;
    int *offsets = orientationToOffsets(orientation);
    int y = *offsets, x = *(offsets + 1);

    for (i = 0; i < strlen(word); i++)
    {
        letter = puzzle[row + i * y][column + i * x];
        // printf("\nCollision Test: testing (%i,%i). Value is %c", column + i * x, row + i * y, letter);
        if (letter == '@' || letter == word[i])
        {
            continue;
        }
        else
        {
            // printf("\nCollision check for %s failed!",word);
            return 1;
        }
    }
    // printf("\nCollision check for %s succeded!",word);
    return 0;
}

// returns 1 if no valid psition could be found for the given word in the given orintation, else returns 0
int putWord(int index, int orientation)
{
    char word[10];
    int maxRow, maxColumn;
    int startRow, startColumn;
    int i = 10; // used to prevent an infinite loop if the word has no valid positions

    int *offsets = orientationToOffsets(orientation);
    int y = *offsets, x = *(offsets + 1);

    strcpy_s(word, 10, dictionary[index]);

    if (getValidArea(&maxColumn, &maxRow, 0, strlen(word)))
    { // find a valid area that does not allow the word to go off the board, if none exists, return 1
        return 1;
    }
    // printf("\nMax coords are (%i,%i)", maxColumn, maxRow);

    do
    { // find valid postition for the word that does not overwrite another word
        startRow = rand() % maxRow;
        startColumn = rand() % maxColumn;
        // printf("\nTesting start coords (%i,%i)", startColumn, startRow);
        i--;
        if (i == 0)
        {
            return 1;
        }
    } while (collisionTest(word, startColumn, startRow, orientation));

    // printf("\nTests succeded, writing word %s", word);

    for (i = 0; i < strlen(word); i++)
    { // if all previos steps succeded, write the word into the chosen area
        puzzle[startRow + i * y][startColumn + i * x] = word[i];
    }

    logWord(&wordBank, word);                  // log the word into wordBank once it's been succesfully written
    shiftArray(&dictionary, &dictSize, index); // delete the word form the dictionary to prevent duplicates
    return 0;
}

void fillPuzzleWithWords(int numWords)
{
    int i, j, wordIndex, orientation, maxColumn, maxRow;

    for (i = 0; i < numWords; i++)
    {
        // select a random index of a word from those remaining in the list
        // printf("\nCurrent wordCount = %i", wordCount);
        wordIndex = rand() % dictSize;

        orientation = rand() % 3; // To generate a random number from 0, 1, & 2
        j = 0;

        while (putWord(wordIndex, orientation) && j < MAXITERATIONS)
        { // attempts to find pos'n for this word in this orientation 10 times before failing
            j++;
        }
    }
    getWordBankSize();
}

void fillRandom(void)
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            if (puzzle[i][j] == '@')
            {
                puzzle[i][j] = 65 + rand() % 26;
            }
        }
    }
}

// deletes array entry at the given index, and shifts remaining entries back
void shiftArray(char *array, int *arrLen, int index)
{
    memcpy(array + index * 10, array + index * 10 + 10, (*arrLen * 10) - index * 10);
    *arrLen -= 1;
}

