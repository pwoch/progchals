
/*
ID: wochnow1
PROG: beads 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEBUG 1
#define DEBUG2



int main() {

    FILE* inFile = fopen("beads.in","r");
    FILE* outFile = fopen("beads.out","w");

    int N;
    fscanf(inFile,"%d", &N);
    char* str1 = malloc(N);
    fscanf(inFile,"%s", str1);
    
    
    char str[2*N];
    strcpy(str, str1);
    strcat(str, str1);
    free(str1);

    int startB = 0, startR = 0;
    int endB = 0, endR = 0;
    int lengthB = 0, lengthR = 0;
    int collectR = 1;
    int length = 0;
    int max = 0;
    int i, j;
    
    if( str[0] != 'b'){
        collectR = 1;
        startR = 0;
        endR = 0;

    } else {
        collectR = 0;
        startB = 0;
        endB = 0;
    }

    for( i = 0; i < N; i++) {
        if( collectR) {
            if( str[i] != 'b'){
                endR = i;
            } else {
                collectR = 0;
                lengthR = endR - (startR-1);
                length = lengthR + lengthB;
#ifdef DEBUG
                printf("Blue starting from %d to %d\n", startB, endB);
                printf("Red starting from %d, finishing at %d\n", startR, endR);
                printf("Length is: %d, Max is %d\n", length, max);
#endif
                if( length > max){
                    max = length;
#ifdef DEBUG
                    printf("New biggest length of size %d found: \n", max);
                    //printf("Blue starting from %d to %d\n", startB, endB);
                    //printf("Red starting from %d to %d\n", startR, endR);

                    for( j = startB; j <= endB; j++){
                        printf("%c", str[j]);
                    }
                    printf("|");
                    for( j = startR; j <= endR; j++){
                        printf("%c", str[j]);
                    }
                    printf("\n");
#endif
                } 
#ifdef DEBUG
                printf("\n");
#endif
                startB = i;
                endB = i;

            }
        } else {
            if( str[i] != 'r'){
                endB = i;
            } else {
                collectR = 1;
                lengthB = endB - (startB-1);
                length = lengthR + lengthB;
#ifdef DEBUG
                printf("Red starting from %d, finishing at %d\n", startR, endR);
                printf("Blue starting from %d to %d\n", startB, endB);
                printf("Length is: %d, Max is %d\n", length, max);
#endif
                if( length > max){
                    max = length;
#ifdef DEBUG
                    printf("New biggest length of size %d found: \n", max);
                    //printf("Blue starting from %d to %d\n", startB, endB);
                    //printf("Red starting from %d to %d\n", startR, endR);

                    for( j = startR; j <= endR; j++){
                        printf("%c", str[j]);
                    }
                    printf("|");
                    for( j = startB; j <= endB; j++){
                        printf("%c", str[j]);
                    }
                    printf("\n");
#endif
                }
#ifdef DEBUG
                printf("\n");
#endif
                startR= i;
                endR = i;

            }

        }
    }
    
    int lengthR1, lengthB1, length1, length2, lengthB2, lengthR2;
    int endR2, endB2, startB2, startR2;
#ifdef DEBUG
    printf("StartR: %d, EndR: %d\nStartB: %d, EndB: %d\n", startR, endR, startB, endB);
#endif
    if( collectR ) {
        if( startR != 0) {
            i = 0;
            while( str[i] != 'b') { 
                endR = i;
                i++;
            }
            if( i != 0){
                endR += N;
            }

            i = startB - 1;
            while( i > (endR-N)  && str[i] != 'r'){
                startB = i;
                i --;
            }
#ifdef DEBUG
            printf("Red inital until %d\n", endR);
            printf("Blue can start from %d\n", startB);
#endif
            startR2 = startR; 
            endR2 = N -1;
            lengthB1 = endB - (startB-1);
            lengthR1 = endR - (startR-1);
            lengthB = lengthB1;
            i = 0;
            while( str[i] != 'r' && i < startR2) { 
                endB2 = i;
                i++;
            }

            i = startR2 - 1;
            printf("%c %d\n\n", str[i], i);
            while( i > (endB2)  && str[i] != 'b'){
                startR2 = i;
                i --;
            }
#ifdef DEBUG
            printf("Blue from start until %d\n", endB2+N);
            printf("Red start from %d until end\n", startR2);
            printf("\n");
#endif

            lengthB2 = endB2+1;
            lengthR2 = endR2 - (startR2-1);
            length1 = lengthR1 + lengthB1;
            length2 = lengthR2 + lengthB2;
            printf("length1 : %d legnth2 %d\n", length1, length2);
            if( length1 > length2) {
                lengthB = lengthB1;
            } else {
                lengthB = lengthB2;
                endR = endR2;
                startR = startR2;
            }
        }

        lengthR = endR - (startR-1);
        length = lengthR + lengthB;
    } else {
        if( startB != 0) {
            i = 0;
            while( str[i] != 'r') { 
                endB = i;
                i++;  
            }
            if( i != 0){
                endB += N;
            }

            i = startR - 1;
            while( i > (endB-N)  && str[i] != 'b'){
                startR = i;
                i--;
            }
#ifdef DEBUG
            printf("blue inital until %d\n", endB);
            printf("red can start from %d\n", startR);
                printf("\n");
#endif

            startB2 = startB; 
            endB2 = N -1;
            lengthR1 = endR - (startR-1);
            lengthB1 = endB - (startB-1);
            lengthR = lengthR1;
            i = 0;
            while( str[i] != 'b' && i < startB2) { 
                endR2 = i;
                i++;
            }

            i = startB2 - 1;
            while( i > (endR2)  && str[i] != 'r'){
                startB2 = i;
                i --;
            }
#ifdef DEBUG
            printf("Red from start until %d\n", endR2);
            printf("Blue start from %d until end\n", startB2);
                printf("\n");
#endif

            lengthR2 = endR2+1;
            lengthB2 = endB2 - (startB2-1);
            length1 = lengthR1 + lengthB1;
            length2 = lengthR2 + lengthB2;
            printf("length1 : %d legnth2 %d\n", length1, length2);
            if( length1 > length2) {
                lengthR = lengthR1;
            } else {
                lengthR = lengthR2;
                endB = endB2;
                startB = startB2;
            }
        }
        lengthB = endB - (startB-1);
        length = lengthR + lengthB;
    }

    if( length > max){
        max = length;
#ifdef DEBUG
        printf("biggest length of size %d found: \n", max);
        printf("Blue starting from %d to %d\n", startB, endB);
        printf("Red starting from %d to %d\n", startR, endR);
                printf("\n");

        for( j = startB; j <= endB; j++){
            printf("%c", str[j]);
        }
        printf("|");
        for( j = startR; j <= endR; j++){
            printf("%c", str[j]);
        }
        printf("\n");
#endif
    }
    printf("%d\n",max);
    fprintf(outFile,"%d\n", max);


    fclose(inFile);
    fclose(outFile);

    return 0;
}
