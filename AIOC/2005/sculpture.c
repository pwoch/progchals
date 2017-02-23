#include <stdio.h>
#include <stdlib.h>
#define MAX 50001


int total = 0;
int recurse(int i);

typedef struct _branch{
    int l1;
	int w1;
	int l2;
	int w2;
}Branch;

Branch b[MAX];


int main() {
    int i, N; 
    FILE* fin = fopen("sculpin.txt","r");
    FILE* fout = fopen("sculpout.txt","w");
    fscanf(fin,"%d", &N);
	int l1, w1, l2, w2;
    for( i = 1; i <= N; i++) {
		fscanf(fin,"%d %d %d %d", &l1, &w1, &l2, &w2);
		b[i].l1 = l1;
		b[i].w1 = w1;
		b[i].l2 = l2;
		b[i].w2 = w2;
	}

	recurse(1);
	fprintf(fout,"%d\n", total);

	fclose(fin);
	fclose(fout);
	return 0;
}

int recurse(int i){
	if( b[i].l1 == 0 || b[i].l2 == 0) {
		return 0;
	}
	int lHeight = recurse(b[i].l1) + b[i].w1;
	int rHeight = recurse(b[i].l2) + b[i].w2;
	int diff = abs(rHeight - lHeight);
	total += diff;
	return (lHeight > rHeight) ? lHeight : rHeight;
}

