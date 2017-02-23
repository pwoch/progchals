#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int checkDigits(int a);
int checkArray();
void resetArray();

int record[MAX] = {0};

int main() {

    int N;
    int num, new, seenAllDigits;
    int i, j;

    scanf("%d", &N);
    int tests[N];


    i = 0;
    while(i < N){
        scanf("%d", &tests[i]);
        i++;
    }

    i = 1; 
    while( i <= N) {
        num = tests[i-1];
        resetArray();
        printf("New number %d\n", num);

        if( num == 0) {
            printf("Case #%d: ", i);
            printf("INSOMNIA\n");

        } else {
            j = 0;
            seenAllDigits = 0;
            new = num;

            while( !seenAllDigits ) {
                seenAllDigits = checkDigits(new);
                new = num * j;
                printf("Checking: %d\n", new);
                j++;
            }

            printf("Case #%d: ", i);
            printf("%d\n", new - num);

        }
        i++;
    }

    return EXIT_SUCCESS;
}

int checkDigits(int num) {
    int sv = num;
    int index, check;
    check = 0;
    while( num != 0) {
        index = num%10;
        record[index]++;
        num = num/10;

    }
    check = checkArray();
    
    return check; 
}

void resetArray(){

    int k = 0;
    while( k < MAX){
        record[k] = 0;
        k++;
    }

}

int checkArray(){

    int i;
    int filled;

    filled = 1;
    i = 0;
    while( i < MAX){
        if( record[i] == 0){
            filled = 0;
            break;
        }
        i++;
    }
    return filled;
}

