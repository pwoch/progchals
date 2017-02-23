
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
int closestRight[MAXN+1] = {0};
pair arr[MAXN + 1];
int adjMat[2*MAXN][2*MAXN] = {{0}, {0}};



int loopExists(int N) {
    
    int i, j;
    int pos;
    for( i = 1; i <= N; i++){
        pos = i;
        for( j = 0; j < N; j++) 
            pos = closestRight[partner[pos]];

        if( pos != 0) 
            return 1;
    }
    return 0;
}    


int solution(int N) {
    int i, j, total = 0;

    // Find first wormhole which we have not paired yet
    for( i = 1; i <= N; i++){ 
        if( partner[i] == 0)
            break;
    }

    // Base Case: If we've paired all the wormholes print them out,
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
    for( i = 1; i <= N; i++) {
        tmp = arr[i];
        for( j = 1; j <= N; j++) {
            //If arr[i] is to the right of arr[j]
            if( tmp.y == arr[j].y && tmp.x < arr[j].x) {

                if( closestRight[i] == 0 || 
                        ((arr[j].x-arr[i].x) < arr[closestRight[i]].x-arr[i].x)) {
                    closestRight[i] = j;
                }

            }
        }
    }

   

    int answer = solution(N);
    printf("Total pairings %d\n", answer);
    fprintf(outFile,"%d\n", answer);
    fclose(outFile);

    return 0;
}
