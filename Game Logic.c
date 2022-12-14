#include "Definitions.h"

extern char puzzle[ROWS][COLUMNS];
extern char wordBank[WORDSTOCHOOSE][10];

void acceptAnswer() {
	getchar();
	char answer[10];
	scanf_s(&answer);
}

