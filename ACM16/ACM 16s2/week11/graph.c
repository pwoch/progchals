
#include <stdio.h>
#include <stdlib.h>

typedef struct _graph *Graph;
typedef struct _link *Link;
typedef struct _stack *Stack;

struct _graph{
	Link* l;
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

Link newNode(int vx, int wt){
	Link l = malloc(sizeof(struct _link));
	l->next = NULL;
	l->v = vx;
	l->w = wt;
	return l;
}
Stack newStack(){
	Stack s = malloc(sizeof(struct _stack));
	return s;
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
	Link l = newNode(v, 0);
	l->next = s->top;
	s->top = l;
}

int isEmpty(Stack s){
	return s->top == NULL;
}


Graph newGraph(int nv){
	Graph g = malloc(sizeof(struct _graph));
	int i ;
	g->l = malloc(sizeof(struct _link)*nv);
	g->nV = nv;
	for( i = 1; i < nv; i++){
		g->l[i] = NULL;
	}
	return g;
}


//adds edge from v1 to v2
void addEdge(Graph g, int v1, int v2, int wt) {
	Link l = newNode(v2, wt);
	l->next = g->l[v1];
	g->l[v1] = l;
}

void showGraph(Graph g){
	int i;
	Link l;
	for( i = 1; i < g->nV; i++) {
		//printf("[%d] links to: ", i);
		for( l = g->l[i]; l != NULL; l = l->next) {
			//printf("[%d,(%d)], ", l->v, l->w);
		}
		//printf("X\n");
	}
}

int bfs(Graph g, int* best, int T) {
	int* parent = malloc(sizeof(int)*g->nV);
	int* path = malloc(sizeof(int)*g->nV);
	int i,j, v, found;
	int cost = 0;
	int count = 0;
	int max = 0;
	Link l;
	Stack s = newStack();
	for( i = 1; i < g->nV; i++) {
		parent[i] = 0;
	}
	push(s,1);
	found = 1;
	parent[1] = 1;
	while(!isEmpty(s)){
		v = s->top->v;
		//printf("exploring %d, parent: %d, cost: %d \n", v,parent[v], cost);
		if( v!= 1) {
			for( l = g->l[parent[v]]; l->v != v; l = l->next);
			cost += l->w;
		}
		//printf("exploring %d, cost: %d \n", v, cost);
		if( v == g->nV-1) {
			//printf("Found %d on path: ", v);
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
					//printf("%d\n", best[i]);
				}
			}
			//printf("\ncost: %d\n",cost);

			for( l = g->l[parent[v]]; l->v != v; l = l->next);
			cost -= l->w;
			pop(s);
			v = s->top->v;
		}
		found = 0;
		for( l = g->l[v]; l != NULL; l = l->next){
			if( l->v != (g->nV-1) && parent[l->v] != 0) 
				continue;
			if( parent[l->v] == v) 
				continue;
			if( cost + l->w > T) 
				continue;
			found = 1;
			parent[l->v] = v;
			push(s, l->v);
			//printf("\tfound %d\n", l->v);
		}
		if( !found) {
			int del = pop(s);
			if( v != 1) {
			for( l = g->l[parent[del]]; l->v != del; l = l->next);
			cost -= l->w;
			}
			//printf("Exhausted %d, cost: %d\n\n", del, cost);
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
	showGraph(g);
	int best[5001];
	int result = bfs(g, best, tMax);
	printf("%d\n", result);
	for( i = result-1; i >= 0; i--) {
		printf("%d ", best[i]);
	}
	printf("\n");

	return;
}




