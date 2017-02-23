
#include <iostream>
#define MAX 10000

using namespace std;

int c[MAX+1];

int f(int n) {
    if (n < MAX) {
        if ( c[n] == -1) {
            if (n%2) {
                c[n] = 1 + f(3*n+1);
            } else {
                c[n] = 1 + f(n/2);
            }
        }
        return c[n];
    } else {
        if (n%2) return 1 + f(3*n+1);
        else return 1 + f(n/2);
    }
}

int main() {
    for (int i = 0; i <= MAX; i++) c[i] = -1;
    c[1] = 1;

    int k, l;
    while ( cin>> k>> l) {
        int m = 1;
        int a = min(k,l);
        int b = max(k,l);
        for (int i = a; i <= b; i++) {
            m = max(f(i),m);
        }
        cout<<k<<" "<<l<<" "<<m<<endl;
    }
    return 0;
}



