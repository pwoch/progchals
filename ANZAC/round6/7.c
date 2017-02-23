
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll gcd( ll a, ll b){
    return b == 0 ? a : gcd(b, a %b);
}


int main() {
    int players, round;

    while(1) {
        scanf("%d %d", &players, &round);

        if ( players == 0 && round == 0) return 0;


        ll p[10010];
        int i, g;
        ll tmp, total = 0; 
        for( i = 0; i < players; i++) {
            for( g = 0; g < round; g++) {
                scanf("%lld", &p[i]);
            }
            total += p[i];
        }
        for( i = 0; i < players; i++) {
            ll d = gcd(p[i], total);
            printf("%lld / %lld\n", p[i]/d, total/d);
        }     
    }

    return 0;
}

