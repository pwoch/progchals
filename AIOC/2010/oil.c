#include <stdio.h>
#include <stdlib.h>

#define M 2005 
#define isValid(x,y) ((0<=x && 0<=y) && (x<c && y<r)) 

typedef struct _s{
    char c;
    int n;
}s;

s a[M][M];
int k, r, c, oX, oY;

void go(int x, int y, int d) {
    if (isValid(x,y) && a[y][x].c != '#' && d < a[y][x].n) {
        a[y][x].c = '*';
        a[y][x].n = d;
        go(x+1,y,d+1);
        go(x,y+1,d+1);
        go(x-1,y,d+1);
        go(x,y-1,d+1);
    }
}

void otherGo(int x, int y) {
    if (isValid(x,y) && a[y][x].c == '.') {
        a[y][x].c = '*';
        otherGo(x+1,y);
        otherGo(x,y+1);
        otherGo(x-1,y);
        otherGo(x,y-1);
    }
}


int main() {
    freopen("oilin.txt","r",stdin);
    freopen("oilout.txt","w",stdout);

    int i, j;
    scanf("%d %d %d\n", &r, &c, &k);
    for (i=0; i < r; i++) {
        for (j=0; j < c; j++) {
            scanf(" %c", &a[i][j].c);
            a[i][j].n = k+1;
            if (a[i][j].c == '$') oX = j, oY = i;
        }
    }

    if ( k < r*c) {
        go(oX, oY, 0);
    } else {
        a[oY][oX].c = '.';
        otherGo(oX, oY);   
    }

    a[oY][oX].c = '$';
    for (i=0; i < r; i++) {
        for (j=0; j < c; j++) printf("%c",a[i][j].c);
        printf("\n");
    }

    return 0;
}










