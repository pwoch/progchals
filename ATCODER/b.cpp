#include <iostream>
#include <algorithm>

#define MAX 100000
using namespace std;

int a[MAX];

int main() {
    int N,t=0;
    cin>>N;
    for (int i=0;i<N;i++) cin>>a[i];
    sort(a,a+N);
    long long sz = 0;
    for (int i=0;i<N;i++) {
        t = (a[i] <= 2*sz) ? t+1 : 1;
        sz+=a[i];
    }
    cout<<t<<endl;
    return 0;
}
        
