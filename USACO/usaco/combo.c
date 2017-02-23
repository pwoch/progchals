

/*
ID: wochnow1
PROG: combo 
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct _lock{
    int a, b, c;
}lock;

void recurse(lock l, lock j, int b, int c); 
void compare(int a,int b,int c,lock l, int d,int e);

int  count = 0;

int main() {

    FILE* inFile = fopen("combo.in","r");
    FILE* outFile = fopen("combo.out","w");

    int N;
    lock j, m;
    fscanf(inFile,"%d", &N);
    int i;
    fscanf(inFile,"%d", &j.a);
    fscanf(inFile,"%d", &j.b);
    fscanf(inFile,"%d", &j.c);
    fscanf(inFile,"%d", &m.a);
    fscanf(inFile,"%d", &m.b);
    fscanf(inFile,"%d", &m.c);

    int combos = ( N > 4)? 5 : N;

    int lim = combos/2;

    if( j.a <= lim) {
        j.a += (N-lim);
    } else {
        j.a -= lim;
    }
    if( j.b <= lim) {
        j.b += (N-lim);
    } else {
        j.b -= lim;
    }
    if( j.c <= lim) {
        j.c += (N-lim);
    } else {
        j.c -= lim;
    }
    if( m.a <= lim) {
        m.a += (N-lim);
    } else {
        m.a -= lim;
    }
    if( m.b <= lim) {
        m.b += (N-lim);
    } else {
        m.b -= lim;
    }
    if( m.c <= lim) {
        m.c += (N-lim);
    } else {
        m.c -= lim;
    }


    recurse( m, j, N, combos);



    printf("Distinct combos %d\n", 2*combos*combos*combos -count);
    fprintf(outFile,"%d\n", 2*combos*combos*combos - count);
    
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void compare(int a,int b,int c,lock j, int N, int M) {

    int k, n, i;
    int tA, tB, tC;

    for( i = 0; i < M; i++) {
        /*if( a > (N-i)) {
            a = a%(N-i);
        }*/

        for( k = 0; k < M; k++) {
           /* if( b > (N-k)) {
                b = b%(N-k);
            }*/

            for( n = 0; n < M; n++) {
               /* if( c >(N-n)) {
                    c = c%(N-n);
                }*/
                tA = a + i;
                tB = b + k;
                tC = c + n;
                if( tA > N) {
                    tA = tA%N;
                }
                if( tB > N) {
                    tB = tB%N;
                } 
                if( tC > N) {
                    tC = tC%N;
                }
                //printf("Comparing %d %d %d to %d %d %d\n", tA, tB, tC, j.a, j.b, j.c);
                if( j.a == (tA) && j.b == tB && j.c == tC ){
                    printf("Overlapping unlock combo\n");
                    printf("%d %d %d\n\n", tA, tB, tC);
                    count++;
                }
                
                
            }
        }
    }

}
void recurse(lock l, lock j, int N, int M) {


    int k, n, i;
    lock t;

    for( i = 0; i < M; i++) {
        /*if( l.a > (N-i)) {
            l.a = l.a%(N-i) - i;
        }
        */

        for( k = 0; k < M; k++) {
            /*if( (l.b) > (N-k)) {
                l.b = l.b%(N-k) - k+1;
            }
            */

            for( n = 0; n < M; n++) {
                /*if( l.c > (N-n)) {
                    l.c = l.c%(N-n) - n+1;
                }
                */

                t.a = l.a+i;
                t.b = l.b+k;
                t.c = l.c+n;
                if( t.a > N) {
                    t.a = t.a %N;
                }
                if( t.b > N) {
                    t.b = t.b % N;
                }
                if( t.c > N) {
                    t.c = t.c % N;
                }

                printf("Comparing %d %d %d\n", t.a, t.b, t.c);

                compare( j.a, j.b, j.c, t,N, M);
            }
        }
    }

}




