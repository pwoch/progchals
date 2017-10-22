#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 2010
#define MAX_S 2010

int w[MAX];
int v[MAX];

int dp[MAX][MAX_S];

int main() {
    int N, S;
    cin>>S;
    cin>>N;

    int i;
    for (i=1; i<=N; i++) {
        cin>>w[i];
        cin>>v[i];
    }

    for (int i=1; i<=N; i++) {
        for (int s=0; s<=S; s++) {
            if (w[i] > s) {
                dp[i][s] = dp[i-1][s];
            } else {
                dp[i][s] = max( dp[i-1][s], dp[i-1][s-w[i]] + v[i]);
            }
        }
    }

    cout<<dp[N][S]<<endl;

    return 0;

}





