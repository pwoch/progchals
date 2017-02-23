
/*
ID: wochnow1
PROG: namenum
LANG: C
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 12

int binarySearch(char* c, int size); 

void opt(char s[],char* og, int i, int N);
char decode(int key);

char str[5000][20];
FILE* outFile;
int found;

int main() {
    FILE* inFile = fopen("namenum.in","r");
    FILE* dict = fopen("dict.txt","r");
    outFile = fopen("namenum.out","w");

    found = 0;
    int i, j;
    int size = 0;
    for( i = 0; i < 5000; i++) {
        fscanf(dict,"%s", str[i]);
        if( str[i][0] == '\0')
            break;
        else 
            size++;
    }

    char s[MAX_LENGTH];
    fscanf(inFile,"%s", s);
    char* og = malloc(strlen(s));
    strcpy(og, s);
    opt(s,og, 0, size);
    if( found == 0) {
        fprintf(outFile,"NONE\n");
        printf("NONE\n");
    }


    return 0;
}

void opt(char r[],char* og, int i,int N) {
   

    if( og[i] != '\0') {

        int key = (int) og[i]-'0';
        //printf("key = %d\n", key);
        int j;
        char replace = decode(key);
        for( j = 0; j < 3; j++) {
            if( replace + j == 'Q') {
                replace++;
            }
            r[i] = replace + j;
            printf("Trying %s\n", r);
            opt(r,og, i+1, N);
        }
    } else {
        if( binarySearch(r, N) != -1) {
            found = 1;
            printf("%s\n", r);
            fprintf(outFile,"%s\n", r);
        }
    }

}

char decode(int key) {

    if( key == 2) {
        return 'A';
    } else if( key == 3) {
        return 'D';
    } else if ( key == 4) {
        return 'G';
    } else if( key== 5) {
        return 'J';
    } else  if( key == 6) {
        return 'M';
    } else if( key == 7) {
        return 'P';
    } else  if( key == 8) {
        return 'T';
    } else if( key == 9) {
        return 'W';
    } else {
        return -1;
    }
}


int binarySearch(char* c,int size) {
    int hi = size;
    int lo = 0;
    int mid = (hi+lo)/2;
    char* tmp;
    int val;
    while( hi >= lo) {
        tmp = str[mid];
        //printf("Comparing %s with %s at index %d\n", c, tmp,mid);
        val = strcmp(c, tmp);
        if( val > 0 ) {
            lo = mid + 1;        
        } else if ( val < 0) {
            hi = mid - 1;
        } else {
            //Exit since tmp == c
            return mid;
        }
        mid = (hi + lo)/2;
    }
    return -1;
}


