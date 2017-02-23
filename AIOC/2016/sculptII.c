#include <stdio.h>
#include <stdlib.h>

typedef struct _block{
	int h, end;
}block;

#define MAX 100000
#define MAX_WIDTH 1000001

int main() {
	block b[MAX];
	
	int n, N;
	FILE* inf = fopen("artin.txt","r");
	FILE* outf = fopen("artout.txt","w");
	fscanf(inf,"%d", &N);
	int i, t, time, width, height;
	int max = 0;
	b[0].h = 0;
	b[0].end = MAX_WIDTH;
	time = 0;
	for( i = 1,n  = 0; n < N; n++) {
		fscanf(inf,"%d %d %d",&time, &width, &height);
		while(b[i].end < time) i--;

		b[++i].end = (time-1) + width;
		b[i].h = b[i-1].h + height;
		if( b[i].h > max) max = b[i].h;
	}
	fprintf(outf,"%d\n", max);
	fclose(inf);
	fclose(outf);
	return 0;
}
