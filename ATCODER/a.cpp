#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;

int p[MAX];

int main() {

    int N,C,K;
    int b=0;
    cin>>N>>C>>K;
    for(int i=0;i<N;i++) {
        cin>>p[i];
    }
    sort(p,p+N,less<int>());
    int end,cap;
    for(int i=0;i<N;) {
        end=p[i]+K;
        cap=1;
        b++;
        while (i<N && cap <= C && p[i] <= end ) {
            cap++;
            i++;
        }
    }
    cout<<b<<endl;
    
    return 0;
}
