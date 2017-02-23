

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {

    int N;
    char s[3][MAX];
    scanf("%d %s %s %s", &N, s[0], s[1], s[2]);
    int i;
    int triple=0, p12=0, p13=0, p23=0, single=0;
    for (i = 0; i < N; i++) {
        if (s[0][i] == s[1][i]) {
            if( s[0][i] == s[2][i]) triple++;
            else p12++;
        } else if (s[0][i] == s[2][i]) {
            p13++;
        } else if (s[1][i] == s[2][i]) {
            p23++;
        } else {
            single++;
        }
    }
    printf("Triples %d\nPairs: 12, %d\t13, %d\t23 %d\nSingles: %d\n",triple,p12,p13,p23,single);
    return 0;
}
        

