
/*
ID: wochnow1
PROG: barn1 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sort(int a[], int b);
int findPos(int a, int arr[], int n);

int main() {

    FILE* inFile = fopen("barn1.in","r");
    FILE* outFile = fopen("barn1.out","w");

    int M, S, C;

    fscanf(inFile,"%d %d %d", &M, &S, &C);
    if( M < C) {

        int num1[C];
        int diff[C-1];
        int i, j;
        int s1, s2;
        for( i = 0; i < C; i++) {
            fscanf(inFile,"%d", &num1[i]);
        }
        sort( num1, C);
        for( i = 1; i < C; i++) {
            diff[i-1] = num1[i] - num1[i-1];
        }
        sort( diff, C-1);
        printf("Differences\n");
        for( i = 0; i < C-1; i++) {
            printf("%d\n", diff[i]);
        }

        int result = M;
        for( i = 0; i < C - M; i++) {
            result += diff[i];
        }
        printf("Min stalls covered %d\n", result);
        fprintf( outFile,"%d\n", result);

    } else { 
        fprintf(outFile,"%d\n", C);
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}


void sort( int a[], int N) {

    int i, j;
    int pos, tmp;
    for( i = 1; i < N; i++) {
        pos = findPos(a[i], a, i);

        tmp = a[i];
        for( j = i-1; j >= pos; j--) {
            a[j+1] = a[j];
        }
        a[pos] = tmp;
    }
}

int findPos( int a, int arr[], int N) {
    int lo = 0;
    int hi = N;
    int mid = (hi + lo)/2;
    while( hi > lo) {
        if ( a > arr[mid]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
        mid = (hi + lo)/2;
    }
    return mid;
}

