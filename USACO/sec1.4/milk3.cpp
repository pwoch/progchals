/*
ID: wochnow1 
LANG: C++
TASK: milk3
*/

#include <fstream>
#include <queue>
#include <cstring>
#include <iostream>

#define MAX 10000 
#define index(s) (s.a*441+s.b*21+s.c)
#define isValid(s) ((s.a+s.b+s.c)==c)


using namespace std;

int to[MAX], from[MAX], succ[MAX];
int start[MAX];
int m = 0;

typedef struct state{
    int a, b, c;
}st;

    ifstream in ("milk3.in");
    ofstream out ("milk3.out");
void go(st s, st p); 

void add(int u, int v) {
    to[m] = v;
    from[m] = u;
    succ[m] = start[u];
    start[u] = m++;
}

    int a, b, c;
int seen[MAX];
int hash[24] = {0};

int main() {
    memset(start,-1,sizeof(int)*MAX);

    st ar[MAX];
    int l = 0;
    for (int i = 0; i <= 20; i++) {
        for( int j = 0; j <= 20; j++) {
            for( int k = 0; k <= 20; k++) {
                ar[l].a = i;
                ar[l].b = j;
                ar[l].c = k;
                seen[l++] = 0;
            }
        }
    } 
    in >>a >>b >>c;
    st n = {0,0,c};
    st dummy = {0,0,0};
    go(n,dummy);
    for (int i = 0; i < MAX; i++) seen[i] = 0;

    queue<int> q;
    q.push(index(dummy));
    seen[(index(dummy))] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int e = start[v]; e != -1; e = succ[e]) {
            if (seen[to[e]]) continue;
            if (ar[to[e]].a == 0) 
                hash[ar[to[e]].c] = 1;

            q.push(to[e]);
            seen[to[e]] = 1;
        }
    }

    for (int i = 0; i <= 20; i++) {

        if (i == c) out<<c<<'\n'; 
        else if (hash[i]) out<<i<<" ";
    }


    return 0;
}

void go(st s, st p) {

    out<<"Looking at "<<s.a<<" "<<s.b<<" "<<s.c<<" after "<<p.a<<" "<<p.b<<" "<<p.c<<endl;
    if ( !seen[index(s)] && isValid(s)) {
        add(index(p),index(s));
        seen[index(s)] = 1;
        st n;
        //Pour c into a or b
        n.a = s.a;
        n.b = min(s.b+s.c,b);
        n.c = max(s.c-n.b,0);
        go(n,s);
        n.a = min(s.a+s.c,a);
        n.b = s.b;
        n.c = max(s.c-n.a,0);
        go(n,s);
        //Pour b into a or c
        n.a = s.a;
        n.c = min(s.c+s.b,c);
        n.b = max(s.b-n.c,0);
        go(n,s);
        n.a = min(s.a+s.b,a);
        n.b = max(s.b-n.a,0);
        n.c = s.c;
        go(n,s);
        //Pour a into b or c
        n.b = min(s.b+s.a,b);
        n.a = max(s.a-n.b,0);
        n.c = s.c;
        go(n,s);
        n.c = min(s.c+s.a,c);
        n.a = max(s.a-n.c,0);
        n.b = s.b;
        go(n,s);
    }
}


