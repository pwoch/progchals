#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


int main() {
	freopen("chairsin.txt","r",stdin);
	freopen("chairsout.txt","w",stdout);
	int C, N, W;
	scanf("%d %d %d", &C, &N, &W);
	char a[MAX];
	scanf(" %s",a);
	int l, r, dryS, wetS, dist, min;
	min = dist = 0;
	l = r = 0;
	dryS = wetS = 0;
	while( r != C) {
		//increment until right is valid
		while( dryS + ((wetS >= W) ? W : wetS) < N) {
			r++;
			if( a[r] == 'd') dryS++;
			else if( a[r] == 'w') wetS++;
		}

		dist = r - l + 1;
		if( dist < min) min = dist;

		//increment left until invalid
		while( dryS + ((wetS >= W) ? W : wetS) == N) {
			l++;
			if( a[l] == 'd') dryS--;
			else if( a[l] == 'w') wetS--;
		}
	}

	printf("%d\n", min);
	return EXIT_SUCCESS;
}



