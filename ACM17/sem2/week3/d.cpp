#include <iostream>

#define MAX 4020
using namespace std;
int c[MAX];
int n;
int d[3];

int f(int i) {
    if (i > n) return 0;
    if (c[i] != -1) return c[i];
    int r1 = f(i+d[0]); 
    if (r1 == -1) return -1
    
    int r2 = f(i+d[1]); 
    int r3 = f(i+d[2]);
    c[i] = 1+max(r1?r1:0,max(r1,r3));
    return c[i];
}

int main() {
    cin>>n>>d[0]>>d[1]>>d[2];
    for (int i=0; i<=n; i++) {
        c[i] = -1;
    }

    cout<< max(f(d[0]), max(f(d[1]), f(d[2])));

}
