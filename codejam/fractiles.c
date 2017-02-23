#include <stdio.h>
#include <stdlib.h>


int main() {

    int size;
    int complexity;
    int scholars;
    int N, i, n;

    scanf("%d", &N);

    i = 1;
    while( i <= N) {
        scanf("%d%d%d", &size, &complexity, &scholars);
        printf("Case #%d:", i); 
        if( scholars < size) {
            printf(" IMPOSSIBLE");
        } else {
            n = 1;
            while( n <= scholars) {
                printf(" %d", n);
                n++;
            }
        }
        printf("\n");
        i++;
    }
    
    return EXIT_SUCCESS;
}


