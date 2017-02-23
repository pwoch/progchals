/*
ID: wochnow1 
LANG: C++
TASK: sprime
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>

#define MAX 10001

using namespace std;
vector<vector<int> > v(9);


int isPrime(int n) {
    if ( n==2) return 1;
    if ( n==1) return 0;
    if ( n%2 == 0) return 0;
    for (int i = 3; i*i <= n; i+=2) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ifstream in("sprime.in");
    ofstream out("sprime.out");
    int N;
    in>>N;
    v[0].push_back(0);

    for (int n = 1; n <= N; n++) {
        int m = v[n-1].size();
        for (int j =0; j < m; j++) { 
            for (int i=1; i < 10; i++) { 
                if (isPrime(10*v[n-1][j]+i)) {
                    v[n].push_back(10*v[n-1][j]+i);
                }
            }
        }
    }
    int m = v[N].size();
    for (int i = 0; i < m; i++) 
        out<<v[N][i]<<endl;


    return 0;
}
