#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("listin.txt","r");
    outputFile = fopen("listout.txt","w");
    
    int players[1001] = {0};
    int i, N, num1, num2;
    num1 = 0;

    fscanf( inputFile,"%d", &N);
    i = 0;
    while( i < 2*N){
        fscanf( inputFile,"%d", &num1);
        players[num1]++;
        i++;
    }

    int max = 0;
    i = 0;
    while( i <= 1000){
        if( players[i] > max){
            max = players[i];
        }
        i++;
    }

    i = 0;
    if(max != 0){
        while( i <= 1000){
            if( players[i] == max){
                fprintf( outputFile,"%d\n", i);
            }
            i++;
        }
    }


    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
