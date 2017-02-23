
#include <stdio.h>
#include <stdlib.h>

typedef struct _graph *Graph;
typedef struct _link *Link;
typedef struct _stack *Stack;

struct _graph{
	int** a;
	int nV;
};

struct _link{
	int v;
	int w;
	Link next;
};

struct _stack{
	Link top;
};

Link newNode(int vx){
	Link l = malloc(sizeof(struct _link));
	l->next = NULL;
	l->v = vx;
	return l;
}
Stack newStack(){
	Stack s = malloc(sizeof(struct _stack));
	return s;
}
int isEmpty(Stack s){
	return s->top == NULL;
}

int pop(Stack s){
	if( isEmpty(s)) return -1;
	Link tbd = s->top;
	s->top = s->top->next;
	int result = tbd->v;
	free(tbd);
	return result;
}

void push(Stack s, int v){
	Link l = newNode(v);
	l->next = s->top;
	s->top = l;
}



Graph newGraph(int nv){
	Graph g = malloc(sizeof(struct _graph));
	int i, j;
	g->a = malloc(sizeof(int)*nv);
	g->nV = nv;
	for( i = 1; i < nv; i++){
		g->a[i] = malloc(sizeof(int)*nv);;
		for( j = 1; j < nv; j++) g->a[i][j] = 0;
	}
	return g;
}


//adds edge from v1 to v2
void addEdge(Graph g, int v1, int v2, int wt) {
	g->a[v1][v2] = wt;
}

void showGraph(Graph g){
	int i, j;
	printf("    ");
	for( i = 1; i < g->nV; i++) printf("%4d",i);
	printf("\n");
	for( i = 1; i < g->nV; i++) {
		printf("[%d]: ", i);
		for( j = 1; j < g->nV; j++) {
			printf("[%d], ",g->a[i][j]);
		}
		printf("\n");
	}
}

int dfs(Graph g, int* best, int T) {
	int* parent = malloc(sizeof(int)*g->nV);
	int* path = malloc(sizeof(int)*g->nV);
	int i, j, v, found;
	int cost = 0;
	int count = 0;
	int max = 0;
	Stack s = newStack();
	for( i = 1; i < g->nV; i++) {
		parent[i] = 0;
	}
	push(s,1);
	found = 1;
	parent[1] = 1;
	while(!isEmpty(s)){
		v = s->top->v;

		if( v != 1) cost += g->a[parent[v]][v];

		//If we've reached destination trace back the path and compare to best
		if( v == g->nV-1) {
			j = v;
			count = 0;
			while( j != 1){
				path[count++] = j;
				j = parent[j];
			}
			path[count++] = 1;

			if( count > max) {
				max = count;
				for( i = 0; i < count; i++) {
					best[i] = path[i];
				}
			}
			cost -= g->a[parent[v]][v];
			pop(s);
			v = s->top->v;
		}

		found = 0;
		for( j = 1; j < g->nV; j++){
			if( (j != (g->nV-1) && parent[j] != 0) || g->a[v][j] == 0) 
				continue;
			if( parent[j] == v) 
				continue;
			if( cost + g->a[v][j] > T) 
				continue;
			found = 1;
			parent[j] = v;
			push(s, j);
		}

		if( !found) {
			//if nothing left to explore remove from stack and subtract cost
			int del = pop(s);
			if(v!= 1) cost -= g->a[parent[del]][del];
		}
	}
	return count;
}


int main(){
	int nv, ne, tMax;
	scanf("%d %d %d", &nv, &ne, &tMax);
	Graph g = newGraph(nv+1);
	int i, v1, v2, w;
	for( i = 0; i < ne; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		addEdge(g, v1, v2, w);
	}
	int best[5001];
	int result = dfs(g, best, tMax);
	printf("%d\n", result);
	for( i = result-1; i >= 0; i--) {
		printf("%d ", best[i]);
	}
	printf("\n");

	return 0;
}




