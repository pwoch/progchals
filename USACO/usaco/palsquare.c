
/*
ID: wochnow1
PROG: palsquare 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned long long convertToBase(int base, int num);
unsigned long long power( unsigned long long a, int b);
int isPalindrome(unsigned long long num);
char* convertToBigBase(int b, int n);
int isPalindromeForBig(char* num);

int main() {

    FILE* inFile = fopen("palsquare.in","r");
    FILE* outFile = fopen("palsquare.out","w");

    int b;
    unsigned long long n;
    //fscanf(inFile,"%d", &b);
    scanf("%d", &b);
    printf("Base %d\n", b);

    unsigned long long square;
    int i;
    char* s;
    char* bigS;
    for( i = 1; i < 300; i++) {
        if( b <= 10) {
            n = convertToBase(b, i);
            square = convertToBase(b, i*i);
            if( isPalindrome(n) ){
                fprintf(outFile,"%llu %llu\n", n, square);
                printf("%d: %llu %llu\n",i, n, square);
            }
        } else {
            s = convertToBigBase(b, i);
            bigS = convertToBigBase(b, i*i);
            if( isPalindromeForBig(bigS)) {
                fprintf(outFile,"%s %s\n", s, bigS);
                printf("%d: %s %s\n",i, s, bigS);
            }
            
        }
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}


char* convertToBigBase(int b, int n) {

    char* result1 = malloc(6);
    char result[6];


    int i, j;
    for( i = 0; i < 6; i++) {
        result[i] = '\0';
    }
    int remainder;
    for( i = 0; n != 0; i++) { 
        remainder = n%b;
        //printf("%d has remainder %d in base %d: ", n, remainder, b);
        if( remainder >= 10) {
            remainder = remainder%10;
            result[i] = 'A' + remainder;
            //printf("%c\n", result[i]);
        } else {
            result[i] = remainder + '0';
            //printf("%c\n", result[i]);
        }
        n = (n)/b;
    }
    result[i] = '\0';
    //printf("%s\n", result);
    for( j = 0; j < i; j++) {
        result1[j] = result[i-1-j];
    }

    return result1;
}





int isPalindromeForBig(char* num) {
    int size = strlen(num);
    int i;
    for( i = 0; i < size; i++) {
        if( num[i] != num[size-1-i]){
            return 0;
        }
    }


    return 1;
}


int isPalindrome(unsigned long long num) { 
    int i,ln = 0;
    unsigned long long tmp = num;
    while( tmp != 0) {
        tmp = tmp/10;
        ln++;
    }
    unsigned long long check[ln];
    tmp = num;
    for( i = 0; i < ln; i++) {
        check[i] = tmp%10;
        tmp = tmp/10;
    }
    tmp = num;
    unsigned long long tp;
    for( i = ln-1; i >= 0; i--){
        tp = tmp/power(10,i);
        if( check[(ln-1)-i] != tmp/(power(10,i))){
            return 0;
        }
        tmp = tmp%power(10,i);
    }
    return 1;
}
unsigned long long power(unsigned long long a, int b){
    unsigned long long result = 1;
    int i;
    for( i = 0; i < b; i++) {
        result = result*a;
    }
    return result;
}

unsigned long long convertToBase(int base, int num) {
    unsigned long long result = 0;
    int b = base;
    int n = num;

    int i = 0;
    while( n != 0) {
        result += n%b *power(10,i);
        n = n/b;
        i++;
    }

    return result;
}
