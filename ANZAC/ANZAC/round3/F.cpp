



#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int n1, f1, f2, n2, d1, d2, n;

    cin>> n1>> f1>> d1>> n2>> f2>> d2;
    float k;
    int i, j;
    for( i = 0; i < n1; i++){
        cout<< f1 + d1*i<<", ";

    }
    cout<< endl;
    for( i = 0; i < n2; i++){
        cout<< f2 + d2*i<<", ";
    }
    cout<< endl;

    if( f1 < f2){
        k = ((f2 - f1)/(double)d1);
        i = (k+k+1)/2;
        //i = ((f2 - f1)/d1);
        cout<< "first sequence starts at "<< i<<endl;
        j = 0;
        n = min(n1,n2);
        while( j < n){
            cout<< f1 + d1*i<<"\t"<< f2 + d2*j<<endl;
            j++;
            i++;
        }
            
    } else {
        k =  ((f1 - f2)/(double)d2);
        k = (k+k+1)/2;
        i = (k+k+1)/2;
        //i = ((f1 - f2)/d2);
        cout<< "second sequence starts at "<< i<<endl;
        j = 0;
        n = min(n1,n2);
        while( j < n){
            
            cout<< f1 + d1*j<<"\t"<< f2 + d2*i<<endl;
            j++;
            i++;
        }
    }
    return 0;
}
    


