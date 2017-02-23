
/*
ID: wochnow1
PROG: crypt1 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isValid(int num, int a[], int mn);


int main() {

    FILE* inFile = fopen("crypt1.in","r");
    FILE* outFile = fopen("crypt1.out","w");

    int N;
    fscanf(inFile,"%d", &N);
    int i, j, k, l, m, tmp;
    int duplicate;
    int size = 0;

    int *arr = malloc( N*sizeof(int));
    printf("%d\n", N);
    for( i = 0; i < N; i++) {
        fscanf(inFile,"%d", &tmp);
        //printf("%d ", tmp);

        duplicate = 0;
        for( j = 0; j < size; j++) {
            if( arr[j] == tmp){
                duplicate = 1;
                break;
            }
        }
        if( duplicate == 0 ) {
            arr[size] = tmp;
            printf("%d ", arr[size]);
            size++;
        }
    }
    printf("\nUnique numbers %d\n",size);

    int a, b, p1, p2, r;
    int counter = 0;

    for( i = 0; i < size; i++) {

        for( j = 0; j < size; j++) {

            for( k = 0; k < size; k++) {

                for( l = 0; l < size; l++) {

                    for( m = 0; m < size; m++) {

                        a = arr[i]*100 + arr[j]*10 + arr[k];
                        b = arr[l]*10 + arr[m];
                        p1 = arr[m]*a;
                        p2 = arr[l]*a;
                        r = p1 + p2*10;
                        if( r / 10000 == 0 && p1 / 1000 == 0 && p2/1000 == 0) {

                            if( isValid(p1, arr, size) && isValid(p2, arr, size) && isValid(r, arr, size)){
                                counter++;
                               /* 
                                printf("%6d\n",a);
                                printf("%6d\n", b);
                                printf("%5d\n%6d\n", p1, p2);
                                printf("%6d\n", p1 + p2*10);
                                printf("-----\n");
                                */   
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Number of solutions %d\n", counter);
    fprintf(outFile,"%d\n", counter);

    fclose(inFile);
    fclose(outFile);
    free(arr);

    return 0;
}


int isValid(int n, int a[], int N) {

    int i, cond, tmp;

    while( n != 0) {

        cond = 0;
        tmp = n%10;
        for( i = 0; i < N; i++) {
            if( a[i] == tmp) {
                cond = 1;
            }
        }
        if( !cond) {
            break;
        }
        n = n/10;
    }
    return cond;
}

