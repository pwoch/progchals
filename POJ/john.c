#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4000


int to[M], from[M], succ[M], start[M];
int num[M], deg[M], trip[M];

int t = 1, m = 0;

//Add edge n from u to v and v to u
void add(int u, int v, int n) {
    deg[u]++, deg[v]++;

    from[m] = u, to[m] = v;
    succ[m] = start[u];
    num[m] = n;
    start[u] = m++;

    from[m] = v, to[m] = u;
    succ[m] = start[v];
    num[m] = n;
    start[v] = m++;
}

void findTour(int s, int n) {
    int pa[M] = {-1};
    memset(pa, -1, sizeof(int)*M);
    int minE, minN, e, v, tmp;
    v = s;
    //t represents how many edges we've added
    while (t <= n) {
        //Find unvisited edge from v with smallest number
        minN = M;
        minE = -1;
        //printf("From %d\n", v);
        for (e = start[v]; e != -1; e = succ[e]) {
            //printf("Edge %d (pa[%d]: %d, pa[%d]: %d) to %d\n", num[e],e,pa[e],e^1, pa[e^1], to[e]); 
            if (pa[e] != -1 || pa[e^1] != -1) continue;
            if (num[e] < minN) {
                minN = num[e];
                minE = e;
            }
        }
        //printf("Smallest is %d to %d\n\n",num[minE],to[minE]);
        //If we couldn't find a valid edge, retrace steps until we can find a vertex that has another outgoing edge
        while (minE == -1) {
            //printf("%d\n",t);
            //printf("Previous choice from %d didnt work\n",from[trip[t-1]]);
            for (e = start[from[trip[t-1]]]; e != -1; e = succ[e]) {
            //printf("Edge %d (pa[%d]: %d, pa[%d]: %d) to %d\n", num[e],e,pa[e],e^1, pa[e^1], to[e]); 
                if (pa[e] != -1 || pa[e^1] != -1) continue;
                //if (to[e] == from[s] && t != n-1) continue;
                //printf("Found %d to %d\n", num[e], to[e]);
                if (num[e] < minN) {
                    minN = num[e];
                    minE = e;
                }
            }
            //Reset the edge that didn't work
            pa[trip[t-1]] = -1;
            trip[--t] = 0;
        }

        //Add the smallest edge to result
        pa[minE] = trip[t-1];
        trip[t++] = minE;
        v = to[minE];
    }
}

int main() {

    int werks, i;
    int N,n,u,v,s;
    do {
        //reset graph
        for (i = 0; i < M; i++) {
            to[i] = 0;
            from[i] = 0;
            succ[i] = -1;
            num[i] = 0;
            start[i] = -1;
            deg[i] = 0;
            trip[i] = 0;
        }
        t = 1, m = 0, n = 0, N = 0,s = -1;
        //construct graph
        do {
            scanf("%d %d", &u, &v);
            if (s==-1) s = (u < v) ? u : v;
            if (u && v) {
                scanf("%d", &n);
                N = (n > N) ? n : N;
                add(u,v,n);
            }
        } while(u && v);

        werks = (N != 0);
        //check if all edges have even degree
        for (i = 0; i < N; i++) {
            if (deg[i]%2) {
                printf("Round trip does not exist\n");
                werks = 0;
                break;
            }
        }
        //Find the Euler Path
        if (werks) {
            findTour(s, N);
            for (i = 1; i < N; i++) {
                printf("%d ", num[trip[i]]);
            }
            printf("%d\n", num[trip[N]]);
        }
    } while( m != 0);

    return 0;
}
