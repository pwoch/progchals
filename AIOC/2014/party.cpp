#include <iostream>
#include <cstdio>
#include <fstream>

#define eligible(v) (known[v] >= A && unknown[v] >= B)
#define MAX_V 1010

using namespace std;

ifstream in ("partyin.txt");
ofstream out ("partyout.txt");

int g[MAX_V][MAX_V];
int valid[MAX_V], known[MAX_V], unknown[MAX_V];

int main() {
    for (int i = 1; i < MAX_V; i++) {
        valid[i] = 1;
        for (int j = 1; j < MAX_V; j++) {
            g[i][j] = 0;
        }
    }

    int N, M, A, B;
    in >>N >>M >>A >>B;
    for (int i = 0,u,v; i < M; i++) {
        in >>u >>v;
        if (g[u][v] != 1) {
            g[u][v] = 1;
            g[v][u] = 1;
            known[u]++;
            known[v]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        unknown[i] = N - known[i]-1;
    }

    int P = N, count, modified = 1;
    while (modified) {
        count = 0;
        modified = 0;
        for (int v = 1; v <= N; v++) {
            if (!valid[v]) continue;
            if (!eligible(v)) {
                for (int j = 1; j <= N; j++) {
                    //Adjust how v impacts other vertices
                    if (g[v][j] == 1) {
                        known[j]--;
                    } else {
                        unknown[j]--;
                    }
                }
                //Remove vertex v from consideration
                valid[v] = 0;
                P--;
                modified = 1;
            } else {
                count++;
            }
        }
    }
    out<< count<< endl;
    return 0;
}

