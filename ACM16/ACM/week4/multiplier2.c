// Paul Wochnowski
// Lucy Qiu
// 1/03/2016

#include <stdio.h>
#include <stdlib.h>
#define M 1000000007
#define SIZE 200000 

void go(int arr[], long long arr2[], int b, int c, long long d);

long long total = 1;
int indx = 0;

int main(int argc, char* argv[]) {

    int size, i;
    size = 0;
    
    scanf("%d", &size);
    
    int primeFactors[size];
    long long factors[SIZE] = {0};

    i = 0;
    while( i < size) {
        scanf("%d", &primeFactors[i]);
        i++;
    }
    go(primeFactors,factors,0,size,total);

    printf("%lld\n", total);

    return EXIT_SUCCESS;

}


void go( int arr[], long long factors[], int pos, int size, 
        long long result) {

    int i, j;
    long long update;  
    int duplicate = 0;
     
    i = pos;
    while(i < size){

        update = (result*arr[i])%M;
       
        for( j = 0; j < SIZE; j++) {
            if( factors[j] == update) {
                duplicate = 1;
                break;
            }
            if( factors[j] == 0){
                break;
            }
        }

        if( !duplicate ) {
            factors[indx] = update;
            indx++;
            total = (total*update)%M;
            go( arr,factors, i + 1, size, update);
            
        } else { 
            update = update/arr[i];
            i = size;
        }
        i++;
    }
}
