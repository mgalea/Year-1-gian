#include "Definitions.h"

// prints the binary of the given value
void toBin(int value) {
    int i;
    printf("\n");
    for (i = 0; i < sizeof(value)*8; i++) {
        printf("%i", binaryRead(value, i));
    }
}

// stes cursor position to given x,y coords
void setCursorPos(int coords[2]) {
    printf(CURSORHOME);
    printf(CURSORPOS, coords[1], coords[0]);
}

// sets the bit at given position of the given variable to the given value
void binaryWrite(int *binaryValue,int position, int bool) {
    unsigned int inverseMask = ~(1 << position);
    if(bool==1||bool==0){
        bool = bool << position;
        *binaryValue = ((*binaryValue) & inverseMask) + bool;
    }
    else {
        printf(REDFORE"Binary Write Error: Invalid bool!"RESET);
    }
}

// reads the bit of the given int at the fiven position
int binaryRead(int binaryValue, int position) {
    unsigned int mask = 1 << position;
    return ((mask & binaryValue) >> position);
}

char puzzle[ROWS][COLUMNS];

char dictionary[][10] = { "GIRL" , "BOY" , "SHIP" , "CAT" , "FOG" , "KITE" , "BAG" , "STAMP" , "ZOOM" , "JOY", "CAR" , "BUS" , "VAN" , "BOAT" , "BIKE" , "TURBO" , "SCHOOL" , "COVID" , "VIRUS" , "STAR" };
char wordBank[WORDSTOCHOOSE][10] = {""};
unsigned int found = 0;


int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
int wordBankSize = WORDSTOCHOOSE;

int ansField[2] = { 19,ROWS + 8 };
int logField[2] = { 1,ROWS + 11 };
int wordBankField[2] = { 1,ROWS + 4 };

int remainingWords;

time_t timer;