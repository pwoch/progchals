
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define SIZE 350
#define FALSE 0
void printExpansion(int num[], int b, int c);


int main() {

    int num[SIZE] = {0};
    int start, i, pow;
    num[0] = 1;
    
    pow = 1;
    
   

    start = 0;
    while(  pow < 9) {
    

        i = start;
        while( i >= 0) {

            if( num[i] < 5 ){
                num[i] = num[i]*2;

            } else if(start < 350) {
                num[i+1] = num[i+1] + 1;
                num[i] = (num[i]*2) % 10;

                if( i == start) {
                    start++;
                }
            } else {
                printf("Array size exceeded\n");
                assert( FALSE ); 
            }
            i--;
        }

        printExpansion( num, pow, start);

        pow++;
    }

    return EXIT_SUCCESS;
}

void printExpansion(int num[], int pow, int start) {

    printf("The decimal expansion for 2 to the %d is\n", pow);
    printf("[");
    int i, sum;
    sum = 0;
    i = start;
    while( i >= 0) {

        printf(" %d", num[i]);
        sum = sum + num[i];
        i--;
    }
    printf("]\n");
    printf("The sum of the digits is: %d\n", sum);
    printf("Array size: %d\n\n", start);

} 

