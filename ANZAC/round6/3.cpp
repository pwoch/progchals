

#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;

#define EPS 0.00000001
#define is_not_compare(x) ((strcmp(x,">") != 0) || (strcmp(x,"<") != 0) || (strcmp(x, "<=") != 0) || strcmp(x,"=") || strcmp(x,">="))


int main() {

    map<string, double> m;

    int N, G;
    cin>> N>> G;
    string name;
    double percent;
    double result, guess;
    for( int i = 0; i < N; i++) {
        cin>> name>> percent;
        m[name] = percent;
    }

    char str[5000];
    for (int i = 0; i < G; i++) {
        scanf("%s", str);
        while( !is_not_compare(str)){
            scanf("%s", str);
            if( strcmp(str,"+") == 0) continue;
            result += m[str];
        }
        scanf("%lf", &guess);
        printf("%lf %s %lf\n",result, str, guess); 
    }


    return 0;
}


