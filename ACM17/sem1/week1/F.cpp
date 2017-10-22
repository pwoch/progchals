
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 10010
#define MAX_P (long long) 1e14

using namespace std;

long long s[MAX];
vector <long long> p(50);

int binary(int lo, int hi, long long target) {
    int mid;
    while ( lo <= hi) {
        mid = lo + (hi-lo)/2;
            if (p[mid] == target)
                return 1;   
            else if (p[mid] < target)
                lo = mid+1;
            else
                hi = mid-1;
    }
    return 0;
}

int main() {

    int N, K,m=0;
    cin >>N >>K;
    if (K ==1) {
        p[0] = 1;
        m=1;
    } else if (K==-1) {
        p[0] = -1;
        p[1] = 1;
        m=2;
    } else {
        for (long long s=1,k=0; s < MAX_P; s*=K,k++,m++) {
            p[k] = s;
        }
        sort(p.begin(),p.begin()+m,less<long long>());
    }
    s[0] = 0;
    int i = 1, t;
    while (i <= N) {
        cin >>t;
        s[i] = t + s[i-1];
        i++;
    }

    int total = 0;
    for (int l=1, r=1; r <= N; r++) {
        for (int a=l, b=r; b <= N; a++,b++) {
            if (binary(0,m,s[b] - s[a-1])) total++;
        }
    }
    cout<< total<<endl;

    return 0;
}


