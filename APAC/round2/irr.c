


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.000000001



int main() {


    int t, T;

    scanf("%d", &T);

    for( t = 1; t <= T; t++) {

        int m;
        double c0, c1, c2;
        double r;
        double a, b, c;

        scanf("%d", &m);

        if( m == 1) {
            scanf("%lf %lf", &c0, &c1);
            c0*=-1;
            r = -(c0 + c1)/c0;
            //printf("r = %lf\n", r);
            
        } else if ( m == 2) {
            scanf("%lf %lf %lf", &c0, &c1, &c2);
            c0*=-1;
            a = -(2*c0+c1);
            printf("a = %lf\n", a);
            b = sqrt(c1*c1 - 4*c0*c2);
            printf("b = %lf\n", b);
            c = 2*c0;
            printf("c = %lf\n", c);
            printf("a+b/c = %lf\n", (a+b)/2*c0);
            printf("a-b/c = %lf\n", (a-b)/2*c0);
            if( abs((a+b)/2*c0)-1 < EPS) {
                
                r = (a+b)/2*c0;
            } else {
                r = (a-b)/2*c0;
            }
        }

        if( abs(r) < EPS) {
        //    r = 0;
        }

        printf("Case #%d: %lf\n", t, r);
    }
    return 0;
}





