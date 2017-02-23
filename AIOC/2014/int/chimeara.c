

#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
char getLowest(int lC,int sC,int gC,int i);
int getLowestNum(int lC, int sC, int gC);
char L[MAX], G[MAX], S[MAX];


int main() { 
	freopen("chimin.txt","r",stdin);;
	freopen("chimout.txt","w",stdout);;
	int n, i;
	scanf("%d", &n);
	scanf("%s %s %s",L, S, G);
	int lC=0, sC=0, gC=0;	
	for (i = 0; i < n; i++) {
		char c = getLowest(lC,sC,gC,i);
		//printf("%c %c %c\n",L[i],S[i],G[i]);
		if( L[i] == c) lC++;
		if( S[i] == c) sC++;
		if( G[i] == c) gC++;
		//printf("L: %d\nS: %d\nG: %d\n\n",lC, sC, gC);
	}
	printf("%d\n",getLowestNum(lC,sC,gC));
	return 0;
}
int getLowestNum(int lC, int sC, int gC) {
	if( lC < sC) {
		return (lC < gC) ? lC : gC;
	} else {
		return (sC < gC) ? sC : gC;
	}
}

char getLowest(int lC,int sC,int gC,int i) {
	char p = L[i]; 
	int min = MAX;
	if (lC <= min) {
		min = sC;
		p = L[i];
	}
	if (sC <= min) {
		min = sC;
		p = S[i];
	}
	if (gC <= min) {
		min = gC;
		p = G[i];
	}
	//printf("Lowest is %d: %c\n",min, p);
	return p;
}

