#include <fstream>

using namespace std;

ifstream in("savein.txt");
ofstream out("saveout.txt");

int main() {
    int n;
    in>> n;
    int tmp, total = 0, n3 = 0, n4 = 0;
    for (int i = 0; i < n; i++) {
        in >>tmp;
        total += tmp;
        total -= tmp%5;
        if (tmp%5 == 3) n3++;
        if (tmp%5 == 4) n4++;
    }
    int m = min(n3,n4);
    n3 -= m;
    n4 -= m;
    total += 5*m;
    total += 5*(n3/2);
    n3 = n3%2;
    total += 10*(n4/3);
    n4 = n4%3; 
    if (n4) total += 5*n4;
    if (n3) total += 5;
    out<< total<<endl;
    return 0;
}
