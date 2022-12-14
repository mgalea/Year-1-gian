#include "Definitions.h"

void setCursorPos(int x, int y) {
    printf(CURSORHOME);
    printf(CURSORPOS, y, x);
}

char puzzle[ROWS][COLUMNS];

char dictionary[][10] = { "GIRL" , "BOY" , "SHIP" , "CAT" , "FOG" , "KITE" , "BAG" , "STAMP" , "ZOOM" , "JOY", "CAR" , "BUS" , "VAN" , "BOAT" , "BIKE" , "TURBO" , "SCHOOL" , "COVID" , "VIRUS" , "STAR" };
char wordBank[WORDSTOCHOOSE][10];

int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
int wordBankSize = WORDSTOCHOOSE;