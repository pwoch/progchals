

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int arr[SIZE] = {0};

int recurse(int b);

int main() {
    arr[1] = 1;
    int i;
    for( i = 2; i < SIZE; i++) {
        printf("%d\n", i);
        recurse(i);
    }   
    int max = 1;
    for( i = 0; i < SIZE; i++) {

        if( arr[i] > max) {
            printf("New Max %d %d\n", i, arr[i]);
            max = arr[i];
        }
    }


    return 0;
}

int recurse(  int num) {
    //printf("Calling with %d\n", num);

    if( num == 1) {
      //  printf("Returning 1 cause num = 1\n");
        return 1;
    } else if (num < SIZE && arr[num] != 0) {
        //printf("Returning %d because we know size of %d\n",arr[num], num);
        return 1 + arr[num];
    } else {
        int new = (num%2 == 0) ? num/2 : 3*num +1;

        recurse( new);

        if( num < SIZE && new < SIZE) {
            arr[num] = arr[new] + 1;
        }
    }
}

