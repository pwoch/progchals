#include <iostream>

#define MAX_E 200020
#define MAX_V 1010
#include <cstdio>

using namespace std;

int to[MAX_E], from[MAX_E], succ[MAX_E], num[MAX_V], start[MAX_V];
int m = 0;
//Add undirected edge from u to v
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
    for (int i = 1; i < MAX_V; i++) {
        start[i] = -1;
        num[i] = 0;
    }
    int N, M, A, B;
    cin >>N >>M >>A >>B;
    int u,v,count = 0, total = 0;
    for (int i = 0; i < M; i++) {
        cin >>u >>v;
        add(u,v);
        printf("added %d %d\n", u, v);
    }
    printf("A = %d. B = %d\n", A, B);
    for (int modified = 1; modified; ) {
        modified = 0;
        for (v = 1; v <= N; v++,count = 0) {
            if( num[v] == -1) continue;
            for (int e = start[v]; e != -1; e = succ[e]) {
                if (num[to[e]] != -1) count++;
            }
            num[v] = count;
            printf("%d knows %d people and doesn't know %d\n", v, count, N-count);
        }
        for (v = 1; v <= N; v++) {
            if ((num[v] != -1) || !(A <= num[v] && B <= N-count)) { 
                num[v] = -1;
                total++;
                modified = 1;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}

