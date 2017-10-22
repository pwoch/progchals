#include <iostream>
#include <queue>

#define M 50

#define id(r,h) (r+h*H)
using namespace std;

typedef pair<int, int> p;
#define f first
#define s second
#define m(a,b) make_pair(a,b)

//Height, and ROW
int H, R;
int adj[M*M][M*M];
int comp[M*M];
int sz[M*M];
p dir[] = {m(1,0), m(0,1), m(-1,0), m(0,-1)};

int main() {
    int tmp;
    cin >>R >>H;
    for (int j=0; j<H; j++) {
        for (int i=0; i<R; i++) {
            comp[id(i,j)]=0;
            cin >>tmp;
            //No wall to the west
            if ((tmp&1)==0) {
                adj[id(i,j)][id(i+1,j)]=1;
                adj[id(i+1,j)][id(i,j)]=1;
            }
            //No wall to the north
            if ((tmp&2)==0) {
                adj[id(i,j)][id(i,j-1)]=1;
                adj[id(i,j-1)][id(i,j)]=1;
            }
            //No wall to the east
            if ((tmp&4)==0) {
                adj[id(i,j)][id(i-1,j)]=1;
                adj[id(i-1,j)][id(i,j)]=1;
            }
            //No wall to the south
            if ((tmp&8)==0) {
                adj[id(i,j)][id(i,j+1)]=1;
                adj[id(i,j+1)][id(i,j)]=1;
            }
        }
    }
    queue<p> q; 
    int counter = 1;
    for (int j=0; j<H; j++) {
        for (int i=0; i<R; i++) {
            if (comp[id(i,j)]) continue;
            q.push(p(i,j));
            comp[id(i,j)] = counter;
            sz[counter] = 1;
            while (!q.empty()) {
                p t = q.front();
                q.pop();
                for (int k=0; k<4; k++) {
                    p next = p(t.f+dir[k].f, t.s+dir[k].s);
                    if (!adj[id(t.f, t.s)][id(next.f, next.s)]) continue; 
                    comp[id(next.f, next.s)] = counter;
                    sz[counter]++;
                    q.push(next);
                }
            }
            counter++;
        }
    }
    int maxComp = 0;
    int maxPair = 0;
    int bestDir = 0;
    p best;
    for (int i=0; i<R; i++) {
        for (int j=0; j<H; j++) {
            p t = p(i,j);
            int compsz = sz[comp[id(i,j)]];
            maxComp = max(compsz,maxComp);
            for (int k=0; k<2; k++) {
                p next = p(t.f+dir[k].f, t.s+dir[k].s);
                if (adj[id(t.f, t.s)][id(next.f, next.s)]) continue; 
                if (maxPair <= sz[comp[id(next.f, next.s)]]+compsz) continue;
                best = t;
                bestDir = k;
                maxPair = sz[comp[id(next.f, next.s)]] + compsz;
            }
        }
    }
    cout<<counter<<endl;
    cout<<maxComp<<endl;
    cout<<maxPair<<endl;
    cout<<best.f<<" "<<best.s<<" "<<((bestDir==0)?'N':'E')<<endl;

}
