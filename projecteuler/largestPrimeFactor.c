

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UPPER_BOUND 775146
#define NUMBER 600851475143
#define TRUE 1
#define FALSE 0

int * generatePrimeNumbers(int a);


int main() {


    int prime, counter, index, entry, trialNum; 

    int primes[UPPER_BOUND] = {0};

    primes[0] = 2;
    trialNum = 3;
    entry = 1;

    while( trialNum < UPPER_BOUND) {

        index = 0;
        prime = TRUE;

        while(index < trialNum) {

            if( primes[index] == 0){
                break;
            } else if( !(trialNum % primes[index])){
                prime = FALSE;
                break;
            }
            index++;
        }

        if( prime) {
            primes[entry] = trialNum;
            entry++;
        }
        trialNum+=2;
    }

    printf("There are %d primes less than %d\n", entry, UPPER_BOUND);

    int i;
    long long product, check, max;
    long long number = NUMBER;
    max = 0;
    i = 0;
    check = 0;
    product = 1;
    while( product != number) {
        check = primes[i];

        if( !(number % check)){
            printf("%lld is a  prime factor of %lld\n", check, number);
            max = check;
            product = product * check;
        }
        i++;
    }



    /*    counter = 0;
          while(counter <= entry) {
          printf("%d\n", primes[counter]);
          counter++;
          }
     */



    return EXIT_SUCCESS;
}

