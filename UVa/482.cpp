#include <iostream>

using namespace std;

#define p pair<int,double>
#define f first
#define s second

vector<int> v(10000);

int main() {
    int N;
    int t;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    double tmp;
    for (int i = 0; i < N; i++)
