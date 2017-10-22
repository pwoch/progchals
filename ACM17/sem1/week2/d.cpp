

#include <iostream>

using namespace std;

int main() {
    int a[100], n, i;
    cin >>n;
    i=0;
    while (i < n) cin >>a[i++];

    long long l=-1,r=1;

    for (i=0; i<n; i++) {
        if (a[i]) {
            if (l!=-1) r *= i-l;
            l=i;
        }
    }
    if (l!=-1) {
        cout<<r<<endl;
    } else {
        cout<<"0\n";
    }
}
