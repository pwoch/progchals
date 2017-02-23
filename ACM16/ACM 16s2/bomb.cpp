
#include <algorithm>
#include <iostream>
#include <cstdio>


using namespace std;
//char arr[1010][1010];
//int col[1010];
//int row[1010];

int main() {

    int N, M;
    scanf("%d %d",&N,&M);
    int x, y;
    char arr[N][M];
    int col[N];
    int row[M];


    for( y = 0; y < M; y++) 
        col[y] = 0;

    for( x = 0; x < N; x++) 
        row[x] = 0;

    int total = 0;
    for( x = 0; x < N; x++) { 
        for( y = 0; y < M; y++) { 
            scanf(" %c",&arr[x][y]);
            if( arr[x][y] == '*') {
                total++;
                col[y]++;
                row[x]++;
            }
        }
    }

    for( x = 0; x < N; x++) {
        for( y = 0; y < M; y++) {
            if( col[y] + row[x] - (arr[x][y]=='*') == total) {
                cout<< "YES"<<endl;
                cout<< x+1<<" "<< y+1<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}


