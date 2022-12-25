#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal_defs.h"

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
void binaryWrite(int *binaryValue, int position, int boolean)
{
    unsigned int inverseMask = ~(1 << position);
    if (boolean == 1 || boolean == 0)
    {
        boolean = boolean << position;
        *binaryValue = ((*binaryValue) & inverseMask) + boolean;
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
