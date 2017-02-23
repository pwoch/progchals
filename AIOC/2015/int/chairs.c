#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define isValid(d,w,W,N) (d + ((w >= W) ? W : w) == N)

int main() {
	freopen("chairsin.txt","r",stdin);
	freopen("chairsout.txt","w",stdout);
	int C, N, W;
	scanf("%d %d %d", &C, &N, &W);
	char a[MAX];
	scanf(" %s",a);
	int l, r, dryS, wetS, dist, min;
	min = dist = C;
	l = r = 0;
	dryS = wetS = 0;

	//keep looping through either while r is not at the end or the current config is valid
	while( r != C || isValid(dryS,wetS,W,N) ) {
		//increment until right is valid
		while( r != C && !isValid(dryS,wetS,W,N)) {
			if( a[r] == 'd') dryS++;
			else if( a[r] == 'w') wetS++;
			r++;
		}
		//printf("l = %d, r = %d\n", l, r-1);
		//printf("dist: %d wetS: %d dryS: %d\n", r-l, wetS,dryS);

		dist = r - l;
		if( dist < min){
			//printf("New min from %d to %d: %d\n", l, r, dist);
			min = dist;
		}

		//increment left by one 
		//while( ((dryS + ((wetS >= W) ? W : wetS) == N))) {

		if( a[l] == 'd') dryS--;
		else if( a[l] == 'w') wetS--;
		l++;

		//}
	}

	printf("%d\n", min);
	return EXIT_SUCCESS;
}



