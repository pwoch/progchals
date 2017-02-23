#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int factorOutTwosAndThrees( int a);


int main(){
 
 
   int max = 0;
   scanf("%d",&max);

   int bids[max];
   int j;
   
   int check = 1;
   
   
   for(j = 0; j < max; j++){
   		scanf("%d",&bids[j]);
   	}	
   	
   
   int reduced[max];
   
   for(j = 0; j < max; j++){
   		
   		reduced[j] = factorOutTwosAndThrees(bids[j]);
   	
   	}
   	
   	
   	for(j = 0; j < max - 1; j++){
   		
   		if(reduced[j] != reduced[j+1]){
   		
   			check = 0;
   		}
   	}
   	
   	   
   	   
   if(check){
   	printf("Yes\n");
   }else{
   	printf("No\n");
   }
   
   
	return EXIT_SUCCESS;
}


             
int factorOutTwosAndThrees(int n) {
    
    while( n%2 == 0)
    	n = n/2;
        
    while( n%3 == 0)
    	n = n/3;
        
    return n;   
}
