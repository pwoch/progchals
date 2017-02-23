
#include <stdio.h>
#include <stdlib.h>

#define MAX 10010

typedef struct node *Node;


typedef struct _set{
    Node head;
    Node end;
}set;

struct node{
    int v;
    Node prev;
};

set join(set a, set b) {
    b.head->prev = a.end;
    a.end = b.end;
    return a;
}

int rank[MAX];
int depth(Node);
int max(int a, int b) {
    return (a>b) ? a : b;
}

set a[MAX];
struct node b[MAX];

int main() {
    int N;
    scanf("%d",&N);
    int i;
    for (i = 1; i <= N; i++) {
        rank[i] = -1;
        b[i].v = i;
        b[i].prev = NULL;
        a[i].head = &b[i];
        a[i].end = &b[i];
    }
    rank[1] = 0;
    int tmp;
    for (i = 2; i <= N; i++) {
        scanf("%d",&tmp);
        a[tmp] = join(a[tmp],a[i]);
    }
    int ans = 0;
    for (i = 1; i <= N; i++) {
        ans = max(ans, depth(&b[i]));    
    }
    printf("%d\n",ans);

    return 0;
}

int depth(Node t) {
    if (t) {
        if (rank[t->v] != -1) {
            return rank[t->v];
        } else {
            rank[t->v] = depth(t->prev)+1;
            return rank[t->v];
        }
    }

}
