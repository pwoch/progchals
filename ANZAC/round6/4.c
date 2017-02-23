#include <stdio.h>
#include <stdlib.h>


char s[1000001];
char a[256] = {0};


int main() {

    int l, r, m, n, k;
    int sLen;
    int i;
    int longest;
    char c;
    while(1){

        scanf("%d", &m);
        if( m == 0) return 0;
        i = 0;
        while( (c=getchar()) != '\n') s[i++] = c;
        s[i] = 0;
        if( i <= m) continue;
        sLen = i;
        printf("length: %d\n", sLen);
        l = 0;
        r = 0;
        n = 0;
        longest = 0;
        while( n < m) {
            a[s[r]]++;
            //check if new character is seen
            if( a[s[r]] == 1){
                n++;
            }
            //increment end
            r++;
        }
        longest = r-l;
        printf("Start: %d End: %d\n", l, r);
        for( k = l; k <= r; k++) {
            printf("%c", s[k]);
        }
        printf("\n\n");

        while(1) {
            while( n <= m && r < sLen) {
                a[s[r]]++;
                //check if new character is seen
                printf("new char: %c\n", s[r]);
                if( a[s[r]] == 1){
                    n++;
                }
                //increment end
                r++;
            }
            printf("l: %d r: %d\n", l, r);
            if( r-l > longest) {
                longest = r-l;
                printf("Start: %d End: %d Length: %d\n", l, r, longest);
                for( k = l; k <= r; k++) {
                    printf("%c", s[k]);
                }
                printf("\n\n");
            }

            printf("\n");
            while( n > m ) {
                a[s[l]]--;
                if( a[s[l]] == 0){
                    n--;
                }
                l++;
            }
                        if( r == sLen) break;
        }
    }
    return 0;
}
