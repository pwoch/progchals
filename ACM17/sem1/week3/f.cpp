#include <queue>
#include <iostream>
using namespace std;

#define p pair<int,int> 
#define f first
#define s second


int main() {
    int N,T,k,b;
    p tmp;
    cin>>T;
    for (int t=0;t<T;t++) {
        int hash[10] = {0};
        cin>>N>>k;
        queue<p> q;
        for (int i=0;i<N;i++) {
            cin>>tmp.f;
            tmp.s = (i==k) ? 1 : 0;
            hash[tmp.f]++;
            q.push(tmp);
        }
        int total=0;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            b=0;
            for (int i=tmp.f+1;i<10;i++) {
                if (hash[i]) {
                    b=1;
                    break;
                }
            }
            if (b) q.push(tmp);
            else {
                hash[tmp.f]--;
                total++;
                if (tmp.s) {
                    cout<<total<<endl;
                    break;
                }
            }
        }
    }
}
