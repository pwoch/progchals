
#include <iostream>
#include <cstring>

using namespace std;

int a[510][510];

int main() {

    int W, H, N, x1, x2, y1, y2;
    while (cin>> W>> H >>N) {
        if (!N && !W && !H) break;
        for (int i = 0; i < 510;i++) {
            for (int j = 0; j < 510; j++) {
                a[i][j] = -1;
            }
        }
        for (int i = 0; i < N; i++) {
            cin >>x1 >>y1 >>x2 >>y2;
            int X = max(x1,x2);
            int x = min(x1,x2);
            int Y = max(y1,y2);
            int y = min(y1,y2);
            for (int j = y; j <= Y; j++) {
                //store the end position of the region
                a[j][x] = max(a[j][x],X);
            }
        }
        int total = 0;
        for (int y = 1; y <= H; y++) {
            for (int x = 1,m = -1; x <= W; x++) {
                m = max(m,a[y][x]); 
                if (x>m) total++;
            }
        }
        switch(total){
            case(0):
                cout<<"There is no empty spots.\n";
                break;
            case(1):
                cout<<"There is one empty spot.\n";
                break;
            default:
                cout<<"There are "<<total<<" empty spots.\n";
                break;
        }
    }
    return 0;
}

             
