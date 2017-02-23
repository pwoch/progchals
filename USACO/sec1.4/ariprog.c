/*
ID: wochnow1
PROG: ariprog 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct _bisquare{
    int c;
}Bi;

int main() {

    FILE* inFile = fopen("ariprog.in","r");
    FILE* outFile = fopen("ariprog.out","w");

    int a, b, n, N,M, i, j, max;
    fscanf(inFile, "%d %d", &N, &M);
    max = 2*(M+1)*(M+1);

    Bi *possible = malloc(sizeof(Bi)*max); 
    for( i = 0; i < max; i++) {
        possible[i].c = 0;
        //possible[i].q = 0;
        //possible[i].p = 0;
    }
    for ( i = 0; i <= M; i++) {
        for( j = i; j <= M; j++) {
            //possible[i*i + j*j].p = i;
            //possible[i*i + j*j].q = j;
            possible[i*i + j*j].c = 1;
        }
    }
    /*
       for( i = 0; i < max; i++) {        
       if( possible[i].c == 1)  
       printf("%d = (%d + %d)\n", i, possible[i].p*possible[i].p, possible[i].q*possible[i].q);
       }
       */

    int printed = 0;
    b = 1; 
    while( b <= (max)/(N-1)) {
        //printf("Increment by %d\n", b);
        a = 0;
        while( a < max) {
            if( possible[a].c == 1) {
                //printf("Start with %d\n", a);
                n = 1; 
                int check = 1;
                while (n < N) {
                    //printf("Checking %d + %d*%d = %d\n",a,n,b, a+n*b);
                    if( (a+n*b) >= max) {
                        //printf("Failed\n");
                        check = 0;
                        break;
                    } else if (possible[a + n*b].c == 0) {
                        //
                        //printf("Failed\n");
                        check = 0; 
                        break; 
                    }
                    n++; 
                }
                if (check == 1) {
                    printf("Success for %d %d \n", a, b);
                    for( i = 0; i < N; i++) {
                        printf("%d check: %d", a+n*b, possible[a+n*b].c);
                    }
                    fprintf(outFile,"%d %d\n", a, b); 
                    printed = 1;
                }
            }
            a++; 
        }
        b++;
    }
    if( printed == 0) {
        fprintf(outFile,"NONE\n");
    }


    free(possible);
    fclose(inFile);
    fclose(outFile);
    return 0;
}
