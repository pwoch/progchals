
/*
ID: wochnow1
PROG: dualpal 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned long long power(int b,int e);
int isPal( unsigned long long n);
unsigned long long convertB(int n, int b);

int main() {

    FILE* inFile = fopen("dualpal.in","r");
    FILE* outFile = fopen("dualpal.out","w");

    int N, s;
    fscanf(inFile,"%d %d", &N, &s);
    //scanf("%d %d", &N, &s);

    int i, j;
    int count = 0;
    unsigned long long try;
    int pal;

    for( i = s+1; count < N; i++) {
        pal = 0;
        printf("%d is ", i);
        for( j = 2; j <= 10; j++) {
            try = convertB(i, j);
            if( !pal) {
                if( isPal(try)) {
                    printf("palindromic in:\n");
                    printf("Base %d: %llu\n",j, try);
                    pal = 1;
                }
            } else { 
                if( isPal(try)) {
                    printf("Base %d: %llu\n",j, try);
                    fprintf(outFile,"%d\n", i);
                    count++;
                    break;
                }
            }
        }
        if( !pal) {
            printf("not palindromic in any base\n");
        }
        printf("\n");
    }


    fclose(inFile);
    fclose(outFile);

    return 0;
}

int isPal( unsigned long long n) {
    int length = 0;
    unsigned long long tmp = n;
    while( tmp != 0) {
        tmp = tmp/10;
        length++;
    }
    int nums[length];
    int otherNums[length];
    int i;
    tmp = n;
    for( i = 0; tmp!= 0; tmp = tmp/10) {
        nums[i] = tmp%10;
        otherNums[length-1-i] = tmp%10;
        i++;
    }
    for( i = 0; i < length; i++) {
        if( nums[i] != otherNums[i]){
            return 0;
        }
    }
    return 1;
}

unsigned long long convertB(int n, int b) {
    unsigned long long result = 0;
    int i;
    for( i = 0; n != 0; n = n/b){
        result += n%b * power(10,i);
        i++;
    }
	printf("%d in base %d is%d\n", result, b);
    return result;
}

unsigned long long power(int b,int e) {
    int i = 0;
    unsigned long long result = 1;
    while( i < e) {
        result = result*b;
        i++;
    }
    return result;
}

