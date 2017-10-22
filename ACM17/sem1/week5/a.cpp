
#include <iostream>

using namespace std;

int main() {
    int N;
    cin>>N;
    int t, lt;
    int m=0, c= 0;
    lt = 0;
    for (int i=0;i<N;i++) {
        cin>> t;
        c = (lt < t) ? c+1 : 1;
        m = max(m, c);
        lt = t;
    }
    cout<<m<<endl;
}
