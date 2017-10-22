
#include <iostream>
#include <vector>

#define MAX 101

using namespace std;
struct piece {
    int x,y;
    char a;
};

char orig[MAX][MAX];
int bish[MAX][MAX];
int rook[MAX][MAX];
int row[MAX];
int col[MAX];
int diff[2*MAX];
int sum[2*MAX];

int main() {
    int T, N, M;
    cin >>T;
    for (int t=0; t<T; t++) {
        int pts=0;
        cin >>N >>M;
        for (int r=1; r<=N; r++) {
            row[r]=0;
            col[r]=0;
            for (int c=1; c<=N; c++) {
                rook[r][c]=bish[r][c]=0;
                orig[r][c]='.';
            }
        }
        for (int n=0; n<2*N-3; n++) {
            diff[n]=0;
            sum[n]=0;
        }
        //Offset to zero index the diagonal arrays
        int o1= N-2;
        int o2= -3;

        for (int m=1; m<=M; m++) {
            int r,c;
            char tmp;
            cin >>tmp>>r>>c;
            orig[r][c]=tmp;
            pts++;
            if (tmp == 'x') {
                rook[r][c]=1;
                row[r]=1;
                col[c]=1;
            } else if (tmp == '+') {
                bish[r][c]=1;
                diff[r-c+o1]=1;
                sum[r+c+o2]=1;
            } else if (tmp == 'o') {
                rook[r][c]=1;
                row[r]=1;
                col[c]=1;
                bish[r][c]=1;
                diff[r-c+o1]=1;
                sum[r+c+o2]=1;
                pts++;
            }
        }

        int found,tmpR,tmpC;
        int n=0;
        found=tmpR=tmpC=0; 
        //Place all the extra rooks (try to place queens as often as possible)
        for (int c=1;c<=N;c++) {
            if (col[c]) continue;
            for (int r=1; r<=N; r++) {
                if (row[r]) continue;
                found=1;
                tmpR=r;
                tmpC=c;
                if (!(sum[r+c+o2] || diff[r-c+o1])) break;
            }
            if (found) {

                row[tmpR]=1;
                col[tmpC]=1;
                rook[tmpR][tmpC]=1;
                n++;
                pts++;
                if (!(sum[tmpR+tmpC+o2] || diff[tmpR-tmpC+o1])) {
                    diff[tmpR-tmpC+o1]=1;
                    sum[tmpR+tmpC+o2]=1;
                    bish[tmpR][tmpC]=1;
                    pts++;
                } 
            }


        }
        //Place all the bishops
        //Check the diagonals starting at every row in the first column
        for (int start=N-1; start>1;start--) {
            int c=1;
            int r=start;
            found=0;
            while (!found&& (r<=N && c<=N)) {
                if (!(sum[r+c+o2] || diff[r-c+o1])) {
                    diff[r-c+o1]=1;
                    bish[r][c]=1;
                    sum[r+c+o2]=1;
                    found=1;
                    n++;
                    pts++;
                }
                r++;
                c++;
            }
        }

        //Check the diagonals starting at every column in the first row
        for (int start=N; start>=1;start--) {
            int c=start;
            int r=1;
            found=0;
            while (!found && (r<=N && c<=N)) {
                if (!(sum[r+c+o2] || diff[r-c+o1])) { 
                    diff[r-c+o1]=1;
                    bish[r][c]=1;
                    sum[r+c+o2]=1;
                    found=1;
                    n++;
                    pts++;
                }
                r++;
                c++;
            }
        }

        char a;
        
        if (N==1) {
            n = (orig[1][1] != 'o') ? 1 :0;
            pts = 2;
            printf("Case #%d: %d %d\n", t+1, pts, n);
            if (n) printf("o %d %d\n", 1, 1);
        } 
        /*
         * else {
            printf("Case #%d: %d %d\n",t+1, pts, n);
            for (int r=1; r<=N;r++) {
                for (int c=1;c<=N;c++) {
                    if (bish[r][c] && rook[r][c]) a='o';
                    else if (bish[r][c]) a='+';
                    else if (rook[r][c]) a='x';
                    else a='.';
                    if (a != orig[r][c]) printf("%c %d %d\n",a,r,c);
                }
            }
        }
        */
        else if (N <= 4) {
            printf("Case #%d: %d %d\n",t+1, pts, n-M);
            printf("Original\n");
            for (int r=1; r<=N;r++) {
                for (int c=1;c<=N;c++) {
                    printf("%c",orig[r][c]);
                }
                printf("\n");
            }

            printf("Result\n");
            for (int r=1; r<=N;r++) {
                for (int c=1;c<=N;c++) {
                    if (bish[r][c] && rook[r][c]) a='o';
                    else if (bish[r][c]) a='+';
                    else if (rook[r][c]) a='x';
                    else a='.';
                    printf("%c",a);
                }
                printf("\n");
            }
        }
    }
}




