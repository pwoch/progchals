#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>

#define MAX 5002

using namespace std;

vector<int> best(MAX);
vector<vector<int> > g(MAX);

int nv, ne, tMax;
int dfs();

int main() {
	int i;
	for( i = 0; i < MAX; i++) {
		g[i].resize(MAX,0);
	}
	cin >>nv >>ne >>tMax;

	int v1, v2, wt;
	for( i = 0; i < ne; i++){
		cin >>v1 >>v2 >>wt; 
		g[v1][v2] = wt;
	}
	int result = dfs();
	cout<< result<<endl;
	for( i = result-1; i >= 0; i--) {
		cout<< best[i]<<' ';
	}
	cout<<endl;
	return 0;
}

int dfs(){
	vector<int> parent(MAX,0);
	vector<int> path(MAX, 0);
	int i, v, found;
	int cost = 0;
	int count, max = 0;
	stack<int> s;
	s.push(1);
	found = 1;
	parent[1] = 1;
	while( !s.empty()) {
		v = s.top();
		if( v != 1) cost += g[parent[v]][v];
		if( v == nv) {
			i = v;
			count = 0;
			while( i != 1){
				path[count++] = i;
				i = parent[i];
			}
			path[count++] = 1;
			if( count > max) {
				max = count;
				for( i = 0; i < count; i++) {
					best[i] = path[i];
				}
				cost -= g[parent[v]][v];
				s.pop();
				v = s.top();
			}
		}
		found = 0;
		for( i = 1; i <= nv; i++) {
			if( (i != nv && parent[i] != 0) || g[v][i] == 0) {
				continue;
			}
			if( parent[i] == v || cost + g[v][i] > tMax){
				continue;
			}
			found = 1;
			parent[i] = v;
			s.push(i);
		}
		if( !found) {
			int del = s.top();
			if( del != 1) cost -= g[parent[del]][del];
			s.pop();
		}
	}
	return max;
}

