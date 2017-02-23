
/*
ID: wochnow1
PROG: skidesign 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sort(int a[], int N);
int binarySearch(int a, int ar[], int arr);

int main() {

    FILE* inFile = fopen("skidesign.in","r");
    FILE* outFile = fopen("skidesign.out","w");

    int N;
    fscanf(inFile,"%d", &N);

    int i;
    int a[N];
    for( i = 0; i < N; i++) {
        fscanf(inFile,"%d", &a[i]);
        //printf("%d ", a[i]);
    }
    //printf("\n");
    fclose(inFile);

    sort(a, N);
    /*for( i = 0; i < N; i++) {
      printf("%d ", a[i]);
      }
      printf("\n");
      */

    int diff, min, max, j, m, k;
    long long cost = 0;
    int minN, maxN;
    long long ans = 0;
    int remainder = 0;

    int notFound = 1;
    int n[N];
    for( i = 17; i < 100; i++) {
        min = i -17;
        max = i;
        for( j = 0; j < N; j++){

            if( a[j] < min) {
                n[j] = min;
            } else if( min <= a[j] && a[j] <= max) {
                n[j] = a[j];
            } else {
                n[j] = max;
            }
        }

        cost = 0;
        for( m = 0; m < N; m++) {
            cost += (n[m] -a[m])*(n[m]-a[m]);
        }
        printf("Total cost for %d-%d is: %lld\n",min, max, cost);

        if( cost < ans || notFound) {
            /*for( m = 0; m < N; m++) {
                printf("%d -> %d: %d\n", a[m], n[m], (n[m] -a[m])*(n[m]-a[m]));
            }
            */
            notFound = 0;
            ans = cost;
        }

    }

    printf("Total cost %lld\n", ans);

    fprintf(outFile,"%lld\n", ans);
    fclose(outFile);

    return 0;
}


void sort(int a[], int N) {
    int i, j;

    int tmp, pos;

    for( i = 1; i < N; i++) { 
        pos = binarySearch(a[i],a, i);

        tmp = a[i];
        for( j = i; j > pos; j--) {
            a[j] = a[j-1];
        }
        a[pos] = tmp;
    }
}

int binarySearch(int n, int a[], int N) {
    int hi = N;
    int lo = 0;
    int mid = lo + (hi-lo)/2;
    while( hi > lo) {
        if( a[mid] < n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
        mid = lo + (hi-lo)/2;

    }
    return mid;
}


