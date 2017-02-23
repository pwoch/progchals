
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
	//l,r are which boundary
	//lP,rP are how big current patch is
	int i, N, l,r,lP,rP;
	int f[MAX];
	FILE* inf = fopen("farmin.txt","r");
	FILE* outf = fopen("farmout.txt","w");
	fscanf(inf,"%d",&N);
	for( i = 0; i < N; i++) {
		fscanf(inf,"%d",&f[i]);
	}
	l = 0;
	lP = f[l];
	r = N-1;
	rP = f[r];
	int remove = 0;
	while( l < r) {
		//printf("l: %d r: %d\nlP: %d rP: %d\nremove: %d\n\n",l,r,lP,rP,remove);
		if( lP > rP) {
			while( lP > rP) {
				f[r] = -1;
				remove++;
				while( r >= 0 && --r == -1);
				rP += f[r];
			}
		} else if (rP > lP) {
			while( rP > lP) {
				f[l] = -1;
				remove++;
				while(l < N && ++l == -1);
				lP += f[l];
				
			}
		} else {
			lP = f[++l];
			rP = f[--r];
		} 
	}
	//printf("l: %d r: %d\nlP: %d rP: %d\nremove: %d\n\n",l,r,lP,rP,remove);

	fprintf(outf,"%d\n", remove);
	return 0;
}



