#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define MAX 10005

int l[MAX] = {0};
int s[MAX] = {0};

int root(int x) {
    if (l[x] == x) return x;
    l[x] = root(l[x]);
    return l[x];
}

void join(int x,int y) {
    int xroot = root(x);
    int yroot = root(y);
    l[xroot] = yroot;
}
    
int main() {
    int N,tmp,T,Q,x,y;
    cin>>T;
    for (int t=0;t<T;t++) {
        //make all sets disjoint for new test case
        for (int i=0;i<MAX;i++) l[i]=i;

        //Read input
        cin>>N;
        for(int i=1;i<=N;i++) cin>>s[i];
        cin>>Q;

        for (int q=0;q<Q;q++) {
            cin>>tmp;
            switch(tmp) {
                case(0) :
                    //Check if the items are owned by the same chefs
                    cin>>x>>y;
                    if (root(x) == root(y)) {
                        cout<<"Invalid query!"<<endl;
                    } 
                    else {
                        if (s[root(x)] > s[root(y)])
                            join(y,x);
                        else if (s[root(y)] > s[root(x)]) 
                            join(x,y);
                    }
                    break;
                case(1) :
                    cin>>x;
                    cout<<root(x)<<endl;
            }
        }
    }
}
