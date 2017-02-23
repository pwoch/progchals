#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {

	int a[9];
	int possible = 0;
	int stop = 0;
	int i;
	while (!stop) {
		for (i = 0; i < 9; i+=3) {
			if (scanf("%d %d %d\n",&a[i],&a[i+1],&a[i+2]) != 3) {
				stop = 1;
				break;
			}
		}
		for ( i = 0; i < 3 && !stop; i++) {
			if (a[i]>a[i+3]) {
				if ( a[i] > a[i+6]) {
					swap(&a[i],&a[i+6]);
				}
			} else {
				if ( a[i+3]> a[i+6]) {
					swap(&a[i+3],&a[i+6]);
				}
			}
			if (a[i]+a[i+3] > a[i+6]) possible++;
		}
	}

	printf("%d\n",possible);
	return 0;
}


