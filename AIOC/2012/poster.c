
#include <stdio.h>
#define MAX 1000007


int main() {
	freopen("postin.txt","r",stdin);
	freopen("postout.txt","w",stdout);
	int n, i, x, w,minStart, minEnd, minN;
	scanf("%d", &n);
	minStart = 0;
	minEnd = MAX;
	for ( i = 1; i <= n; i++) {
		scanf("%d %d",&x,&w);
		if (x <= minStart || x < minEnd) {
			minStart = x;
			minEnd = x + w;
			minN = i;
		}
	}
	printf("%d\n",minN);

	return 0;
}

