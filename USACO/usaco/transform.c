
/*
ID: wochnow1
PROG: transform 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printBoard(char** a, int N);
char* reverse(char *s, int N);
int compareStr(char* a, char* b);



int main() {

    FILE* inFile = fopen("transform.in","r");
    FILE* outFile = fopen("transform.out","w");

    int N;
    fscanf(inFile,"%d", &N);
    fscanf(inFile,"\n");



    int i, j, k;
    char o[N][N];
    for( i = 0; i < N; i++) {

        for( j = 0; j < N; j++) {
            fscanf(inFile,"%c", &o[i][j]);
        }
        fscanf(inFile,"\n");
    }
    printf("Original\n");
    for( i = 0; i<N; i++) {
        for( k = 0; k< N; k++) {
            printf("%c ",o[i][k]);
        }
        printf("\n");
    }

    char r[N][N];

    for( i = 0; i < N; i++) {

        for( j = 0; j < N; j++) {
            fscanf(inFile,"%c", &r[i][j]);
        }
        fscanf(inFile,"\n");
    }
    printf("Transformation\n");
    for( i = 0; i<N; i++) {
        for( k = 0; k< N; k++) {
            printf("%c ",r[i][k]);
        }
        printf("\n");
    }
    char dummy[N][N];
    for( i = 0; i < N; i++) {
        for( k = 0; k < N; k++) {
            dummy[i][k] = o[i][k];
        }
    }


    char try[N][N];
    

    int stop = 1;
    for( j = 90; j < 360; j+=90){

        stop = 1;
        printf("%d degree rotation\n", j);
        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                try[i][k] = dummy[(N-1)-k][i];
            }
        }
        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                dummy[i][k] = try[i][k];
            }
        }

        for( i = 0; i<N; i++) {
            for( k = 0; k< N; k++) {
                printf("%c ",try[i][k]);
            }
            printf("\n");
        }

        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                if( try[i][k] != r[i][k]) {
                    printf("Not matching\n\n");
                    stop = 0;
                    break;
                }
            }
            if(stop == 0){
                break;
            }
        }
        if( stop ) {
            printf("Matching\n");
            fprintf(outFile,"%d\n",j/90);
            return 0;
        }
    }

    for( i = 0; i < N; i++) {
        for( k = 0; k < N; k++) {
            dummy[i][k] = o[i][(N-1)-k];
        }
    }
    printf("Reflection\n");
    stop = 1;
    for( i = 0; i<N; i++) {
        for( k = 0; k< N; k++) {
            printf("%c ",dummy[i][k]);
        }
        printf("\n");
    }
    for( i = 0; i < N; i++) {
        for( k = 0; k < N; k++) {
            if( dummy[i][k] != r[i][k]) {
                printf("Not matching\n\n");
                stop = 0;
                break;
            }
        }
        if(stop == 0){
            break;
        }
    }
    if( stop ) {
        printf("Matching\n");
        fprintf(outFile,"%d\n",4);
        return 0;
    }


    for( j = 90; j < 360; j+=90){

        stop = 1;
        printf("Reflection + %d degree rotation\n", j);
        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                try[i][k] = dummy[(N-1)-k][i];
            }
        }
        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                dummy[i][k] = try[i][k];
            }
        }

        for( i = 0; i<N; i++) {
            for( k = 0; k< N; k++) {
                printf("%c ",try[i][k]);
            }
            printf("\n");
        }

        for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                if( try[i][k] != r[i][k]) {
                    printf("Not matching\n\n");
                    stop = 0;
                    break;
                }
            }
            if(stop == 0){
                break;
            }
        }
        if( stop ) {
            printf("Matching\n");
            fprintf(outFile,"%d\n",5);
            return 0;
        }
    }

    printf("Checking original\n");
    for( i = 0; i < N; i++) {
            for( k = 0; k < N; k++) {
                if( o[i][k] != r[i][k]) {
                    printf("Not matching\n\n");
                    stop = 0;
                    break;
                }
            }
            if(stop == 0){
                break;
            }
        }
        if( stop ) {
            printf("Matching\n");
            fprintf(outFile,"%d\n",6);
            return 0;
        }else {
            printf("Invalid Transformation\n");
            fprintf(outFile,"%d\n",7);
        }





    fclose(inFile);
    fclose(outFile);

    return 0;
}
