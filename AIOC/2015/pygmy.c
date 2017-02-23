#include <stdio.h>
#include <stdlib.h>
int main() {
    freopen("hippoin.txt","r",stdin);
    freopen("hippoout.txt","w",stdout);
    int N, h1, h2, h3, max = 0;
    scanf("%d %d %d %d", &N, &h1, &h2, &h3);
    int f01 = h1 - 1;
    int f12 = h2 - h1 - 1;
    int f23 = h3 - h2 - 1;
    int f34 = N - h3;
    if( f01 + f12 > max) max = f01 + f12;
    if( f01 + f23 > max) max = f01 + f23;
    if( f01 + f34 > max) max = f01 + f34;
    if( f12 + f34 > max) max = f12 + f34;
    if( f23 + f34 > max) max = f23 + f34;
    printf("%d\n", max);
    return 0;
}
