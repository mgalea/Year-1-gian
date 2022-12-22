#ifndef PUZZLE_GEN_H
#define PUZZLE_GEN_H

void createBlankPuzzle();
void createBlankPuzzle();

int* orientationToOffsets(int orientation);
int getValidArea(int* maxColumn, int* maxRow, int orientation, int wordLen);
int collisionTest(char word[10], int column, int row, int orientation);
int putWord(int index, int orientation);

void fillPuzzleWithWords();

void fillRandom(void);

#endif
