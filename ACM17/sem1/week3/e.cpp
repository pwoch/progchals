#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define rem(i) m[i]--
#define add(i) m[i]++, q.push(i)


using namespace std; 

#define MAX 500005
#define pii pair<int,int>
#define f first
#define s second
#define m(a,b) make_pair(a,b)

//r[i] denotes pop. of region i 
//a[i] denotes the parent of i
//h1[i] denotes if the i-th edge has been deleted whilst querying
int r[MAX], a[MAX], h1[MAX];
pii e[MAX];

map<int,int> m;
priority_queue<int> q;
/*
struct rg {

    int region, size;
    bool operator<(rg other) const
    {
        return size < other.size;
    }
};
//bool cmp(const pii& p, const pii& q) { return p.f > q.f; }

priority_queue<rg> q1;
*/

void make_set(int x) { a[x] = x; }

int root(int x) {
    if (a[x] == x) return x;
    a[x] = root(a[x]);
    return a[x];
}

void join(int x,int y) { 
    int ry=root(y), rx=root(x);
    a[ry] = rx;
    //If they belong to diff regions, we absorb them into one region (since we never disjoin them)
    if (ry == rx) return;
    rem(r[rx]),rem(r[ry]);
    r[rx] += r[ry];
    add(r[rx]);
}

int main() {
    int M, N, Q, a, b;
    cin >>N >>M >>Q;
    for (int i=1;i<=N;i++) {
        cin>>r[i];
        make_set(i);
    }
    for (int i=1;i<=M; i++) {
        cin>>a>>b;
        e[i] = make_pair(a,b);
        h1[i] = 1; 
    }
    stack<pair<char, pii> > queries;
    char c;
    for (int i=1;i<=Q; i++) {
        cin>>c;
        if (c == 'P') {
            cin>>a>>b; 
            queries.push( m(c, m(a,r[a]-b)));
            r[a] = b;
        } else {
            cin>>a;
            h1[a]=0;
            queries.push(make_pair(c,make_pair(a,-1)));
        }
    }

    //push everything in to find the biggest region at the end
    for (int i=1;i<=N;i++) add(r[i]); 

    for (int i=1;i<=M;i++) {
        if (h1[i]) {
            join(e[i].f, e[i].s);
        }
    }

    //Stack to store the values for printing later 
    stack<int> pt;
    int t;
    pair<char,pii> tmp;

    for (int i=1;i<=Q;i++) {
        for (t=q.top(),q.pop(); !q.empty() && m[t] <= 0; t=q.top(),q.pop());
        q.push(t);
        pt.push(t);

        tmp = queries.top();
        queries.pop();
        if (tmp.f == 'P') {
            int town=tmp.s.f, diff=tmp.s.s, rx = root(town);
            rem(r[rx]);
            r[rx] += diff;
            add(r[rx]);
        } else {
            //Array e stores the edges from before
            int edge = tmp.s.f;
            //cout<<"Joining region "<<root(e[edge].f)<<" to "<<root(e[edge].s)<<endl;
            join(e[edge].f, e[edge].s);
        }
        /* Debug
           for (int i=1;i<=N;i++) {
        //cout<<i<<" ("<<p[i]<<") belongs to region "<< root(i)<<" of size "<<r[root(i)]<<endl;
        }*/

    }

    while (!pt.empty()) {
        cout<<pt.top()<<endl;
        pt.pop();
    }
    return 0;
}

