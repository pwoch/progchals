#include <iostream>
#include <vector>
using namespace std;

int nodes[100020][11];

int c = 0;

int main() {

    int T, N;
    cin>>T;
    for (int t=0; t<T; t++) {
        cin >>N;
        for (int i=0; i<100020; i++) {
            for (int j=0; j<11; j++) {
                nodes[i][j] = -1;
            }
        }
        c = 0;
        bool flag = true;
        for (int i=0; i<N; i++) {
            string a;
            cin >>a;
            bool ok = false;
            int curr = 0;
            //cout<<a<<endl;
            for (int k=0; k<a.size() && flag; k++) {
                int n = a[k]-'0';
                //if a number ends on the path its wrong
                if (nodes[curr][10] != -1) {
                    ok = false;
                    break;
                }
                //if we need to branch off then it is successful
                if (nodes[curr][n] == -1) {
                    //cout<<n<<" diverged"<<endl;
                    nodes[curr][n] = ++c;
                    ok = true;
                }
                curr = nodes[curr][n];
            }
            nodes[curr][10] = 1;
            if (!ok) flag = false;
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}

