#include <stdio.h>
#include <stdlib.h>


void merge( long long arr[], long long p, long long q, long long r) {

    //find the number of items in each section
    long long n1, n2;
    //Left subarray starts from index p and finishes at index q, so has size q - p
    n1 = q - p;
    //Right subarray starts from index q+1 and finishes at index r, so has size r-q+1
    n2 = r - q + 1;

    //seperate the two subarrays long longo their own array so that we can manipulate the first array
    long long* L = malloc(sizeof(long long)*n1);
    long long* R = malloc(sizeof(long long)*n2);
    long long i, j, k;
    for( j = 0; j < n1; j++) {
        L[j] = arr[p+j];
    }

    for( k = 0; k < n2; k++) {
        R[k] = arr[q+k];
    }
    
    for( i = p, k = 0, j = 0; i <= r; i++) {
        if( j >= n1 ) {
            arr[i] = R[k];
            k++;
        } else if( k >= n2) {
            arr[i] = L[j];
            j++;
        } else {
            if( L[j] < R[k]) {
                arr[i] = L[j];
                j++;
            } else {
                arr[i] = R[k];
                k++;
            }
        }
    }
   free(L);
    free(R);

}

void mergeSort( long long arr[], long long p, long long r) {

    if( p < r) {
        long long mid = (p+r)/2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid+1, r);
        merge(arr,p,mid+1,r);
    }
}

FILE* in;

int  main() {

    in = fopen("D-large-practice.in","r");

    long long t, T;
    
    fscanf(in,"%lld", &T);
    long long N, i, sz,j,k;
    long long* psums;
    long long* new;
    long long tmp, sum;
    long long l, r;
    long long q, Q;
    for( t = 0; t < T; t++) {

        fscanf(in,"%lld", &N);
        fscanf(in, "%lld", &Q);
        psums = malloc(sizeof(long long)*N);
        for( i = 0; i < N; i++) {
            fscanf(in,"%lld", &psums[i]);

        }

        sz = (N*(N+1))/2;
        new = malloc(sizeof(long long)*sz); 
        k = 0;
        for( i = 0; i < N; i++) {
            sum = 0;
            for( j = i; j < N; j++) {
                sum+= psums[j];
                new[k] = sum;
                k++;
            }
        }

        mergeSort(new, 0, sz-1);

        long long* ps = malloc(sizeof(long long)*sz);
        ps[0] = new[0];

        for( i = 1; i < sz; i++) {
            ps[i] = ps[i-1] + new[i];
        }
                
        printf("Case #%lld:\n", t+1);
        for( q = 0; q < Q; q++) {
            fscanf(in,"%lld %lld", &l, &r);
            l--;
            r--;
            if( l == 0) {
                printf("%lld\n", ps[r]);
            } else {
                printf("%lld\n",ps[r] - ps[l-1]);
            }
        }
        free(psums);
        free(new);
        free(ps);
    }

    return 0;
}

