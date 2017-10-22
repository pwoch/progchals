
#include <iostream>

using namespace std;

int gcd(int a,int b) {
    return (b == 0) ? a : gcd(b,b%a);
}
vector<int> a;

int main() {
    int n, i, j,t;
    cin >>n;
    for (i=0;i<n;i++) {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    


    for (int i=0;i<n;i++) 
        for (int j=0;j<n;j++) 
            cout<<t[i][j]<<" ";

}

