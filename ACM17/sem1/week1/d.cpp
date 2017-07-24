
#include <iostream>
#include <vector>

#define MAX 101


int a[MAX][MAX]
i

int main() {
	int T, N, M;
	cin >>T;
	for (int t=0; t<T; t++) {
		cin >>N >>M;
		for (int r=1; r<=N; r++) {
			for (int c=1; c<=N; c++) {
				a[r][c]='.';
			}
		}
		int offset = 2-N;
		for (int m=1; m<=M; m++) {
			int r,c;
			cin >>a[r][c];
			if (a[r][c] == 'x') {
				row.add(r);
				col.add(c);
			} else if (a[r][c] == '+') {
				diag.add(r+c+offset)
				diag.add(r-c+offset)
			}
	}

