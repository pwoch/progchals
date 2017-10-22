#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 110

int parent[MAX];
int size[MAX];
pair<int, pair<int, int> > edges[MAX*MAX]; // each edge is (weight, (u, v))
vector<int> mst;

int root(int x) {
    return parent[x] == x ? x : parent[x] = root(parent[x]);
}

void join(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return;
    if (size[x] < size[y]) parent[x] = y, size[y] += size[x];
    else parent[y] = x, size[x] += size[y];
}

int main() {
    int T;
    cin>> T;

    for (int t=1; t<=T; t++) {
        int N, M;
        int u,v,c;
        cin>> N>> M;
        for (int e=0; e<M; e++) {
            cin>> u>> v>> c;
            edges[e].first = c;
            edges[e].second = make_pair(u,v);
        }

        for (int i = 0; i < N; ++i) parent[i] = i, size[i] = 1;
        sort(edges, edges + M, greater<pair<int, pair<int, int> > >());

        for (int i = 0; i < M; ++i) {
            // if the vertices connected by this edge are already connected, skip it
            if (root(edges[i].second.first) == root(edges[i].second.second)) continue;
            // add the edge to the tree
            mst.push_back(i);
            // join the two vertices in the union find so we know they’re connected
            join(edges[i].second.first, edges[i].second.second);
        }
        cout<<"Case #"<<t<<": "<< edges[mst[mst.size()-1]].first << endl;
    }

    return 0;
}
