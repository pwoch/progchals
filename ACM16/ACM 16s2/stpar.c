

#include <stdlib.h>
#include <stdio.h>

typedef struct _stack{
    int a[1000];
    int size;
}stack;


int main(){
    int n, i, success;
    scanf("%d",&n);
    int* arr = malloc(sizeof(int)*n);

    while(n != 0){
        for( i = 0;i<n; i++){
            scanf("%d",&arr[i]);
        }
        stack s;
        s.size = 0;
        success = 0;
        i = 0;
        int k = 0;
        while( success != n) {
            if( arr[i] == success+1){
                printf("%d\n",i);
                i = i+1;
                success = success+1;
            } else if (s.size != 0 && s.a[s.size] == success+1) {
                success = success+1;
                s.size--;
            } else {
                if( s.size != 0 && s.a[s.size] < arr[i]){
                    printf("no");
                    return 0;
                } else {
                    s.a[++s.size] = arr[i];
                    i++;
                }
            }
            for( k = 1; k <= s.size; k++)
                printf("%d", s.a[k]);
            printf("\n");

        }
        printf("yes");
        scanf("%d",&n);
    }
    return 0;
}


