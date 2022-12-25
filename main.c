/**
 * @file main.c
 * @author Gianluca Galea (you@domain.com)
 * @brief Year 1 First Semester Assignment
 * @version 0.1
 * @date 2022-12-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "terminal_defs.h"
#include "menu.h"
#include "puzzle.h"


int main(void)
{
    while (mainMenu() == 1)
    {
		printf("\x1b[1A"
			   "\x1b[50D" CLEARLINE "Enter Option: ");
        newPuzzle(); // generate the puzzle

        // game();                                       //lets watch the game...
    };

    return 0;
}