#include <fstream>

using namespace std;

#define MAX 101000

int park[MAX], v[MAX];

ifstream in("slicein.txt");
ofstream out("sliceout.txt");

int main() {
    int N;
    in>> N;
    for (int i = 0; i <= N+1; i++) park[i] = 0;
    park[0] = 1, park[N+1] = 1;

    for (int n = 1, tmp; n <= N; n++) {
        in >> tmp;
        v[tmp] = n;
    }
    int total = 1;
    int ans = 1;
    for ( int n = 1; n <= N; n++) {
        //out << park[v[n]-1] <<" "<< v[n]<<" "<<park[v[n]+1]<<endl;
        if ( park[v[n]+1] && park[v[n]-1]) {
            total--;
        } else if (!(park[v[n]+1] || park[v[n]-1])) { 
            total++;
        }
        ans = max(ans, total);
        park[v[n]] = 1;
    }
    out<< ans<<endl;
    return 0;
}



  

