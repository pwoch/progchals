/*
ID: wochnow1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef char* string;
int findIndex(char* tmp, string arr[], int size); 

int main()
{
    FILE* inFile = fopen("gift1.in","r");
    FILE* outFile = fopen("gift1.out","w");

    int N;
    fscanf(inFile,"%d", &N);
    string arr[N];
    string tmp;
    int i, j;
    tmp = malloc(MAX_SIZE);
    for( i = 0; i < N; i++) {
        fscanf(inFile,"%s", tmp);
        arr[i] = malloc(strlen(tmp));
        strcpy(arr[i], tmp);
    }

    int new[N];
    int old[N];
    for( i = 0; i < N; i++){
        new[i] = 0;
        old[i] = 0;
    }

    int num, amount, loc;

    for( i = 0; i < N; i++){
        fscanf(inFile,"%s", tmp);
        //printf("Gifts by %s\n", tmp);
        loc = findIndex(tmp, arr, N);

        fscanf(inFile,"%d", &old[loc]);
        fscanf(inFile,"%d", &num);

        //printf("Has %d and is giving to %d people\n", old[loc], num);

        if( num != 0){
            new[loc] += (old[loc] % num);
            amount = (old[loc] / num);
        } else {
            new[loc] += old[loc];
            amount = 0;
        }

        for( j = 0; j < num; j++) {
            fscanf(inFile,"%s", tmp);
            loc = findIndex(tmp, arr, N);
            new[loc] += amount;
        }
    }

    for( i = 0; i < N; i++){
        //printf("%s\n", arr[i]);
        //printf("Old %d, new %d\n", old[i], new[i]);
        fprintf(outFile,"%s %d\n", arr[i], (new[i] - old[i]));
        free(arr[i]);
    }
    free(tmp);

    return 0;
}


int findIndex(char* tmp, string arr[], int N) {
    int found;
    int j;
    for( j = 0; j < N; j++) {
        found = (strcmp(tmp, arr[j]) == 0);
        if( found ){
            break;
        }
    }
    return j;
}

