// add header comment
/*
    Robert Clark
    1071 -003
    9/21/18
    This program reads in ints from an
    input.txt file, fills a 2D array with
    values that it calculates from the read 
    input
*/
#include <stdio.h>

// #define for the number of columns
#define numCols 4

void convertInches(int rows, int array[][numCols]);
void printValues(int rows, int array[][numCols]);
FILE *fp;

int main(void) {
    // declare needed variables:
        // numRows for the number of rows
        int numRows = 0;
        fp = fopen("input.txt", "r");
        char buffer[30];
        while (fscanf(fp, "%s", buffer) == 1) // expect 1 successful conversion
        {
            numRows++;
        }
        rewind(fp);
        // array called measurements
        int measurements[numRows][numCols];  

    
    // call convertInches() sending the appropriate arguments
    convertInches(numRows, measurements);

    // call printValues() sending the appropriate arguments
    printValues(numRows, measurements);
    
    return 0;
}


// reads next value from file into 1st element of row
// fills in the rest of the elemenst of that row
// after computing yards, feet, and inches
// parameters:  the number of rows, and the 2-D array
// returns:  none
void convertInches(int rows, int array[][numCols]) {
    int totalInches, i, col = 0;
    
    for (i = 0; i < rows; i++) {
        // use scanf (or fsanf with stdin) to read in next value
        // from file and put into the 1st element of the row
        int readInt;
        fscanf(fp, "%d", &readInt); 
        array[i][col] = readInt;

        // assign to totalInches that value that was just read into
        // that 1st element of the row
        totalInches = array[i][col];


        array[i][col+1] = totalInches / 36;
        totalInches %= 36;
        array[i][col+2] = totalInches / 12;
        array[i][col+3] = totalInches % 12;
    }
    
}


// prints the contents of the 2-D array
// parameters:  the number of rows, and the 2-D array
// returns:     nothing
void printValues(int rows, int array[][numCols]) {
    int i;
    printf("\n%8s%8s%8s%8s\n\n", "total", "yards", "feet", "inches");
    
    for (i = 0; i < rows; i++) {
        printf("%8d  %6d  %6d  %6d \n", 
               array[i][0], array[i][1], array[i][2], array[i][3]);
    }
    printf("\n\n");
}
