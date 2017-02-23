

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100000

int p[MAX] = {0};

typedef struct prime{
    int pow, prime;
}pr;

int main() {

    int i, j;
    p[0] = 1;
    p[1] = 1;
    for( i = 2; i < MAX; i++) {
        for( j = 2*i; j < MAX; j+=i) p[j] = 1;
    }

    int num;
    pr div[100];

    int t, tc = 0;
    //scanf("%d", &tc);

    //for( t = 0; t < tc; t++) {
        int k = 0;
        scanf("%d", &num);
        for( i = 0; i < 10; i++) {
            div[i].pow = 0;
            div[i].prime = 0;
        }

        i = 2;
        while( i < MAX && num != 0) {

            if( p[i]) {
                i++;
                continue;
            }
            if( num%i == 0) {
                if( k != 0 && div[k-1].prime == i) {
                    div[k-1].pow++;
                }else {
                    div[k].prime = i;
                    div[k].pow++;
                    k++;
                }
                num = num/i;
            } else {
                i++;
            }
        }
        if( num != 1) {
            div[k].prime = num;
            div[k].pow = 1;
            k++;
        } 
        int divs = 1;
        for( i = 0; i < k; i++) {
            divs *= div[i].pow+1;
        }
        printf("Divs: %d\n", divs);
      

    //}
    



    for( i = 0; i < k; i++) printf("%d^%d\n", div[i].prime, div[i].pow);
    printf("Kiwi: %d\n", isPrime(divs));

    return 0;
}

int isPrime(int n) {
    int i;
    for( i = 2; i < MAX; i++) {
        if( p[i] || i == n) continue;
        if( n%i == 0) {
            printf("%d divides %d\n", i, n);
            return 0;
        }
    }
    return 1;
}
