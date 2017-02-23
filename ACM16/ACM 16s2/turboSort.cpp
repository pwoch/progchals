
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int i, int j) {return (i>j);}

int main() {
    int n;
    cin >>n;
    int i;

    vector<int> v(n);
    for( i = 0; i < n; i++){
        cin>> v[i];
    }
    sort(v.begin(),v.end());
    for( i = 0; i<n; i++){
        cout<< v[i]<<'\n';
    }
    return 0;
}
        


