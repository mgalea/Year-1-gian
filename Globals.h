#include "Definitions.h"

char puzzle[ROWS][COLUMNS];

char dictionary[][10] = { "GIRL" , "BOY" , "SHIP" , "CAT" , "FOG" , "KITE" , "BAG" , "STAMP" , "ZOOM" , "JOY", "CAR" , "BUS" , "VAN" , "BOAT" , "BIKE" , "TURBO" , "SCHOOL" , "COVID" , "VIRUS" , "STAR" };

//char chosenWords[WORDSTOCHOOSE][10];

int wordCount = sizeof(dictionary) / sizeof(dictionary[0]);