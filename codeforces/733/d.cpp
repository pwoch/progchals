#include <iostream>
#include <algorithm>
#include <vector>
#define MAX ((int)10e5)

using namespace std;

typedef pair<int,int> p;
typedef pair<p,int> pi;

#define f first
#define s second 
#define mk(a,b) make_pair(a,b) 

int main() {
    vector<vector<pi> > v1(MAX);
    p h[MAX];
    int n,ans,l,t[3],val,index,pos;

    cin >>n;
    for (int i=1;i<=n;i++) {
        cin>>t[0]>>t[1]>>t[2];
        sort(t,t+3,less<int>());
        v1[t[2]].push_back(mk(mk(t[0],t[1]),i));
    }
    
    //for (int i=0;i<n;i++) h[i] = mk(0,0);

    int fi1,fi2,i1,i2;
    ans=0;
    for (int i=0;i<n;i++) {
        l = v1[i].size();
        if (l) {
            cout<<"looking at size: "<<i<<endl;
            //Need to use map instead
            for (int i=0;i<n;i++) h[i].f=0,h[i].s=0;
            i1=i2=0;

            for (int j=0;j<l;j++) {
                val = v1[i][j].f.f;
                index = v1[i][j].f.s;
                pos = v1[i][j].s;
                if (h[index].f == 0) h[index].f = val, i1 = pos;
                else if (h[index].s == 0) h[index].f = val, i2 = pos;
                else {
                    //Both entries are filled
                    if (val > h[index].f) {
                        if (h[index].f > h[index].s) {
                            i2 = i1;
                            h[index].s = h[index].f;
                        }
                        h[index].f = val;
                        i1 = pos;
                    }
                    else if (val > h[index].s) {
                        h[index].s = val;
                        i2 = pos;
                    }
                }
                if (h[index].f + h[index].s > ans) {
                    ans = h[index].f+h[index].s;
                    fi1 = i1;
                    fi2 = i2;
                }
            }
        }
    }
    if (fi2) {
        cout <<"2\n";
        cout <<fi1<<" "<<fi2<<endl;
    } else {
        cout <<"1\n";
        cout <<fi1<<endl;
    }
    return 0;
}







