
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define MAX 600851475143

int main(int argc,char* argv[]) {
    int max = (int) sqrt(MAX); 
    int prime = TRUE;
    int primeArr[max] = {0};
    int index = 0;
    int i, j;
    primeArr[index] = 2;
    index++;

    for(i = 3; i <= MAX; i+=2){
        prime = TRUE;
        int checkIfPrime = i;

        for(j = 0; j < MAX; j++) {

            if( primeArr[j] == 0){
                break;
            }
             
            if( !(checkIfPrime % primeArr[j]) ){
                    prime = FALSE;
                    break;
            }

        }
        if(prime){
            primeArr[index] = i;
            printf("New prime found: %d\n", primeArr[index]);
            index++;
        }
    }

             
    printf("Number of primes less than %d is %d\n", MAX, index);

    return EXIT_SUCCESS;
}

