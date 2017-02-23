
/*
ID: wochnow1
PROG: milk 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _farmer{
    //Price and quantity per farmer
    int p;
    int q;
}farmer;

void sort(farmer a[], int N);
int binarySearch(farmer f, farmer ff[], int N);

int main() {

    FILE* inFile = fopen("milk.in","r");
    FILE* outFile = fopen("milk.out","w");

    int amount, N;
    fscanf(inFile,"%d %d",&amount, &N);
    int i, j;
    farmer arr[N];
    for( i = 0; i < N; i++) {
        fscanf(inFile,"%d", &arr[i].p);
        fscanf(inFile,"%d", &arr[i].q);
    }
    printf("Unsorted\n");
    for( i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].p, arr[i].q);
    }
    sort( arr, N);
    printf("Sorted\n");
    for( i = 0; i < N; i++) {
        printf("%d %d\n", arr[i].p, arr[i].q);
    }

    int tmp = amount;
    int cash = 0;
    for( i = 0; i < N; i++) {
        if( tmp >= arr[i].q) { 
            // Need to buy all of the units
            tmp = tmp - arr[i].q;
            cash += arr[i].q*arr[i].p;
            printf("Buying %d units at %d cents each\n", arr[i].q, arr[i].p);
        } else {
            //Only need to buy tmp amount of units
            cash += tmp*arr[i].p;
            printf("Buying %d units at %d cents each\n", tmp, arr[i].p);
            break;
        }
    }
    fprintf(outFile,"%d\n", cash);
    printf("%d\n", cash);
        
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void sort( farmer a[], int N) {
    int i, j;
    farmer f;
    int pos;
    for( i = 1; i < N; i++) {
        pos = binarySearch(a[i], a, i);
        
        f = a[i];
        for( j = i-1; j >= pos; j--) {
            a[j+1] = a[j];
        }
        a[pos] = f;
    }
}

int binarySearch(farmer a, farmer arr[], int N) {
    int lo = 0;
    int hi = N;
    int mid = (hi + lo)/2;
    while( lo < hi) {

        if( arr[mid].p <  a.p) {
            lo = mid + 1;
        } else { 
            hi = mid;
        }
        mid = (hi+lo)/2;
    }
    return mid;
}








