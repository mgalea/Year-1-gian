
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"
#include "terminal_defs.h"
#include "menu.h"
#include "timer.h"


void printLine(int width)
{
	for (int i = 0; i < width; i++)
	{
		printf(BOLD "_" RESET);
	}
}

// loops until the user enters an integer within the specified range, then returns it.
int userInput(int min, int max)
{
	char answer[10];
	int value;
	printf("\n\n");
	do
	{
		printf("\x1b[1A"
			   "\x1b[50D" CLEARLINE "Enter Option: ");

		gets(answer);
		value = atoi(answer);
		if (value > max || value < min)
		{
			printf(REDFORE "Invalid Option" RESET);
		}
	} while (value > max || value < min);
	return value;
}

int mainMenu()
{
	printf(CLRSCREEN
		   "    " HIGHLIGHT BOLD "  _____  _____    ____    _____  _____ __          __ ____   _____   _____  " RESET "\n"
		   "  " HIGHLIGHT BOLD "   / ____||  __ \\  / __ \\  / ____|/ ____|\\ \\        / // __ \\ |  __ \\ |  __ \\   " RESET "\n"
		   "" HIGHLIGHT BOLD "    | |     | |__) || |  | || (___ | (___   \\ \\  /\\  / /| |  | || |__) || |  | |    " RESET "\n"
		   "" HIGHLIGHT BOLD "    | |     |  _  / | |  | | \\___ \\ \\___ \\   \\ \\/  \\/ / | |  | ||  _  / | |  | |    " RESET "\n"
		   "  " HIGHLIGHT BOLD "  | |____ | | \\ \\ | |__| | ____) |____) |   \\  /\\  /  | |__| || | \\ \\ | |__| |  " RESET "\n"
		   "    " HIGHLIGHT BOLD " \\_____||_|  \\_\\ \\____/ |_____/|_____/     \\/  \\/    \\____/ |_|  \\_\\|_____/ " RESET "\n");
	
	
	printf(BOLD "\n\t1. New Game\n\n\t2. Quit\n\n" RESET);

	printLine(40);

	return (userInput(1, 2));
}

int pauseMenu()
{
	printf(CLRSCREEN BOLD "\t\tGame Paused\n" RESET);
	printLine(45);
	printf("\n\n\t1. Resume Game\n\t2. Main Menu\n\t3. Quit\n\n");
	printLine(45);
	switch (userInput(1, 3))
	{
	default:
		return 0;
		break;
	case 1:
		resumeTimer(startTime);
		//game();
		return 0;
		break;
	case 2:
		printf(CLRSCREEN REDFORE BOLD "Are You Sure?\nThis will delete your progress.\n" RESET);
		printLine(30);
		printf("\n1. Yes, I'm sure\n2. Cancel\n");
		printLine(30);
		if (userInput(1, 2) == 1)
		{
			mainMenu();
		}
		else
		{
			pauseMenu();
		}

		return 0;
		break;
	case 3:
		printf(CLRSCREEN REDFORE BOLD "Are You Sure?\nThis will delete your progress.\n" RESET);
		printLine(30);
		printf("\n1. Yes, I'm sure\n2. Cancel\n");
		printLine(30);
		if (userInput(1, 2) == 1)
		{
			return 0;
		}
		else
		{
			pauseMenu();
		}

		return 0;
		break;
	}
	return 1;
}

int endMenu()
{
	printLine(60);
	printf("\n1. New Game\n2. Return to Main Menu\n3. Quit\n");
	printLine(60);
	switch (userInput(1, 3))
	{
	default:
		break;
	case 1:
		//newPuzzle();
		//game();
		break;
	case 2:
		mainMenu();
		return 0;
		break;
	case 3:
		return 0;
		break;
	}
}
