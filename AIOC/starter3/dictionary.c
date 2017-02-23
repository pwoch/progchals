

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("dictin.txt","r");
    outputFile = fopen("dictout.txt","w");


    int N, queries;
    fscanf( inputFile,"%d %d", &N, &queries);

    int dict[2][N];
    int i = 0;
    while(i < N){
        fscanf( inputFile,"%d %d", &dict[0][i], &dict[1][i]);
        i++;
    }
    int j, q, found;
    
    i = 0;
    while( i < queries){
        fscanf( inputFile,"%d", &q);
        
        j = 0;
        found = 0;
        while( j < N){
            if( dict[0][j] == q){
                fprintf( outputFile,"%d\n",dict[1][j]);
                found = 1;
                break;
            }
            j++;
        }
        if( !found){
            fprintf( outputFile,"%s\n","C?");
        }
        i++;
    }
        






    fclose( inputFile);
    fclose( outputFile);

    return EXIT_SUCCESS;
}
