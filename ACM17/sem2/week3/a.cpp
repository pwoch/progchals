#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main() {
    int n, m;
    int tmp;
    cin >>n >>m;
    for (int i=0; i<m; i++) {
        cin >>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int l,r, diff;
    l=0;
    r=min(n-1,m-1);
    diff = v[r]-v[l];

    while (r < m) {
        diff = min(diff,v[r]-v[l]);
        r++;
        l++;
    }
    cout<<diff<<endl;
}
