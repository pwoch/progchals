

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("tripin.txt","r");
    outputFile = fopen("tripout.txt","w");

    int N, i, k;
    N = 0;
    fscanf( inputFile,"%d", &N);

    int index[N];
    i = 0;
    while( i < N){
        index[i] = 0;
        i++;
    }
    int num;
    i = 0;
    k = 0;
    while( i < N){
        fscanf( inputFile,"%d", &num);
        if( num %3 == 0){
            index[k] = i;
            k++;
        }
        i++;
    }
    if( k != 0){
        fprintf( outputFile,"%d\n", k);
        i = 0;
        while( i < k){
            fprintf( outputFile,"%d ",index[i]+1);
            i++;
        }
    } else{
        fprintf( outputFile,"Nothing here!");
    }

    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
