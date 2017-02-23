#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int counter = 0;
char evac[1000];
int* generateArray(int size);
int getMax(int *p, int N);
int getSecMax(int *p, int N);
int getMin(int *p, int N);
void evacuate( int index);

int main(){

    int testN;
    scanf("%d", &testN);
    int i,j,k, N;
    int max, secMax, min;
    int *p;
    i = 0;
    while( i < testN) {
        scanf("%d", &N);
        p = generateArray(N);
        max = getMax(p, N);
        secMax = getSecMax(p,N);
        if( N > 2){
            min = getMin(p, N);
        }else{
            min = secMax;
        }
        int j = 0;
        while( p[max] - 2 >= p[secMax]){
            evacuate(max);
            evacuate(max);
            p[max]-=2;
            evacuate(-1);
        }
        if( p[max] - 1 == p[secMax]){
            evacuate(max);
            evacuate(-1);
        }
        while( p[max] > p[min] + 1) {
            evacuate(max);
            p[max]--;
            evacuate(secMax);
            p[secMax]--;
            evacuate(-1);
        }
        while( p[max] != 1){

            evacuate(min);
            p[min]--;
            evacuate(-1);
            evacuate(max);
            p[max]--;
            evacuate(secMax);
            p[secMax]--;
        }
        evac[counter] = '\0';
        printf("%s\n", evac);
        k = 0;
        j = strlen(evac);
        while( k <= j){
            evac[k] = ' ';
            k++;
        }
        free(p);
        i++;
    }

    return EXIT_SUCCESS;
}
void evacuate( int index){
    if(index == -1){
        evac[counter] = ' ';
    } else {
        evac[counter] = 'A' + index;
    }
    counter++;
}


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

int getSecMax(int *p, int N){
    int secMax, max,i;

    i = 0;
    max = 0;
    while( i < N){
        if( p[i] > max){
            secMax = max;
            max = i;
        }
        i++;
    }
    return secMax;
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
