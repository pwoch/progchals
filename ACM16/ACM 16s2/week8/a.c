#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int tc, T;
    long long w, h, a;
    scanf("%d", &T);
    for( tc = 0; tc < T; tc++) {

        scanf("%lld %lld %lld", &w, &h, &a);
        printf("%lld\n", ((w-1)/a + 1)*((h-1)/a +1));
    }
    return 0;
}
