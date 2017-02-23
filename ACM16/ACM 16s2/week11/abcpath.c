
#include <stdio.h>
#include <stdlib.h>

int di[] = {-1,-1,-1,0,1,1,1,0};
int dj[] = {-1,0,1,1,1,0,-1,-1};
char graph[55][55];
int visited[27];

int main() {

	int t = 0;
	char input[51];
	int H, W;
	int i, j;
	while(1){ 
		scanf("%d %d", &H, &W);
		if( H == 0) break;
		for( i = 0; i < H; i++){
			scanf(" %s",input);
			for( j = 0; j < W; j++){
				graph[i][j] = input[j];
			}
		}

		//DFS starting at A
		for( i = 0; i < H; i++) {
			for( j = 0; j < W; j++){
				if( graph[i][j] == 'a') {
					length = dfs(i,j);
					if( length > max) {
						max = length;
					}
				}
			}
		}
		printf("Case %d: %d\n",++t, max);
	}
	return 0;
}

int dfs(int i, int j) {



}
