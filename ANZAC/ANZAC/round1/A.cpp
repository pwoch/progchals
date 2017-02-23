#include <cstdio>
#include <vector>

using namespace std;
int main(){
   int dice, hp, overkill;
   scanf("%d%d%d",&dice, &hp, &overkill);
   if(hp > 60){
      printf("WELL WE TRIED\n");
      return 0;
   }
   vector<int> die(dice);
   double best = 0;// probability
   int best1 = -1;
   int best2 = -1;
   for(int x = 0; x < dice; x++){
      scanf("%d",&die[x]);
   }
   for(int x = 0; x < dice; x++){
      for(int y = x; y < dice; y++){
         if(x != y){
            if(die[x] + die[y] >= hp){
               int highScore = 0;
               for(int a = 1; a <= die[x]; a++){
                  for(int b = 1; b <= die[y]; b++){
                     
                        if(a+b >= hp && a+b <= (hp+overkill)){
                           highScore++;
                        }
                     
                  }
               }
               double probability = (double)highScore/((double)die[x] * (double)die[y]);
               //printf("%f\n", probability);
               if(probability > best){
                  best = probability;
                  best1 = x;
                  best2 = y;
               }
            }
         }
      }
   }
   if(best1 == -1){
      printf("WELL WE TRIED\n");
      return 0;
   }
   printf("d%d d%d\n",die[best1],die[best2]);
   return 0;
}
