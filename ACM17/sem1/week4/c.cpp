#include <iostream>

using namespace std;

#define MAX 2*100000

long long a[MAX];
long long s[MAX];

int main() {
    int l, r,t, N, Q;
    cin>>N;
    for (int i=N; i>0; i--) cin>>a[i];

    s[0] = 0;
    for (int i=1;i<=N;i++) { 
        s[i] = a[i] + s[i-1];
    }
    for (int i=1;i<=N;i++) 
        cout<<s[i]<<" ";
    cout<<endl;

    cin>>Q;
    for (int i=1;i<=Q;i++) {
        cin>>t;
        if (t==1) {
            cin>>l>>r;
            cout<<s[N-l+1]-s[N-r-1];
        } else {
            cin>>t;
            s[N+1] = s[N] + t;
            N++;
        }
    }
    return 0;
}
