
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define dist(u,v) ((abs(u.x-v.x) + abs(u.y-v.y)))
#define eql(u,v) (u.x == v.x && v.y == u.y)
#define validV(u) (abs(u.x) <= 2000 && abs(u.y) <= 2000)

typedef struct _pair{
    int x, y, d;
}pair;

void go(pair orig, pair u, pair dest);

int abs(int n) {
    return (n > 0) ? n : -n;
}

pair dir[4] = {{0,1,'U'}, {1,0,'R'}, {-1,0,'L'}, {0,-1,'D'}};
int g[2010][2010];
pair s, d;
int vis = 0;
int c = 0;

float euclid(pair u, pair v) {
    return sqrt((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y));
}

int main() {
    scanf("%d %d %d %d",&s.x, &s.y, &d.x, &d.y);
    int i, j;
    for ( i = 0; i < 2010; i++) {
        for ( j=0; j < 2010; j++) {
            g[i][j] = 0;
        }
    }
    s.x += 1000;
    s.y += 1000;
    d.x += 1000;
    d.y += 1000;
    int dirX = (d.x-s.x)/abs(d.x-s.x);
    int dirY = (d.y-s.y)/abs(d.y-s.y);
    char dy1, dx1, dy2, dx2;
    dy1 = (dirY>0) ? 'U' : 'D';
    dx1 = (dirX>0) ? 'R' : 'L';
    dy2 = (dirY>0) ? 'D' : 'U';
    dx2 = (dirX>0) ? 'L' : 'R';
    int p, q;
    for (p = s.y; p != d.y; p+=dirY) {
        g[s.x][p] = 1;
        printf("%c",dy1);
    }
    for (q = s.x; q != d.x; q+=dirX) {
        g[q][p] = 1;
        printf("%c",dx1);
    }

    for (p = d.y; p != s.y; p-=dirY) {
        g[d.x][p] = 1;
        printf("%c",dy2);
    }
    for (q = d.x; q != s.x; q-=dirX) {
        g[q][p] = 1;
        printf("%c",dx2);
    }
    
    go(s,s,d);

    printf("\n");
    return 0;
}


void go(pair orig, pair u, pair dest) {
    pair a[4];

    if (eql(dest,u)) {
        //reached destination
        go(dest,dest,orig);
        return;
    }
    g[u.x][u.y] = 1;
    int min = 10000, minI = -1;
    int i;
    for (i = 0; i < 4; i++) {
        a[i].x = u.x + dir[i].x;
        a[i].y = u.y + dir[i].y;
        a[i].d = dist(a[i],dest);
        if (validV(a[i]) && (g[a[i].x][a[i].y] == 0 || eql(dest,a[i]))) {
            if (a[i].d < min) {
                min = a[i].d;
                minI = i;
            } else if ( a[i].d == min) {
                //if the current minimum lies on the same line choose the other option
                if ((a[minI].x - dest.x == 0) || (a[minI].y - dest.y == 0)) {
                    minI = i;
                } else if ( euclid(a[i],dest) < euclid(a[minI], dest)) {
                    minI = i;
                }
            }
        }
    }
    //if we have somewhere to go...
    if (minI != -1) {
        printf("%c",dir[minI].d);
        go(orig, a[minI], dest);
    }
}
