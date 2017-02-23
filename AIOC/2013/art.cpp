#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

#define M 1010
#define p pair<int, int>
#define n(a,b) make_pair(a,b)
#define y first
#define x second

char a[M][M];

int dist(int a, int b, int c, int d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    freopen("artin.txt","r",stdin);
    freopen("artout.txt","w",stdout);

    int w,h;
    scanf("%d %d",&h,&w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c",&a[i][j]);
        }
    }
    queue< p> q;
    int c = '0';
    int u,d,r,l,dis=0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'X') {
                u = d = i;
                l = r = j;
                a[i][j] = c;
                q.push(n(i,j));
                while (!q.empty()) {
                    p t = q.front();
                    q.pop();
                    if (t.x+1 < w && a[t.y][t.x + 1] == 'X') {
                        a[t.y][t.x+1] = c;
                        q.push(n(t.y,t.x+1));
                        r = max(r,t.x+1);
                    }
                    if (t.x-1 >= 0 && a[t.y][t.x-1] == 'X') {
                        a[t.y][t.x-1] = c;
                        q.push(n(t.y,t.x-1));
                        l = min(l,t.x-1);
                    }
                    if (t.y+1 < h && a[t.y+1][t.x] == 'X') {
                        a[t.y+1][t.x] = c;
                        q.push(n(t.y+1,t.x));
                        d = max(d,t.y+1);
                    }
                    if (t.y-1 >= 0 && a[t.y-1][t.x] == 'X') {
                        a[t.y-1][t.x] = c;
                        q.push(n(t.y-1,t.x));
                        u = min(u,t.y-1);
                    }
                }
                for (int h=u; h<=d; h++) {
                    if (a[h][l] == c) {
                        for (int k = u; k <= d; k++) {
                            if (a[k][r] == c) {
                                dis = max(dis,dist(h,l,k,r));
                                //printf("new dist from %d,%d to %d,%d: %d\n", h,l,k,r,dist(h,l,k,r));
                            }
                        }
                    }
                }
                for (int s=l; s<=r; s++) {
                    if (a[u][s] == c) {
                        for (int k = l; k <= r; k++) {
                            if (a[d][k] == c) {
                                dis = max(dis,dist(u,s,d,k));
                                //printf("new dist from %d,%d to %d,%d: %d\n", u,s,d,k,dist(u,s,d,k));
                            }
                        }
                    }
                }
                c++;
            }
        }
    }
    printf("%d\n",dis);

    return 0;
}



