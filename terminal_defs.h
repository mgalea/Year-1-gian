#ifndef TERMINAL_DEFS_H
#define TERMINAL_DEFS_H

#define WINDOWS 0
#define BLANK ""

#if WINDOWS

    #define HIGHLIGHT BLANK 
    #define REDBACK BLANK 
    #define GRNBACK BLANK 
    #define REDFORE BLANK 
    #define GRNFORE BLANK 
    #define BOLD BLANK 
    #define RESET BLANK 
    #define CURSORPOS BLANK 
    #define CURSORHOME BLANK 
    #define CLEARFIELD BLANK 
    #define CLEARLINE BLANK 
    #define CLRSCREEN BLANK 
    #define SAVEPOS BLANK 
    #define RECALLPOS BLANK 
#else

    #define HIGHLIGHT "\x1b[7m"
    #define REDBACK "\x1b[41m"
    #define GRNBACK "\x1b[42m"
    #define REDFORE "\x1b[31m"
    #define GRNFORE "\x1b[32m"
    #define BOLD "\x1b[1m"
    #define RESET "\x1b[0m"
    #define CURSORPOS "\x1b[%i;%iH"
    #define CURSORHOME "\x1b[H"
    #define CLEARFIELD "\x1b[0K"
    #define CLEARLINE "\x1b[2K"
    #define CLRSCREEN "\x1b[2J" CURSORHOME
    #define SAVEPOS "\x1b 7"
    #define RECALLPOS "\x1b 8"
#endif



#endif
