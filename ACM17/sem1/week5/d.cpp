#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100010

using namespace std;

string a[MAX];
int c[MAX];
int N;
long long dp[MAX][2];
typedef long long ll;

long long go( int i, int set) {

    if (i == N) return 0;

    if ( dp[i][set] != (ll) 1e15) return dp[i][set];

    string curr = a[i];
    if (set) {
        reverse(curr.begin(), curr.end());
    }

    string next = a[i+1];
    string nextR = next;
    reverse(nextR.begin(), nextR.end());

    if (curr > nextR && curr > next) return 1e15;

    if (curr <= next) {
        //cout<<"No need to reverse next string"<<endl;
        dp[i][set] = go(i+1,0);
        //cout<<i<<", "<<set<<": "<<dp[i][set]<<endl;
    }

    if (curr <= nextR) {
        //cout<<"Reversing next string"<<endl;
        dp[i][set] = min(dp[i][set], c[i+1] + go(i+1,1));
        //cout<<i<<", "<<set<<": "<<dp[i][set]<<endl;
    }
    return dp[i][set];
}

int main() {

    cin>>N;
    for (int i=1;i<=N;i++) cin>>c[i];
    for (int i=1;i<=N;i++) cin>>a[i];
    dp[N][0] = dp[N][1] = 0;
    for (int i=0;i<=N;i++) dp[i][0]=dp[i][1]=1e15;
    a[0] = "a";

    go(0,0);
    go(0,1);
    if (dp[0][0] == (long long) 1e15 && dp[0][1] == (long long) 1e15)
        cout<<-1<<endl;
    else 
        cout<<min(dp[0][0],dp[0][1])<<endl;
}
