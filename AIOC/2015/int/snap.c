#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	freopen("snapin.txt","r",stdin);
	freopen("snapout.txt","w",stdout);
	int R,C;
	int rX, rY,sX, sY;
	scanf("%d %d", &R, &C);
	scanf("%d %d %d %d", &rX, &rY, &sX, &sY);
	int dX = abs(rX - sX);
	int dY = abs(rY - sY);
	if( (dX + dY)%2) 
		printf("ROSE\n");
	else 
		printf("SCARLET\n");
	
	return 0;
}
