#ifndef GLOBALS_H
#define GLOBALS_H

#include <time.h>
#include "definitions.h"

void binaryWrite(int *, int, int);
void setCursorPos(int coords[2]);
int getBit(int, int);


int wordBankSize = WORDSTOCHOOSE;

int ansField[2] = {19, ROWS + 8};
int logField[2] = {1, ROWS + 11};
int wordBankField[2] = {1, ROWS + 4};

int remainingWords;

time_t startTime;
time_t timeToComplete = 0;

// prints the binary of the given value

void decimalToBinary(int num)
{

    if (num == 0)
    {
        printf("0");
        return;
    }

    int binaryNum[32];
    int i = 0;

    for (; num > 0;)
    {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    // Printing array in reverse order.
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// stes cursor position to given x,y coords
void setCursorPos(int coords[2])
{
    printf(CURSORHOME);
    printf(CURSORPOS, coords[1], coords[0]);
}

// sets the bit at given position of the given variable to the given value
void binaryWrite(int *binaryValue, int position, int bool)
{
    unsigned int inverseMask = ~(1 << position);
    if (bool == 1 || bool == 0)
    {
        bool = bool << position;
        *binaryValue = ((*binaryValue) & inverseMask) + bool;
    }
    else
    {
        printf(REDFORE "Binary Write Error: Invalid bool!" RESET);
    }
}

// reads the bit of the given int at the given position
int getBit(int binaryValue, int position)
{
    return ((binaryValue >> (position % 32)) & 1);
}

#endif