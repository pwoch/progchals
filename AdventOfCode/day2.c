#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define isLegit(x,y) (abs(x) + abs(y) <=2)

int main() {

	char a[100000];
	int i, l, x = -2,y = 0;
	char c[5]['5'] = {{'0','0','1','0','0'},{'0','2','3','4','0'},{'5','6','7','8','9'},{'0','A','B','C','0'},{'0','0','D','0','0'}};
	
	while (scanf("%s",a) == 1) {
		l = strlen(a);
		for ( i = 0; i < l; i++) {
			switch(a[i]) {
				case('U') :
					if (isLegit(x,y-1)) y--;
					break;
				case('R') :
					if (isLegit(x+1,y)) x++;
					break;
				case('D') :
					if (isLegit(x,y+1)) y++;
					break;
				case('L') :
					if (isLegit(x-1,y)) x--; 
					break;
			}
		}
		printf("x=%d, y=%d, %c\n",x,y,c[y+2][x+2]);
	}
	printf("\n");
	return 0;
}
