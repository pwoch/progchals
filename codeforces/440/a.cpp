#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int a,b;
  int l1 = 20, l2 = 20;
  cin >>a>>b;
  int tmp;
  for (int i=0; i<a;i++) {
    cin>>tmp;
    l1 = min(l1,tmp);
  }
  
  for (int i=0; i<b;i++) {
    cin>>tmp;
    l2 = min(l2,tmp);
  }
  if (l1 != l2) 
    cout<< min(l1,l2)<<max(l1,l2)<<endl;
  else 
    cout <<l1<<endl;
  

  return 0;
}
