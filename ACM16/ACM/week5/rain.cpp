

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(){

    
    int diam, height, drink, rain;
    scanf("%d %d %d %d", &diam,&height, &drink, &rain);
    diam = pow(diam,2);
    double c = height/((4*drink/(M_PI)*diam)- rain);
    if(c < 0 ){
        std::cout << "NO"<<'\n';
    } else {
        std::cout << "YES" << std::endl;
        std::cout << c<<'\n';

    }
    return EXIT_SUCCESS;
}
