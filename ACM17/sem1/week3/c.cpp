#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define MAX 101
int l[MAX] = {0};

int root(int x) {
    if (l[x] == 0) return 0;
    if (l[x] == x) return x;
    l[x] = root(l[x]);
    //cout<<"root of "<<x<<" is "<<l[x]<<endl;
    return l[x];
}

void join(int x,int y) {
    int xroot = root(x);
    int yroot = root(y);
    //cout<<"xroot: "<<xroot<<",yroot: "<<yroot<<endl;
    l[xroot] = yroot;
}
void make_set(int x) {
    if (l[x]==0) l[x]=x;
}
    

int main() {
    set<int> s; 
    int total = 0;
    int n,m,tmp;
    int a[MAX];
    int hash[MAX];
    cin>>n>>m;

    int t=0;
    for (int i=0;i<n;i++) {
        cin>>tmp;
        if (tmp==0) t++;
        for (int j=0;j<tmp;j++){
            cin>>a[j];
            //cout<<"Making set "<<a[j]<<endl;
            make_set(a[j]);
        }
        for (int j=0;j<tmp;j++) {
            for (int k=j+1;k<tmp;k++) {
                //cout<<"Joining "<<a[j]<<" "<<a[k]<<endl;
                join(a[j],a[k]);
            }
        }
    }
    int r;
    for (int i=1;i<=n;i++) {
        r = root(i);
        if (r) s.insert(r);
    }
    if (s.size() != 0) t = max(((int)s.size())-1+t,0); 
    cout<<t<<endl;
    return 0;
}
