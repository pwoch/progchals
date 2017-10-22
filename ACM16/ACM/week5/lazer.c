


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define EPS 0.00001

int main(){

    int N;
    double x0, y0;


    std::cin >> N >> x0 >> y0;
    printf("%f %f\n", x0, y0);
    long double tmp;
    std::vector<long double> gradient;
    int j = 0;
    int special = 0;
    long double tmpX, tmpY;
    int i = 0;

    while( i < N){
        scanf("%lf %lf", &tmpX, &tmpY);
        std::cout<<tmp<<std::endl;
        printf("%lf %lf\n", tmpX, tmpY);
        if( abs(tmpX - x0) < EPS){
            special = 1;
        } else {
            printf("%f %f\n", tmpX, tmpY);
            tmp = (tmpY - y0)/(tmpX - x0);
            printf("%lf\n",tmp);
            std::cout<<tmp<<std::endl;
            gradient.push_back(tmp);
            j++;
        }
        i++;
    }

    sort(gradient.begin(),gradient.end());

    int sum = 0;
    i = 1;


    if( j){
    sum = 1;
    tmp = gradient[0];

    while(i < j) {
        if( fabs(tmp - gradient[i]) > EPS){
            tmp = gradient[i];
            sum++;
            } 

        i++;
    }
    }

    printf("%d\n",sum+special);
    return EXIT_SUCCESS;
}



