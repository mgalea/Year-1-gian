#include "Definitions.h"

void printLine(int width) {
	int i;
	for (i = 0; i < width; i++) {
		printf(BOLD"-"RESET);
	}
}

void mainMenu() {
	printf(
 "    "HIGHLIGHT  "  _____  _____    ____    _____  _____ __          __ ____   _____   _____  "RESET"\n"
 "  "HIGHLIGHT "   / ____||  __ \\  / __ \\  / ____|/ ____|\\ \\        / // __ \\ |  __ \\ |  __ \\   "RESET"\n"
 ""HIGHLIGHT"    | |     | |__) || |  | || (___ | (___   \\ \\  /\\  / /| |  | || |__) || |  | |    "RESET"\n"
 ""HIGHLIGHT"    | |     |  _  / | |  | | \\___ \\ \\___ \\   \\ \\/  \\/ / | |  | ||  _  / | |  | |    "RESET"\n"
 "  "HIGHLIGHT "  | |____ | | \\ \\ | |__| | ____) |____) |   \\  /\\  /  | |__| || | \\ \\ | |__| |  "RESET"\n"
 "    "HIGHLIGHT  " \\_____||_|  \\_\\ \\____/ |_____/|_____/     \\/  \\/    \\____/ |_|  \\_\\|_____/ "RESET"\n"
	);
	printf(BOLD"\n\t1. New Game\n\n\t2. Quit\n\n"RESET);
	printLine(40);
	printf("\n Option: ");
}