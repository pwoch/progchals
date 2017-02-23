
#include <stdio.h>
#include <stdlib.h>

#define ROWS 15
#define COLS 15

int getBigger(int a, int b);
void printArray(int a[][COLS]);
void performSums(int a[][COLS]);

int main(){


    int tri[ROWS][COLS] = {
        {75, 0},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20,  4, 82, 47, 65},
        {19,  1, 23, 75,  3, 34},
        {88,  2, 77, 73,  7, 63, 67},
        {99, 65,  4, 28,  6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        { 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };

    printArray(tri);

    performSums(tri);

    printArray( tri);

    return EXIT_SUCCESS;
}

void printArray( int tri[][COLS]) {
    int row, col;
    row = 0;
    while( row < ROWS) {

        col = 0;
        while( col <= row) {
            printf("%d ", tri[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
}
int getBigger( int a, int b) {
    int result;
    result = (a >= b) ? a : b;
    return result;
}

void performSums(int a[][COLS]) {

    int row, col;
    int option1, option2, high;
    row = ROWS - 2;

    while( row >= 0 ) {
        col = 0;
        while( col <= row) {
            //printf("\nThe two options for a[%d][%d] are\n", row, col);
            //printf(" a[%d][%d]: %d\t a[%d][%d]: %d\n",row+1, col, a[row+1][col], row+1, col+1, a[row+1][col+1]);

            option1 = a[row+1][col];
            option2 = a[row+1][col+1];
            high = getBigger( option1, option2);

            a[row][col] = a[row][col] + high;
            col++;
        }
        row --;
    }
}
