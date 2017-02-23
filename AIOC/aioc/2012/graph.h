
typedef struct GraphRep *Graph;
typedef struct EdgeRep *Edge;

typedef int Vertex;


struct EdgeRep{
    Vertex v;
    Vertex w;
};


struct GraphRep{
    //Array of edges
    Edge* edges;
    int numV;
    int numE;
};


//Input is number of vertices
Graph newGraph(int nV){
    Graph new = malloc(sizeof(struct GraphRep));
    new->edges = malloc(sizeof(struct GraphRep)*nV);
    edges = NULL;
    numV = nV;
    numE = 0;

    return new;
}


int validG(Graph g);
int validV(Graph g, Vertex v);
int validE(Graph g, Edge e);
Graph newGraph(int nV);
Graph disposeGraph(Graph g);

