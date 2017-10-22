#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

ll pws[62]; 
int N;

int leastSetBit(ll x) {
    int p = 0;
    for (;!(x&pws[p]);p++);
    return p;
}

ll left(ll x) {
    int p = leastSetBit(x);
    if (p==0) return x;
    return (x | pws[p-1]) & ~(pws[p]);
}

ll right(ll x) {
    int p = leastSetBit(x);
    if (p==0) return x;
    return x | pws[p-1];
}

ll parent(ll x) {
    int p = leastSetBit(x);
    if (p==N) return x;
    return (x | pws[p+1]) & ~(pws[p]);
}

int main() {
    ll n, x, Q;
    string s;
    cin>>n>>Q;
    pws[0] = 1;
    for (int i=1; i < 62; i++) pws[i] = pws[i-1]<<1;

    for (int i=0; pws[i]!=n+1; N=i,i++);

    for (int i=0; i<Q; i++) {
        cin >>x >>s;
        int l = s.size();
        for (int i=0; i<l; i++) {
            switch (s[i]) {
                case ('U') :
                    x = parent(x);
                    break;
                case ('L') :
                    x = left(x);
                    break;
                case ('R') :
                    x = right(x);
                    break;
            }
        }
        cout<<x<<endl;
    }
}
