#include <iostream>

using namespace std;
#define MAX 100000

long long a[MAX+2];

int main() {
    int N, tmp;
    a[0] = 0;
    cin>>N;
    for (int i=1;i<=N;i++) {
        cin>>tmp;
        a[i]=tmp+a[i-1];
    }
    for (int i=1;i<N;i++) {
        cin>>tmp;
        a[i]=tmp+a[i-1];
    }
    cout<<a[N]-a[N-1]<<endl;
    for (int i=1;i<N-1;i++) {
        cin>>tmp;
        a[i]=tmp+a[i-1];
    }
    cout<<a[N-1]-a[N-2]<<endl;
}

