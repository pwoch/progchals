#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in ("archin.txt");
    ofstream out ("archout.txt");

    int N, s1, s2;
    in >>N >>s1 >>s2;
    int b1 = s1 - 1, b2 = s2 -1;
    int w1 = N - s1, w2 = N - s2;
    int best = N - (w1 + w2);
    if (best < 1) best = 1;
    int worst = b1 + b2 + 1;
    if (worst > N) worst = N;
    out<<best <<" "<<worst<<endl;
    return 0;
}

