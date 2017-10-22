#include <stdio.h>

int main() {
    char s[500001];
    scanf("%s",s);
    int i,t=0;
    char p = '0';
    for (i=0; s[i] != '\0'; p=s[i++]) {
        if (s[i] < p) t++;
    }
    printf("%d\n",t+1);
    return 0;
}


