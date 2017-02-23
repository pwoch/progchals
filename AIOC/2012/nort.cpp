#include <fstream>
using namespace std;

int main() {
    ifstream in ("nortin.txt");
    ofstream out ("nortout.txt");
    int n, m;
    in>> n>> m;
    int result = (n*m%2) ? (n*m-1) :n*m;
    out<<result;
    return 0;
}
