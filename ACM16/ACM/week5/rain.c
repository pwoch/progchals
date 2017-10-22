

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define EPS 0.00001

int main(){

    
    double diam, height, drink, rain;
    scanf("%lf %lf %lf %lf", &diam,&height, &drink, &rain);
    
    diam = pow(diam,2);

    double d = 4*drink/(M_PI*diam)- rain; 
    if( d < height*EPS){
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("%.12f\n", height/d);

    }
    return EXIT_SUCCESS;
}
