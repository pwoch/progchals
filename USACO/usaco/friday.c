/*
ID: wochnow1
PROG: friday
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE* inFile = fopen("friday.in","r");
    FILE* outFile = fopen("friday.out","w");
    
    int N;
    fscanf(inFile,"%d", &N);
    int i, j;
    int freqs[7] = {0};
    int date = 0;
    freqs[date]++;
    int year = 1900;
    int m;

    for( i = 1; i < 12*N; i++) {
        m = i%12;

        if( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 ||
                m == 10 || m == 0) {
            date = date + 3;
        } else if( m == 4 || m == 6 || m == 9 || m == 11) {
            date = date + 2;
        } else {
            if( !(year%4) && (year%100) || !(year%400)){
                date = date + 1; 
            } else {
                date = date + 0;
            }
        }
        date = date%7;
        freqs[date]++;
        if( m == 0) {
            year++;
        }

    }
    for( i = 0; i < 7; i++){
        if( i != 6){
        fprintf(outFile,"%d ", freqs[i]);
        } else {
            fprintf(outFile,"%d\n", freqs[i]);
        }
    }


    fclose(inFile);
    fclose(outFile);

    return 0;
}

