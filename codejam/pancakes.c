
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 10

char flipTarget(char face);

int main() {


    int N, i;
    scanf("%d", &N);
    int result[N];
    char stack[101];
    char target, bottom;

    int size, index, counter;

    i = 1;
    while( i <= N){

        size = 0;
        scanf("%s", stack);
        size = strlen(stack);
        index  = size - 1;
        bottom = stack[index];

        index--; 
        target = flipTarget(bottom);
        counter = 0;
        while( index >= 0){

            if( stack[index] == target){
                counter++;
                target = flipTarget(target);
            }

            index--;
        }
        if( bottom == '-'){
            counter++;
        }
        result[i-1] = counter;
        i++;
    }

    i = 0;
    while( i < N) {
        printf("Case #%d: %d\n", i+1, result[i]);
        i++;
    }

    return EXIT_SUCCESS;
}

char flipTarget(char current) {

    char result;

    result = (current == '+') ? '-' : '+';

    return result;
}

