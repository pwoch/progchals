#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define MAX 100003

set<int> s;
int h[MAX] = {};
int a[MAX];

struct rg{
    int start, sum;
    bool operator<(rg o) const
    {
        return sum < o.sum;
    }
};

priority_queue<rg> q;
void add(int i, int e) {
    //cout<<"Adding interval from "<< i<<" to "<<e<<" size "<<a[e-1]-a[i]<<endl;
    s.insert(i);
    s.insert(e);
    rg t = {i,a[e-1]-a[i]};
    q.push(t);
    h[i]++;
}

int main() {
    int N,tmp;
    cin>> N;
    a[0] = 0;
    for (int i=1;i<=N;i++) {
        cin>>tmp;
        a[i] = tmp+a[i-1];
        h[i] = 0;
    }
    add(0, N+1);
    set<int>::iterator low, high;
    for (int i=1;i<=N;i++) {
        cin>>tmp;
        low = upper_bound(s.begin(), s.end(), tmp);
        high = lower_bound(s.begin(), s.end(), tmp);
        low--;

        //cout<<tmp<<" upper bound: "<< *high <<" lower bound: "<< *low<<endl;
        if (*high != *low) {
            add(*low, tmp);
            add(tmp,*high);
        } 
        rg tmp;
        for (tmp=q.top(),q.pop(); h[tmp.start]-- != 1; tmp=q.top(), q.pop());
        q.push(tmp);
        h[tmp.start]++;
        
        cout<<tmp.sum<<endl;
    }

}

