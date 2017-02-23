#include <fstream>
#include <iostream>
#include <cstring>
#include <queue>
#define NUM_E 1000001
#define NUM_V  100001

using namespace std;

ifstream in ("arthin.txt");
ofstream out ("arthout.txt");

int to[NUM_E*2],from[NUM_E*2],succ[NUM_E*2];
int start[NUM_V], color[NUM_V];
int m = 0;
void add(int u, int v) {
    from[m] = u;
    to[m] = v;
    succ[m] = start[u];
    start[u] = m++;
    from[m] = v;
    to[m] = u;
    succ[m] = start[v];
    start[v] = m++;
}

int main() {
    memset(to,0,2*NUM_E*sizeof(int));
    memset(from,0,2*NUM_E*sizeof(int));
    memset(succ,0,2*NUM_E*sizeof(int));
    memset(start,-1,NUM_V*sizeof(int));
    memset(color,0,NUM_V*sizeof(int));
    
    int n, k, u, v, size, c1, c2, s, c;
    in >>n >>k;
    for (int i = 0; i < k; i++) {
        in >>u >>v;
        add(u,v);
    }
    queue<int> q;
    for (v = 1, size = 0; v <= n; v++) {
        c1 = c2 = 0;
        if (color[v]) continue;
        q.push(v);
        color[v] = 1;
        c1++;
        while (!q.empty()) {
            s = q.front();
            q.pop();
            c = (color[s] == 1) ? 2 : 1;
            for (int e = start[s]; e != -1; e = succ[e]) {
                if (color[to[e]]) continue;
                color[to[e]] = c;
                if (c == 1) c1++;
                else c2++;
                q.push(to[e]);
            }
        }
        size += max(c1, c2);
    }
    out<<size;
    return 0;
}
        
