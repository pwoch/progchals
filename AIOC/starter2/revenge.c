

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("dishin.txt","r");
    outputFile = fopen("dishout.txt","w");

    int min, max, mean;
    int num, i, N;

    mean = 0;
    i = 0;
    fscanf(inputFile,"%d", &N);
    while( i < N) {
        fscanf(inputFile,"%d", &num);
        mean += num;
        if( i == 0) {
            max = num;
            min = num;
        } else if( num > max){
            max = num;
        } else if( num < min){
            min = num;
        }
        i++;
    }

    mean /= N;

    fprintf(outputFile,"%d %d %d", min, max, mean);

    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
