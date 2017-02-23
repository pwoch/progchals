

#include <stdio.h>
#include <stdlib.h>

#define MAXN 80

int cache[MAXN][MAXN];

memset(cache, 0, sizeof(cache));

int min(int** a, int i, int j) {
    
    if( cache[i][j] == 1) {
        return a[i][j];
    } else {
        if( i == N-1 && j == N-1) {
            return a[i][i];
        }
        int option1 = a[i,j] + min(a, i+1, j);
        int option2 = a[i,j] + min(a, i, j+1);
        cache[i][j] = (option1 > option2) ? option2 : option1;
        return cache[i][j];
    }
}

int main() {

    int a[80][80];
    FILE* inf = fopen("matrix.txt","r");
    memset(a, 0, sizeof(cache));
    int i,j;
    for( i = 0; i < MAXN; i++) {
        for( j = 0; j < MAXN; j++) {
            fscanf("%d,", &a[i][j]);
        }
    }
    min(a, 0, 0);
    
    return 0;
}
