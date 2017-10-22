#include <iostream>
using namespace std;

#define Y cout<<"YES\n"
#define N cout<<"NO\n"

int main() {
    char v1, v2, h1, h2;
    int m, n;
    cin >> n>> m;
    cin >>h1;
    for (int i=1; i<n; i++) cin>>h2;
    cin >>v1;
    for (int i=1; i<m; i++) cin >>v2;
    if (v1 == 'v') {
        if (h2 == '>' && h1 != h2 && v1 != v2) Y;
        else N;
    } else {
        if (h2 == '<' && h1 != h2 && v1 != v2) Y;
        else N;
    }
    
    return 0;
}

