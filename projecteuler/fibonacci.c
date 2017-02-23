

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int fib);

int main(){
    int fib, sum;
    int tmp = 0;
    printf("Enter which term\n");
    scanf("%d", &tmp);

    fib = fibonacci(tmp);
    printf("The %d-th term of the sequence is %d\n", tmp , fib);

    sum = fibonacci(tmp + 2);
    printf("Sum of numbers to this term is %d\n", sum);

    return EXIT_SUCCESS;
}

int fibonacci(int n){

    if( n <= 2){
        return 1;
    } else {

        return fibonacci(n-1)+fibonacci(n-2);
    }
}
