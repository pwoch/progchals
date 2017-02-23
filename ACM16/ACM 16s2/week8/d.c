
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

long long gcd(long long a, long long b) { return a ? gcd(b%a,a) : b; }


int  main(){

    int tc, tcn;
    scanf("%d", &tcn);
    for( tc = 0; tc < tcn; tc++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long d = gcd(a,b);
        long long lcm = (a*b)/d;
        //lcm/a are the factors of B minus the factors of A
        //need to check if these factors occur in A, by checking if a is divisible by the remaining factors
        long long b_minus_a = lcm/a;

        if( a%b_minus_a == 0) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

long long gcd(long long a, long long b) {


    long long p, q;
    if( a > b) {
          p = a;
          q = b;
    } else {
          p = b;
          q = a;
    }
    long long tmp;
    while( q != 0) {
        tmp = q;
        q = p % q;
        p = tmp;
    }

    return p;

}
