
#include <stdio.h>
#include <stdlib.h>

typedef struct queueRep *Queue;
typedef struct node *Node;
typedef struct GraphRep *Graph;

typedef int Vertex;

typedef struct EdgeRep *Edge;
typedef struct HeadRep *Head;

struct EdgeRep{
    Vertex to;
    Edge next;
};

struct HeadRep{
    Edge first;
};

struct GraphRep{
    //Linked list of connecting vertices
    Head* edges;
    int numV;
    int numE;
};

struct queueRep{
    Node head;
    int data;
    int size;
};
struct node{
    Node next;
    int v;
};

int values[10001];


Queue newQueue(){
    Queue new = malloc(sizeof(struct queueRep));
    new->head = NULL;
    new->size = 0;
    return new;
}

int isEmpty(Queue q) {
    return q->size == 0;
}

void queueEnter(Queue q, int n) {
    Node new = malloc(sizeof(struct node));
    new->v = n;
    new->next = NULL;
    if( q->head ){
        Node iter = q->head;
        while( iter->next) {
            iter = iter->next;
        }
        iter->next = new;
    } else {
        q->head = new;
    }
    q->size++;
}

int queueLeave(Queue q) {
    int value;
    if( q->head){
        value = q->head->v;
        q->head = q->head->next;
        q->size--;
    } else {
        value = -1;
    }
    return value;
}

void showQueue(Queue q){
    printf("Queue contains: \n");
    Node iter = q->head;
    while( iter) {
        printf("%d, ", iter->v+1);
        iter = iter->next;
    }
    printf("X\n");
}

//Input is number of vertices
Graph newGraph(int nV){
    Graph new = malloc(sizeof(struct GraphRep));
    new->edges = malloc(sizeof(struct HeadRep)*nV);
    int i = 0;
    for( i = 0; i <  nV; i++) {
        new->edges[i] =  malloc(sizeof(struct HeadRep));
        new->edges[i]->first = NULL;
    }
    new->numV = nV;
    new->numE = 0;

    return new;
}


void addLink(Graph g, Vertex begin, Vertex end){

    Edge new = malloc(sizeof(struct EdgeRep));
    new->to = end;
    new->next = NULL;

    Head start = g->edges[begin];
    Edge prev = NULL;
    Edge curr = start->first;

    if( curr == NULL) {
        //Insert at front
        start->first = new;
        g->numE++;
        //printf("Added link from %d to %d\n", begin, end);

    } else {

        int duplicate = 0;
        //Insert in correct order
        while( curr && curr->to < end) {
            if( curr->to == end) {
                duplicate = 1;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if( !duplicate) {
            //Insert between prev and curr
            if( prev ) {
                new->next = curr;
                prev->next = new;
            } else {
                new->next = curr;
                start->first = new;
            }
            g->numE++;
            //printf("Added link from %d to %d\n", begin, end);
        } else {
            //printf("Connection already exists\n");
        }
    }
    //If graph is directed then there must be even number of edges
    if( g->numE%2) {
        addLink(g, end, begin);
    }
}

void showGraph(Graph g) {
    int i;
    Edge iter;
    Head start;
    for( i = 0; i < g->numV; i++){
        start = g->edges[i];
        printf("[%d ($%d)] links to: ", i, values[i]);
        iter = start->first;
        while( iter) {
            printf("%i ($%d), ", iter->to, values[iter->to]);
            iter = iter->next;
        }
        printf("X\n");
    }
}


int sumEachComponent(Graph g) {
    
    //Run through BFS for each component and add the value of each node visited

    int visited[10001] = {0};
    int i = 0;
    Vertex v;
    Edge iter;
    for( i = 0; i < g->numV; i++) {
        if( visited[i] == 1) continue; 

        int total = 0;
        Queue BFS = newQueue();
        queueEnter(BFS, i);
        total += values[i];
        //printf("Checking connections for vertex %d\n", i);
        while( !isEmpty(BFS)){

            v = queueLeave(BFS);
            visited[v] = 1;

            for( iter = g->edges[v]->first; iter != NULL; iter = iter->next) {
                if( visited[iter->to] == 1) continue;
                visited[iter->to] = 1;
                total += values[iter->to];
                //printf("Visited %d, adding %d to total: %d\n", iter->to, values[iter->to], total);
                queueEnter(BFS, iter->to);
            }
            //printf("total = %d\n", total);
        }
        if( total != 0) {
            return 0;
        }
    }
    return 1;
}



int main() {

    int size, numPairs, i;
    scanf("%d %d", &size, &numPairs);
    Graph g = newGraph(size);
    Vertex v, w;
    for( i = 0; i < size; i++) {
        scanf("%d", &values[i]);
    }

    for( i = 0; i < numPairs; i++) {
        scanf("%d %d", &(v), &(w));
        addLink(g, v, w);
    }

    //showGraph(g);   

    int diff = sumEachComponent(g);
    if( diff) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

