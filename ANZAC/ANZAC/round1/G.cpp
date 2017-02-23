#include <cstdio>

int main(){

   int n,m;
   scanf("%d%d",&n,&m);
   if(n%2 == 1){
      printf("1\n");
      return 0;
   }
   if(m%2 == 1){
      printf("1\n");
      return 0;
   }
   printf("2\n");
   return 0;
}
