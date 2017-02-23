
/*
ID: pwoch197
PROG: ride
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {

    FILE* fin = fopen("ride.in","r");
    FILE* fout = fopen("ride.out","w");

    char comet[8];
    char group[8];
    int codeA = 1;
    int codeB = 1;
    fscanf(fin, "%s %s", comet, group);

    int sizeA = strlen(comet);
    int sizeB = strlen(group);
    int i;
    for( i = 0; i < sizeA; i++){
        codeA = (codeA *(comet[i] - 'A' + 1))%47;
        //printf("%c %d %d\n", comet[i], comet[i] - 'A' + 1, codeA);
    }
    //printf("\n");

    for( i = 0; i < sizeB; i++){
        codeB = (codeB * (group[i] - 'A' + 1))%47;
        //printf("%c %d %d\n", group[i], group[i] - 'A' + 1, codeB);
    }

    if( codeA == codeB){
        //printf("GO\n");
        fprintf(fout,"GO\n");
    }else{
        //printf("STAY\n");
        fprintf(fout,"STAY\n");
    }
    fclose(fin);
    fclose(fout);

    return 0;
}
