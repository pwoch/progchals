
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define TILES 999
#define MIN_SUM 2
int factorial(int a);
long long combinatorial(int n, int k);

int main(int argc,char* argv[]) {

    int bishopNumber = 0;
    scanf("%d", &bishopNumber);
    
    int differenceCoord[2*TILES + 1] = {0};
    int sumCoord[2*TILES + 1];
    int xPos, yPos;
    int difference, sum;
    int i;
    
    for (i = 0; i < 2*TILES + 1; i++){
    
   		differenceCoord[i] = 0;
   		sumCoord[i] = 0;
    }
   	
    for (i = 0; i < bishopNumber; i++) {
    	
    	        scanf("%d %d", &xPos, &yPos);
    	
 		difference = xPos - yPos + (TILES);
 		
 		sum = xPos + yPos - MIN_SUM;
 		
 		differenceCoord[difference]++;
 		sumCoord[sum] = sumCoord[sum] + 1;
 		
 		
    }
	
    long long result;
    result = 0;
   
    


    for (i = 0; i < 2*TILES + 1; i++) {
 	    
            if( differenceCoord[i] >= 2){
                        
 	    	result = result + combinatorial(differenceCoord[i],2);
 	    }	
 		
 	    if( sumCoord[i] >= 2) {
 	    	result = result + combinatorial(sumCoord[i], 2);
 	    }
    }

    int n = 1000;
    long long combination = combinatorial(n, 2);
    printf("%lld\n", result);
 	
    return EXIT_SUCCESS;
}

int factorial(int n) {
	if( n <= 1){
		return 1;
	} else {
		return n*factorial(n-1);
	}
}

long long combinatorial(int n, int k) {


        long long result = 1;
        long long counter = 1;
        long long i = (long long) n;
        long long nMinusK = i - (long long) k;

        while( i > nMinusK) {

            result = result*i;
            result = result/((long long)counter);
            i--;
            counter++;
        }
      	return result;
}

	
