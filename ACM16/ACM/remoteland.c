



#include <stdio.h>
#include <stdlib.h>




int main() {
    int high = 10;
    int tar = binarySearch(1,high);

    printf("target is: %d\n", high);

    return EXIT_SUCCESS;
}



int binarySearch(int low, int target){
    int high = target;
    int mid;
    int result;

    while( (high -low) > 1){
        
        mid = (low+high)/2;
        printf("mid: %d\n", mid);
        if( mid*mid < target){
            low = mid+1;
        } else if (mid*mid > target){
            high = mid-1;
        }
        printf("mid: %d\n", mid);
    }

    result = mid;

    return result;
}


