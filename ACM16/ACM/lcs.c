



#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main() {


    long long n1, f1, d1, n2, f2, d2;

    scanf("%lld%lld%lld%lld%lld%lld", &n1, &f1, &d1, &n2,&f2, &d2);

    int startN, endN;
    long long max1, max2;
    max1 = f1 + (n1-1)*d1;
    max2 = f2 + (n2-1)*d2;

    if( f1 < f2){
        startN = (f2-f1)/d1;
        n1 = n1 - endN;
        f1 = f1 + startN*d1;
    } else {
        startN = (f1 - f2)/d2; 
        n2 = n2 - endN;
        f2 = f1 + startN*d1;
    }
    long long shared;
    int notFound = TRUE;
    
    int n;
   
    for( n = 0; notFound; n++) {
        if( ((d1*n) + f1 -f2)%d2 == 0){
            notFound = FALSE;
            shared = f1 + d1*n;
        }
    }
    
    int smallMax = (max1 < max2) ? max1 : max2;

    int result = (smallMax - shared)/(d1*d2);
    result++;
    printf("result: %d\n", result);

    return 0;
}

    


