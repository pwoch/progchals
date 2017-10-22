#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200000

char o[MAX], t[MAX], save[MAX];
int a[MAX];
int N, M;

int is_substring(int m) {

    for (int i=0; i<m; i++) {
        int tmp = o[a[i]];
        o[a[i]] = save[i];
        save[i] = tmp;
    }

    //printf("is %s contained in %s: ", t, o);

    int c=0, i;
    char check = t[c];
    int found = 0;
    for (i=0; i<N; i++) {
        if (o[i] == check) {
            c++;
            if (c == M) {
                found=1;
                break;
            }
            check = t[c];
        }
    }

    for (int i=0; i<m; i++) {
        int tmp = o[a[i]];
        o[a[i]] = save[i];
        save[i] = tmp;
    }

    //printf("%s", found?"true\n":"false\n");
    return found;
}

int main() {
    int c;
    int i,n=0;
    for (i=0; i<MAX;i++) save[i]='.';
    scanf("%s",o);
    scanf("%s",t);
    N = strlen(o);
    M = strlen(t); 

    while (scanf(" %d",&c) != EOF) a[n++] = c-1;


    int lo=0, hi=N-M;
    while (lo < hi) {
        int m = lo + (hi-lo)/2;
        if (lo+1==hi) {
            if (is_substring(hi)) lo=hi;
            else hi=lo;
        } else {
            if (is_substring(m)) lo=m;
            else hi=m-1;
        }

    }
    printf("%d\n",lo);

    return 0;
}
