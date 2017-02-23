#include <stdio.h>
#include <stdlib.h>


int main() {

    int e, f;
    scanf("%d %d", &e,  &f);
    long long empty = e + f;
    long long full;
    long long count = 0;
    int k;
    scanf("%d", &k);
    while( empty >= k) {
        full = empty/k;
        empty = full + empty%k;
        count += full;
    }
    printf("%lld\n", count);
    return 0;
}
