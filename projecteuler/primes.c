


#include <stdio.h>
#include <stdlib.h>

#define SIZE 2000000

int main() {


    int i, j;
    int num[SIZE] = {0};
    num[0] = 1;
    num[1] = 1;
    for( i = 2; i < SIZE; i++) {

        for( j = 2*i; j < SIZE; j= j+i) {
            num[j] = 1;
        }
    }
    unsigned long long sum = 0;
    for( i = 0; i < SIZE; i++) {
        if( num[i] == 0) {
            sum += i;
            printf("%d\n", i);
        }
    }
    printf("Sum: %llu\n", sum);

    return 0;
}

