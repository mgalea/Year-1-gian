#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Program now supports boards up to 26 columns and 19 rows, and up to 20 hidden word
// (hidden words restriceted by number of words in dictionary)
// (board dimensions restricted by no. of letters and terminal scrolling)


#define ROWS 10             // number of rows
#define COLUMNS 10          // number of columns
#define AREA (ROWS*COLUMNS) // area covered by puzzle

#define WORDSTOCHOOSE 4     // affects the chance of not finding a valid position for a word
#define MAXITERATIONS 50    // affects the chance of not finding a valid position for a word


// Escape Codes for Display:
#define HIGHLIGHT  "\x1b[7m"
#define REDBACK    "\x1b[41m"
#define GRNBACK    "\x1b[42m"
#define REDFORE    "\x1b[31m"
#define GRNFORE    "\x1b[32m"
#define BOLD	   "\x1b[1m"
#define RESET      "\x1b[0m"
#define CURSORPOS  "\x1b[%i;%iH"
#define CURSORHOME "\x1b[H"
#define CLEARFIELD "\x1b[0K"
#define CLEARLINE  "\x1b[2K"
#define CLRSCREEN  "\x1b[2J"CURSORHOME
#define SAVEPOS	   "\x1b 7"
#define RECALLPOS  "\x1b 8"

#endif



