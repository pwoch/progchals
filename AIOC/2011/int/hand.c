#include <stdio.h>
#include <stdlib.h>

int main() {
	freopen("handin.txt","r",stdin);
	freopen("handout.txt","w",stdout);
	int i,n, curr, N;
	scanf("%d %d %d",&n,&curr,&N);
	int from, to;
	for (i = 0; i < N; i++) {
		scanf("%d %d",&from, &to);
		if (from == curr) {
			curr = to;
		} else if (from < curr && curr <= to) {
			curr--;
		} else if (curr < from && to <= curr) {
			curr++;
		}
	}
	printf("%d\n",curr);
	

	return 0;
}

