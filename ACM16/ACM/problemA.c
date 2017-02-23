
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long geometricSum(long long n);
//int power(int base, int exp);


int main(int argc,char* argv[]) {

        long long num, result;

        scanf("%lld",&num);

        result = geometricSum(num);
        
        printf("%lld\n", result);

   	return EXIT_SUCCESS;
}

long long geometricSum(long long lim) {

    long long result = 0;
    long long term = 1;
    int i;
    for( i = 1; i <= lim; i++) {

        term = term*2;
        result = result + term;
    }
    
    return result;
}
/*
int power (int base, int exp);
    
    if(exp == 0) {
        
        return 1;

    } else {

        return base*power(base,exp-1);
    }
} */
