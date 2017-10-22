#include <iostream>
#include <queue>

#define Y cout<<"YES\n"; return 0;
#define N cout<<"NO\n"
#define MAX 100000

int to[MAX], from[MAX], first[MAX], succ[MAX];
int e=0;

using namespace std;

void add(int u, int v) {
    from[e] = u;
    to[e] = v;
    succ[e] = first[u];
    first[u] = e++;
}

int main() {
    for (int i=0; i<MAX;i++) first[i]=-1;
    int n, d, t;
    cin >>n >>d;
    for (int i=1; i<n; i++) {
        cin >>t;
        add(i,t+i);
    }
    int seen[MAX];
    for (int i=1; i<=n; i++) seen[i]=0;

    queue<int> q;
    q.push(1);
    seen[1] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=first[v]; i!=-1; i=succ[i]) {
            int m = to[i];
            if (seen[m]) continue;
            if (m == d) { Y }
            seen[m]=1;
            q.push(m);
        }
    }
    N;
    return 0;
}




