

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("encyin.txt","r");
    outputFile = fopen("encyout.txt","w");

    int size, queries;
    fscanf( inputFile,"%d %d", &size, &queries);

    int pages[size];
    int num, i;
    
    i = 0;
    while( i < size){
        fscanf( inputFile, "%d", &num);
        pages[i] = num;
        i++;
    }

    i = 0;
    while( i < queries){
        fscanf( inputFile,"%d", &num);
        fprintf( outputFile,"%d\n", pages[num-1]);
        i++;
    }
    
    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
