
#include <fstream>
#define M 210

using namespace std;
int f(int, int, int);

int c[M][M];
int a[M]; 
    int N;

ifstream in("snapin.txt");
ofstream out("snapout.txt");

int main() {
    in >>N;
    if ( N > 105) return 0;
    for (int i = 0; i < M; i++) {
        for (int j = i; j <M;j++) {
            c[i][j] = -1;
        }
    }
    
    for (int i = 0; i < 2*N; i++) {
        in >> a[i];
    }

    out<< f(0,1,-1)<<endl;
    return 0;
}

int f(int i1, int i2, int top) {
    out << i1<<" "<<i2<<endl;
    if (i2 > N) {
        if ( i1 < N && a[i1] == a[top]) {
            return 1;
        } else {
            return 0;
        }
    } else if ( c[i1][i2] != -1) {
        return c[i1][i2];
    } else {
        if (top != -1) { 
            if (a[i1] == a[top]) {
                out<<"\tpair\n";
                c[i1][i2] = f(i2, i2+1,-1)+1;
                out<<"c["<<i1<<"]"<<"["<<i2<<"]"<<" = "<<c[i1][i2]<<endl;
                return c[i1][i2];
            } else if (a[i2] == a[top]) {
                out<<"\tpair\n";
                c[i1][i2] = f(i1,i2+1,-1)+1;
                out<<"c["<<i1<<"]"<<"["<<i2<<"]"<<" = "<<c[i1][i2]<<endl;
                return c[i1][i2];
            } 
        } 
        c[i1][i2] = max(f(i1,i2+1,i2),f(i2,i2+1,i1));
        return c[i1][i2];
    }
}


