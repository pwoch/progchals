/*
ID: wochnow1
PROG: numtri 
LANG: C
*/

#include <stdio.h>
#define MAX 1010

int a[MAX][MAX];

int max(int a, int b) {
	return (a < b) ? b : a;
}

int main() {
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	int R;
	scanf("%d",&R);
	int i,j;
	for (i = 0; i < R; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for (i = R-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			a[i-1][j] = a[i-1][j] + max(a[i][j+1],a[i][j]);
		}
	}
	
	printf("%d\n",a[0][0]);
	return 0;
}
	


