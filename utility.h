
/**
 * @file utility.h
 * @brief General Utility functions
 * 
 * @param num integer to be converted
 */



/**
 * @brief Decimal to Binary Convertor
 * 
 * @param num 
 */
void decimalToBinary(int num);


// stes cursor position to given x,y coords
void setCursorPos(int coords[2]);


// sets the bit at given position of the given variable to the given value
void binaryWrite(int *binaryValue, int position, int boolean);


// reads the bit of the given int at the given position
int getBit(int binaryValue, int position);

