
/*
ID: wochnow1
PROG: milk2 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _farmer{
    int begin;
    int end;
}farmer;

farmer *binaryInsertionSort(farmer arr[], int N);
int findIndex(farmer f, farmer arr[], int size);

int main() {

    FILE* inFile = fopen("milk2.in","r");
    FILE* outFile = fopen("milk2.out","w");

    int N;
    fscanf(inFile,"%d", &N);
    int i, k;
    farmer f;
    fscanf(inFile,"%d %d", &f.begin, &f.end);
    farmer arr[N];
    for( i = 0; i < N; i++) {
        arr[i].begin = 0;
        arr[i].end = 0;
    }
    arr[0] = f;
    int size = 1;
    int absorbed = 0;

    for( i = 1; i < N; i++) {
        fscanf(inFile,"%d %d", &f.begin, &f.end);
        
        absorbed = 0;
        for( k = 0; k < size; k++) {
            if(     f.begin <= arr[k].begin && arr[k].begin <= f.end ||
                    f.begin <= arr[k].end && arr[k].end <= f.end ||
                     arr[k].begin <= f.begin && f.end <= arr[k].end)  {

                if( f.begin < arr[k].begin) {
                    arr[k].begin = f.begin;
                } 
                if( f.end > arr[k].end) {
                    arr[k].end = f.end;
                }
                    
               // arr[k].begin = (f.begin < arr[k].begin) ? f.begin : arr[k].begin;
               // arr[k].end = (f.end > arr[k].end) ? f.end : arr[k].end;
                //printf("A cow is milked between %d, %d\n", arr[k].begin, arr[k].end);
                absorbed = 1;
            }
        }
        if( !absorbed) {
            arr[size].begin = f.begin;
            arr[size].end = f.end;
            size++;
        }
    }
    printf("Length: %d\n", size);


    //printf("Sorting by earliest beginning\n");
    farmer *sort = binaryInsertionSort(arr, size);
    
    for( i = 1; i < size; i++) {
        f = sort[i-1];
        
        if(     f.begin <= sort[i].begin && sort[i].begin <= f.end ||
                    f.begin <= sort[i].end && sort[i].end <= f.end ||
                     sort[i].begin <= f.begin && f.end <= sort[i].end)  {

                if( f.begin < sort[i].begin) {
                    sort[i].begin = f.begin;
                } 
                if( f.end > sort[i].end) {
                    sort[i].end = f.end;
                }

        }
    }
    for( i = 0; i < size; i++){
        printf("%d: %d %d\n", i, sort[i].begin, sort[i].end);
    }

        

    int interval, indx, max = 0;
    int noMilk = 0;
    for( i = 0; i < size; i++) {
        interval = sort[i].end - sort[i].begin;
        if( interval > max) {
            printf("New max %d, begin: %d end: %d\n",interval, sort[i].begin, sort[i].end);
            max = interval;
            indx = i;
        }
        //printf("%d %d %d\n", arr[i].begin, arr[i].end, interval);
        if( i != 0) {
            interval = sort[i].begin - sort[i -1].end;
            if( interval > noMilk){
                printf("New no milking %d, begin: %d end: %d\n",interval, sort[i].begin, sort[i-1].end);

                noMilk = interval;
            }
        }
    }
    printf("%d %d\n", max, noMilk);

    fprintf(outFile,"%d ", max);
    fprintf(outFile,"%d\n", noMilk);

    fclose(inFile);
    fclose(outFile);

    return 0;
}

farmer *binaryInsertionSort(farmer arr[], int N) 
{
    farmer *a = malloc(sizeof(farmer)*N);
    int i, j;
    for( i = 0; i < N; i++) {
        a[i].begin = 0;
        a[i].end = 0;
    }
    int pos;
    farmer tmp;
    for( i = 0; i < N; i++) {

        pos = findIndex(arr[i], a, i);
        tmp = arr[i];
        for( j = i; j > pos; j--) {
            a[j] = a[j-1];
        }
        a[j] = tmp;

    }

    return a;
}

int findIndex(farmer f, farmer arr[], int size)
{
    int hi = size;
    int lo = 0;
    int mid = (hi+lo)/2;
    while( lo < hi) {

        if( f.begin > arr[mid].begin) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
        mid = (hi+lo)/2;
    }

    return mid;
}



