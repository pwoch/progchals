
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TILES 999
int factorial(int a);
int combinatorial(int n, int k);

int main(int argc,char* argv[]) {

    int bishopNumber = 0;
    scanf("%d", &bishopNumber);
    
    int differenceCoord[2*TILES];
    int sumCoord[2*TILES];
    int xPos, yPos;
    int difference, sum;
    int i;
    
    for (i = 0; i < 2*TILES; i++){
    
   		differenceCoord[i] = 0;
   		sumCoord[i] = 0;
   	}
   	
    for (i = 0; i < bishopNumber; i++) {
    	
    	scanf("%d %d", &xPos, &yPos);
    	
 		difference = xPos - yPos + (TILES);
 		
 		sum = xPos + yPos - 2;
 		
 		differenceCoord[difference]++;
 		printf("Changing index %d to value %d\n", difference, differenceCoord[difference]);
 		sumCoord[sum] = sumCoord[sum] + 1;
 		
 		
 	}
 	
 	int result = 0;
 	for (i = 0; i < 2*TILES ; i++) {
 		
 		if( differenceCoord[i] >= 2){
 			printf("diff Check for index  %d\n", i);
 			printf("diff array has value %d at index %d\n", differenceCoord[i],i);
 			result = result + combinatorial(differenceCoord[i],2);
 		}	
 		
 		if( sumCoord[i] >= 2) {
 			printf("sum Check for index  %d\n", i);
 			result = result + combinatorial(sumCoord[i], 2);
 		}
 	}
 	printf("%d\n", result);
 	
 	return EXIT_SUCCESS;
}

int factorial(int n) {

	if( n <= 1){
		
		return 1;
	} else {
		
		return n*factorial(n-1);
		
	}
}

int combinatorial(int n, int k) {

	printf("%d Choose %d\n", n, k);
	
	int result = 1;
	int factN = factorial(n);
	
	int factNK = factorial(n-k);
	int factK = factorial(k);
	printf("%d! = %d\n%d! = %d\n%d! = %d\n", n, factN, (n-k), factNK, k, factK);
	
	printf("%d! * %d! = %d\n", factNK, factK, factNK*factK);
	
	result = (factNK*factK);
	
	printf("%d\n", result);
	
	result = factN/result;
	
	printf("Returning: %d\n", result);
	return result;
}

	
