#include <stdio.h>
#include <stdlib.h>

#define MOD 100000007
    
long long powers[1001];
long long term[1001];

void initPowers() {
    int i;
    powers[0] = 1;
    for( i = 1; i < 510; i++) {
        powers[i] = (powers[i-1]*26)%MOD;
    }
}

void initTerms() {
    int i;
    term[0] = 0;
    for( i = 1; i < 101; i++) {
        if( i%2 == 0) {
            term[i] = (2*((powers[i/2+1]-1)/25 -1))%MOD;
        } else {
            term[i] = (term[i-1] + powers[(i/2)+1])%MOD;
        }
        printf("N=%d: %lld %d\n",i,i/2+1, term[i]%MOD,100000007);
    }
}

int main() {
    int tc, T;
    int n;
    initPowers();
    initTerms();
    scanf("%d", &T);
    for( tc = 0; tc <T; tc++) {

        scanf("%d", &n);
        printf("N=%d, %lld\n",n, term[n]%MOD);

    }
    return 0;
}

term[i] = term[i-1] + pow(26, (i+1)/2);
