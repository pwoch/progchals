

#include <stdio.h>
#include <stdlib.h>

int main() {

    int t, T, N;
    scanf("%d", &T);

    for( t = 0; t < T; t++){
        scanf("%d", &N);
        if( N % 2 == 0){
            printf("ALICE\n");
        } else {
            printf("BOB\n");
        }
    }
    return 0;
}
    
