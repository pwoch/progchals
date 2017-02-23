#include <stdio.h>
#include <string.h>

#define MAX 1000010
#define min(a,b) ((a<b) ? a : b)

int main() {
	int a[MAX];
	int b[MAX];
	memset(a,0,sizeof(int)*MAX);

	freopen("alienin.txt","r",stdin);
	freopen("alienout.txt","w",stdout);

	int i,n,w,p,j;
	scanf("%d %d",&n, &w);
	int oldP = 1;
	int end;
	for (i = 0; i < n; i++) {
		scanf("%d",&p);
			for (j=oldP; j < p; j++){ 
				a[j] = i;
			}
		oldP = p;
		a[p] = i+1;
		end = p;
		b[i] = p;
	}
	int r, m = 0;
	for (i = 0; i <n; i++) {
//		printf("%d: %d, %d to %d ",b[i], a[b[i]],b[i], min(b[i]+w-1,end));
		r = a[min(b[i]+w-1,end)] - a[b[i]] + 1;
		m = (r > m) ? r : m;
	}
	printf("%d\n",m);
	return 0;
}


