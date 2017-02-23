

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("rainin.txt","r");
    outputFile = fopen("rainout.txt","w");

    int N, size;

    fscanf(inputFile, "%d %d", &N, &size);
    int rain, filled, i; 

    filled = 0;
    i = 0;
    while( filled < size) {
        fscanf(inputFile,"%d", &rain);
        filled+= rain;
        i++;
    }

    fprintf(outputFile,"%d", i); 

    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
