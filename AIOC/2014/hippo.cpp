
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1010
using namespace std;


int main() {

    ifstream in ("hippoin.txt");
    ofstream out ("hippoout.txt");

    int N, H, F;
    in >>N>>H>>F;
    int a[MAX];
    for (int h = 0; h < H; h++) {
        in>> a[h];
    }

    vector< int> diff(MAX, 0);
    int b1, b2;
    //Tulips to the left of first and right of last hippo
    b1 = max(a[0] - 1, N-a[H-1]);
    b2 = min(a[0] - 1, N-a[H-1]);

    for (int i = 0; i < H-1; i++) {
        diff[i] = a[i+1] - a[i] - 1;
    }
    sort(diff.begin(), diff.end(), greater<int>());

    int used1 = 0, used2 = 0;
    int total = 0;
    int f, i;
    for (f = F, i = 0; f > 1 && i < H-1; f--) {
        //if we havent used either of the boundaries
        if (!used1 && diff[i] < b1) {
            used1 = 1;
            total += b1;
        } else if (!used2 && diff[i] < b2) {
            used2 = 1;
            total += b2;
        } else if (f != 1) {
            total += diff[i++];
            f--;
        }
    }
    //if we have one fence left over and not used the edge fences
    if (!(used1 || used2) && f == 1) {
        if (!used1){
            total += b1;
        } else {
            total += b2;
        }
    }
    out<< total<< endl;
}



