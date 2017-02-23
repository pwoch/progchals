//Lucy Qiu
//Paul Wochnowski
//28/03/216
//ACM Week 4 Problem D- Vasya and Petya's Game
//Guessing numbers

#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
#define TRUE 1
#define FALSE 0

int getHighestPowerLessMax(int primeNum, int Max);
int power(int a, int b);
void generatePrimeArray(int high);

int primeArr[MAX] = {0};


int main(int argc, char* argv[]) {
	int lim = 0;
	scanf("%d", &lim);
	
        generatePrimeArray(lim);
	int answer[MAX] = {0};
        int primeNum, high, exponent, i, index;

        i = 0;
	index = 0;
        
        while(primeArr[i] <= lim && primeArr[i]!= 0) {

            primeNum = primeArr[i];
            high = getHighestPowerLessMax(primeNum, lim);
            exponent = 1;

            while (exponent <= high) {
                answer[index] = power(primeNum, exponent);
                index ++;
                exponent ++;

            }
            i ++;
        }

        printf("%d \n", index);

        i = 0;
        while( i < lim) {
            if (answer[i] != 0) {
                printf("%d ", answer[i]);
            } else {
                break;
            }
            i++;
        }
        printf("\n");

        return EXIT_SUCCESS;
}

int power(int num, int exponent) {
    int i, result;
    
    i = 0;
    result = 1;
    while( i < exponent) {
        result = result*num;
        i++;

    }
    return result;
}

int getHighestPowerLessMax(int number, int limit) {

    int highestPower, result;
    highestPower = 0;
    result = number;
    while( result < limit){
        result = result*number;

        highestPower ++;
    }

    return highestPower;
}

void generatePrimeArray(int high) {
    int isPrime = TRUE;
    int index, j;

    index = 0;
    primeArr[index] = 2;
    index ++;

    int number;
    for(number = 3; number <= high; number+=2) {
        isPrime = TRUE;

        for(j = 0; j < high; j++) {

            if(primeArr[j] == 0) {
                break;
            }
            if ( !(number % primeArr[j]) ) {
                isPrime = FALSE;
                break;
            }
        } 

        if(isPrime) {
            primeArr[index] = number;
            index ++;
        }
    }
}

