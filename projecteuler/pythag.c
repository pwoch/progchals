#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TARGET 1000
#define TRUE 1
#define FALSE 0
#define LIM 500

int main() {

    int a,b,c;
    int triplet, sum, result;
    while( a < LIM) {

        b = 1;
        while( b < LIM) {
            result = pow(a,2) + pow(b,2);
            triplet = FALSE;
            c = sqrt(result);

            if( pow(c,2) == result){
                triplet = TRUE;
            }
            if(triplet){
                sum = a + b + c;
                printf("%d + %d + %d = %d\n", a, b, c, sum);
                if( sum == TARGET) {
                    return EXIT_SUCCESS;

                }
            }
            b++;
        }
        a++;
    }
    return EXIT_SUCCESS;
}
