

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("countin.txt","r");
    outputFile = fopen("countout.txt","w");

    int N, i;

    fscanf( inputFile,"%d", &N);

    i = 1;
    while( i <= N) {
        fprintf( outputFile,"%d\n", i);
        i++;
    }

    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}

