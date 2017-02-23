


#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;



int main() {


    int size1, size2;
    int check;

    scanf("%d%d", &size1, &size2);

    int arr1[size1];
    int arr2[size2];

    int i;
    
  
    i = 0;
    while( i < size1){
        scanf("%d", &arr1[i]);
        i++;
    }

    i = 0; 
    while( i < size2) {
        scanf("%d", &arr2[i]);
        i++;
    }
    
    sort(arr1, arr1 + size1);
    i = 0;
    int max;
    while( i < size2) {

        max =  upper_bound(arr1, arr1 + size1,arr2[i]) - arr1;
        printf("%d ", max);
        i++;
    }
    printf("\n");
       
    return 0;
}
