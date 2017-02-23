#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE* fin = fopen("probein.txt","r");
    FILE* fout = fopen("probeout.txt","w");
    int wC, wR, lC, lR;
    int R, C;
    fscanf(fin,"%d %d", &R, &C);
    fscanf(fin,"%d %d %d %d", &wR, &wC, &lR, &lC);
    int Q, qR, qC;
    fscanf(fin,"%d", &Q);
    int i;
    for( i = 0; i < Q; i++) {
        fscanf(fin,"%d %d", &qR, &qC);
        int waterDist, lavaDist;
        waterDist = abs(qR - wR)  + abs(qC - wC);
        lavaDist = abs(qR - lR) + abs(qC - lC);
        if( lavaDist > waterDist) { 
            fprintf(fout,"WATER\n");
        } else if ( waterDist > lavaDist) {
            fprintf(fout,"LAVA\n");
        } else {
            if( ((lC - lR) == (wC - wR)) || ((lC - wC) == (wR - lR))) {
                int bigLava = (abs(qR -lR) > abs(qC - lC)) ? abs(qR - lR) : abs(qC - lC);
                int bigWater = (abs(qR -wR) > abs(qC - wC)) ? abs(qR - wR) : abs(qC - wC);
                if( bigLava > bigWater) {
                    fprintf(fout,"WATER\n");
                } else if(bigWater > bigLava) {
                    fprintf(fout,"LAVA\n");
                } else {
                    fprintf(fout,"MOUNTAINS\n");
                }
            } else {
                fprintf(fout,"MOUNTAINS\n");
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
