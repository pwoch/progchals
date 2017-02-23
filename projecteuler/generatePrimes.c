#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM 500500 
#define TRUE 1
#define FALSE 0

int* generatePrimes();

int main() {

    int* primes = generatePrimes();

   
    return EXIT_SUCCESS;
}

int* generatePrimes() {

    int* result = malloc(NUM*sizeof(int));
    result[0] = 2;
    long long product = 2;
    int i = 1;
    int j = 0;
    long long try = 3;
    int prime;
    while( try < 1000000000){
        prime = TRUE;
        j = 0;
        while( j < i){
            if( (try % result[j]) == 0){
                prime = FALSE;
                break;
            }
            j++;
        }
        if( prime){
            product = (product*try)%500500507;
            result[i] = try;
            i++;
            if( prime >= NUM){
                break;
            }

        }
        try++;
    }

    printf("%d: %d\t%d\n", i, result[i-1],product);

    return result;
}
