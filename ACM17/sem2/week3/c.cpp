#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10010

using namespace std;

vector<int> v;
int f[MAX];

int main() {
    int n, k;
    int tmp;
    cin >>n >>k;
    f[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >>tmp;
        f[i] = tmp + f[i-1];
    }
    int l,r, diff;

    l=1;
    r=min(k,n);
    int res = r;
    diff = f[r]-f[l];
    while (r <= n) {
        if (diff > f[r]-f[l]) {
            res = l;
            diff = f[r]-f[l];
        }
        r++;
        l++;
    }
    cout<<res <<endl;
}
