#include <stack>
#include <iostream>
#include <fstream>

#define MAX 1000001

using namespace std;

int main() {
    ifstream in ("shufflein.txt");
    ofstream out ("shuffleout.txt");

    int N, K;
    int a[MAX];
    stack<int> s;
    int minister[MAX];
    int tmp, min, i, pm;
    in >>N >>K;
    in >>tmp;
    min = tmp;
    a[tmp]--;
    for (i=1; i < K; i++) {
        in >>tmp;
        a[tmp]--;
    }
    for (i=0; i<=K; i++) {
        in >>tmp;
        minister[tmp] = i+1;
        a[tmp]++;
    }
    if (a[min] == 0) pm = minister[min];
    for (int j = 0; j < 2*N;j++) {
        i = j%N+1;
        if (a[i] == 1) {
            s.push(i);
            a[i] = 0;
        }
        if (a[i] == -1) {
            if (!s.empty()) {
                tmp = s.top();
                s.pop();
                a[i] = 0;
                if (i == min) pm = minister[tmp];
            }
        }
    }
    out<< pm<< endl<< minister[s.top()]<<endl;
    return 0;
}


