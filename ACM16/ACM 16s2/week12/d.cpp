#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int search(int a,int b);
bool g[26][26];
int P, M;
void precompute();

int main() {
	char S[1010];
	char T[1010];
	cin>> P;
	int i, t;
	int v1, v2;
	int result;

	for( t = 0; t < P; t++) {
		scanf("%s %s", S, T);
		scanf("%d", &M);
		for( int m = 0; m < M; m++){
			char c1, c2;
			scanf(" %c->%c",&c1, &c2);
			v1 = c1 - 'a';
			v2 = c2 - 'a';
			g[v1][v2] = 1;
		}

		precompute();
		result = 1;
		for( i = 0; S[i] != '\0'; i++) {
			if( S[i] == T[i]) continue;
			if( !g[S[i]-'a'][T[i]-'a']) {
				result = 0;
				break;
			}
		}
		if( result != 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		memset(g,0,sizeof(g));
	}	
	return 0;
}
void precompute() {
	queue<int> q;
	vector<bool> v(26,0);
	for( int i = 0; i < 26; i++) {
		q.push(i);
		while(!q.empty()) {
			int c = q.front();
			q.pop();
			for(int j = 0; j < 26; j++){
				if( v[j] || (g[c][j] == 0)) continue;
				q.push(j);
				v[j] = 1;
			}
		}
		for(int j = 0; j < 26; j++){
			if( v[j]) {
				g[i][j] = 1;
			}
			v[j] = 0;
		}
	}
}
