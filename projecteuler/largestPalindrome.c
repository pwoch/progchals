

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define SIZE 1000000



int primes[SIZE] = {0};
int composites[SIZE] = {0};
int palindromes[SIZE/10] = {0};

int generatePrimeAndComposites();
void generateCompositePalindromes();
int  printPrimeFactorisation();
int isPalindromic(int num);


int main() {
    int compositeNumber;
    compositeNumber = generatePrimesAndComposites();
    printf("There are %d composites and %d primes below%d\n", compositeNumber + 1,
        SIZE - compositeNumber +1,SIZE);
    generateCompositePalindromes(compositeNumber);


    return EXIT_SUCCESS;
}

void generateCompositePalindromes(int index){

    int i, check, cond;

    i = 0;
    index--;
    check = 100000;
    while(check > 1000) {
        check = composites[index];

        if( isPalindromic(check)){
            cond = printPrimeFactorisation(check);
            if( !cond ){
                //printf("Palindrome is %d\n\n",check);
                composites[i] = check;
                i++;
            }
        }
        index--;
    }
}
int printPrimeFactorisation(int check){
    int prime, result, exceed;
    int primeFactors[20];
    result = 1;
    int num = check;

    int i = 0;
    int index = 0;
    while(result != check){
        exceed = 0;
        prime = primes[i];

        if( !(num%prime)){ 

            if( prime > 1000){
                exceed = 1;
            }

            primeFactors[index] = prime;
            index++;
            num = num/prime;
            result = result*prime;

        }else{
            i++;
        }
    }
    if( !exceed){
        i = 0;
        printf("Composite found with factors: ");
        while( i < index){
            printf("%d ", primeFactors[i]);
            i++;
        }
        printf("\n\n");
    }
    return exceed;
}
int isPalindromic(int num){

    int first, last, second, secondLast, third, thirdLast, check;
    check = 0;

    if(num < 10000){ 
        check = 0;
        last = num%10;
        first = num/10000;
        secondLast = (num%100)/10;
        second = (num/1000)%10;
        if( (first == last) && (second == secondLast)){
            check = 1;
        }


    } else if (num < 1000000){

        check = 0;
        first = num/100000;
        second = (num%100000)/10000;
        third = (num%10000)/1000;
        thirdLast = (num%1000)/100;
        secondLast = (num%100)/10;
        last = num%10;
        /*      printf("First number is %d\n",first);
                printf("Second number is %d\n",second);
                printf("Third number is %d\n",third);
                printf("Fourth number is %d\n",thirdLast);
                printf("Fifth number is %d\n",secondLast);
                printf("Sixth number is %d\n",last);
         */
        if( (first == last) && (second == secondLast) && (third = thirdLast)){
            check = 1;
            printf("%d is palindromic\n",num);
        }

    }
    return check;
}


int generatePrimesAndComposites(){

    int prime, counter, index, entry, trialNum, entryC, max; 

    max = SIZE;
    primes[0] = 2;
    trialNum = 3;
    entry = 1;
    entryC = 0;
    while( trialNum < SIZE) {

        index = 0;
        prime = TRUE;

        while(index < (int) sqrt(trialNum)) {

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
        } else {
            composites[entryC] = trialNum;
            entryC++;
        }
        trialNum++;
    }

    return entryC;
}
