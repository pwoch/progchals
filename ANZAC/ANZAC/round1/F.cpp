#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef struct _node{
   vector<struct _node *> nexts;
}node;

typedef struct _check{
   int path[];
   int max;
} check;

int main(){
   int c,r;
   scanf("%d%d",&c,&r);
   vector<node> cities(c);
   map<int, map<int, int> > distance;
   for(int x = 0; x < r; x++){
      int c1,c2,d;
      scanf("%d%d%d",&c1,&c2,&d);
      cities[c1].nexts.push_back(cities[c2]);
      cities[c2].nexts.push_back(cities[c1]);
      distance[c1][c2] = d;
      distance[c2][c1] = d;
   }
   priority_queue<int, >
   while(true){
      
      // make a bunch of paths and store them in a priority queue
      
   }

   return 0;
}

