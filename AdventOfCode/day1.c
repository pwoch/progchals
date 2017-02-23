
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	char dir;
	int curr,steps,x,y;
	curr = 4;
	x = 0;
	y = 0;
	int c = 1;
	while (1 ) {
		scanf(" %c%d",&dir,&steps);
		curr = (curr + 4+((dir == 'R') ? 1 : -1))%4;
	
		switch((curr+4)%4) {
			case(0) :
				y += steps;
				break;
			case(1) :
				x += steps;
				break;
			case(2) :
				y -= steps;
				break;
			case(3) :
				x -= steps;
				break;
		}
		scanf("%c",&dir);
		if (dir != ',') break;
	}
	printf("x: %dy: %d\n",x,y);
	printf("%d\n",abs(x)+abs(y));
	return 0;
}

