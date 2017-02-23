
/*
ID: wochnow1
PROG: wormhole 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 12


typedef struct _pair{
    long long x;
    long long y;
}pair;

    
int partner[MAXN+1] = {0};
pair arr[MAXN + 1];
int adjMat[2*MAXN][2*MAXN] = {{0}, {0}};



int loopExists(int N) {
    
    int i, j;
    /*
    printf("Pairing is: \n");
    for( i = 1; i <= N; i++){
        printf("%d:%d ", i, partner[i]);
    }
    printf("\n");
    */


    int a[2*MAXN][2*MAXN];
    for( i = 0; i < 2*MAXN; i++) {
        for( j = 0; j < 2*MAXN; j++) {
            a[i][j] = adjMat[i][j];
        }
    }  
   
    //Generate the links due to wormholes
    for( i = 1; i <= N; i++) {
        a[2*i-1][2*partner[i]-2] = 1;
    }
/*
    //print the matrix 
    for( i = 0; i < 2*N; i++) {
        for( j = 0; j < 2*N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/

  
    //determine if cycle exists using powers of adjacency matrix
    int b[2*MAXN][2*MAXN];
    int n;
    for( i = 0; i < 2*N; i++) {
        for( j = 0; j < 2*N; j++) {
            b[i][j] = a[i][j]; 
        }
    }

    int r[2*MAXN][2*MAXN];
    int result, k;
    for( n = 1; n < N; n++) {
        //printf("Power = %d\n", n+1);

        for( i = 0; i < 2*N; i++) {

            for( k = 0; k < 2*N; k++) {
                result = 0;
                for( j = 0; j < 2*N; j++) {
                    result += a[i][j]*b[j][k];
                }
                //printf("%d-th & %d-th entry is %d\n",i,k, result);
                r[i][k] = result;
            }
        }
        /*
        //print the matrix
        for( i = 0; i < 2*N; i++) {

            for( j = 0; j < 2*N; j++) {
                printf("%d ", r[i][j]);
            }
            printf("\n");
        }
        printf("\n");
*/
        for( i = 0; i < 2*N; i++) {
            for( j = 0; j < 2*N; j++) {
                b[i][j] = r[i][j];
                if( i == j && r[i][j] != 0) {
                    return 1;
                }
            }
        }

    }

    //printf("\n\n");
    return 0;

}

int solution(int N) {
    int i, j, total = 0;

    // Find first wormhole which we have not paired yet
    for( i = 1; i <= N; i++){ 
        if( partner[i] == 0)
            break;
    }

    //Base Case: If we've paired all the wormholes print them out,
    // return 1 if the pairing results in a loop
    if( i > N) {
        if( loopExists(N) ) return 1;
        else return 0;

    }

    //Find a partner for j
    for( j = i+1; j <= N; j++) {
        if( partner[j] == 0) {
            //pair up i and j
            partner[j] = i;
            partner[i] = j;
            //Recurse to generate all possible pairings with these two pairs
            total += solution(N);

            //Pair i with a different partner and repeat
            partner[i] = 0;
            partner[j] = 0;
        }
    }
    return total;
}







int main() {

    FILE* inFile = fopen("wormhole.in","r");
    FILE* outFile = fopen("wormhole.out","w");

    int N;
    fscanf(inFile, "%d", &N);
    int i;
    for( i = 1; i <= N; i++) {
        fscanf(inFile, "%lld %lld", &arr[i].x, &arr[i].y);
    }
    fclose(inFile);

    pair tmp;
    int j;
    int closestRight[MAXN+1] = {0};
    for( i = 1; i <= N; i++) {
        tmp = arr[i];
        for( j = 1; j <= N; j++) {
            //If arr[i] is to the right of arr[j]
            if( tmp.y == arr[j].y && tmp.x < arr[j].x) {
/*
    //print the matrix 
    for( i = 0; i < 2*N; i++) {
        for( j = 0; j < 2*N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/

                if( closestRight[i] == 0 || 
                        ((arr[j].x-arr[i].x) < arr[closestRight[i]].x-arr[i].x)) {
                    closestRight[i] = j;
                }

            }
        }
    }

    for( i = 1; i <= N; i++) {            
        if( closestRight[i] != 0){
            adjMat[2*i-2][2*closestRight[i]-1] = 1;
        }
    }


    int answer = solution(N);
    printf("Total pairings %d\n", answer);
    fprintf(outFile,"%d\n", answer);
    fclose(outFile);

    return 0;
}
