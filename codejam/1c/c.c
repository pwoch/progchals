#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){

    int test, N, min, max, mid;
    scanf("%d", &test);

    int i, j, k;
    while( i < test){
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        scanf("%d", &N);

        min = getMin( a, 3);
        mid = getMid( a, 3);
        max = getMax( a, 3);



}
    
int* generateArray(int size);
int getMax(int *p, int N);
int getMid(int *p, int N);
int getMin(int *p, int N);



int getMin(int *p, int N){
    int min,i, result;

    i = 0;
    min = p[0];
    while( i < N){
        if( p[i] < min){
            min = p[i];
            result = i;

        }
        i++;
    }
    return result;
}

int getMax(int *p, int N){
    int max,i, result;

    i = 0;
    max = 0;
    while( i < N){
        if( p[i] > max){
            max = p[i];
            result = i;
        }
        i++;
    }
    return result;
}

int getMid(int *p, int N){
    int mid, max,i;

    i = 0;
    max = 0;
    while( i < N){
        if( p[i] > max){
            mid = max;
            max = i;
        }
        i++;
    }
    return mid;
}


int* generateArray(int size){
    int *result = malloc(size*sizeof(int));
    int i;

    i = 0;
    while( i < size){
        scanf("%d", &result[i]);
        i++;
    }
    return result;
}

    return EXIT_SUCCESS;
}
