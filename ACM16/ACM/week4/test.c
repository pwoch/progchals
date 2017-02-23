// Paul Wochnowski
// Lucy Qiu
// 1/03/2016

#include <stdio.h>
#include <stdlib.h>
#define M 1000000007
#define SIZE 1000000 

void go(int arr[], int arr2[], int b, int c, long long d);

long long total = 1;
int indx = 0;

int main(int argc, char* argv[]) {

    int size, i;
    size = 0;
    
    scanf("%d", &size);
    
    int primeFactors[size];
    int factors[SIZE] = {0};

    i = 0;
    while( i < size) {
        scanf("%d", &primeFactors[i]);
        i++;
    }

    go(primeFactors,factors,0,size,total);

    printf("%lld\n", total);

    return EXIT_SUCCESS;

}


void go( int arr[], int factors[], int pos, int size, 
        long long result) {

    int i, j;
    long long update;  
    int duplicate = 0;
     
    i = pos;
    while(i < size){
        duplicate = 0;
        update = (result*arr[i])%M;
        
        for( j = 0; j < 2*size; j++) {
            if( factors[j] == (int) update) {
                duplicate = 1;
                break;
            }
            if( factors[j] == 0){
                break;
            }
        }

        if( !duplicate ) {
            factors[indx] = (int) update;
            indx++;
            total = (total*update)%M;
            
        } else { 
            update = update/arr[i];
        }
        go( arr,factors, i + 1, size, update);
        i++;
    }
}
