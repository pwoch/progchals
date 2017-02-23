#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
   unsigned int n, a;
   scanf("%d",&n);
   vector<unsigned int> p1;
   vector<unsigned int> p2;
   vector<unsigned int> p3;
   vector<unsigned int> p4;
   vector<unsigned int> aliens(n);
   
   for(unsigned int x = 0; x < n; x++){
      int bleh;
      scanf("%d",&bleh);
      aliens[x] = bleh;
   }
   sort(aliens.rbegin(),aliens.rend());
   
   for(unsigned int x = 0; x < n; x++){
      // each alien
      a = aliens[x];
      if(a > p2.size()){
         p2.push_back(a);
      } else {
         if(a > p3.size()){
            p3.push_back(a);
         } else {
            if(a <= p4.size()){
               printf("-1\n");
               return 0;
            } else {
               if(p2[0] > (p3.size() + p2.size()) ){
                  p1.push_back(a);
               } else {
                  p4.push_back(a);
               }
            }
         }
      }
   }
   
   if(p4.size() && p1.size()){
      printf("-1\n");
      return 0;
   }
   if(p2.size() > 0){
   if(p2[0] > (p1.size() + p2.size() + p3.size())){
      
               printf("-1\n");
               return 0;   
   }}
   
   if(p3.size() > 0){
   if(p3[0] > (p2.size() + p3.size() + p4.size())){
      
               printf("-1\n");
              return 0;
   }}
   if(p1.size() > 0){
   if(p1[0] > (p1.size() + p2.size()) ){
   
               printf("-1\n");
               return 0;
   }}
   
   if(p4.size() > 0){
   if(p4[0] > (p3.size() + p4.size())){
      printf("-1\n");
               return 0;
   }}
   
   
   if(p1.size() > 0){
         unsigned int answer = max(p1.size(), p3.size());
       printf("%d\n",answer);
   } else {
    unsigned int answer = max(p4.size(), p2.size());
    printf("%d\n",answer);
   }
   
   return 0;
}
