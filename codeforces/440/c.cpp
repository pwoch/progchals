#include <iostream>
#include <algorithm>
#include <vector>

#define MAX (int)1e4 + 1 

using namespace std;
vector<int> v(MAX, 0);

int main() {
  int i;
  v[1] = v[2] = v[3] = -1;
  for (int i=2; i<MAX; i++) {
    if (v[i] == 1) continue;
    for (int j=2; j*i<MAX; j++) {
      v[j*i] = 1; 
    }
  }
  int q, tmp;
  int fac1=0, fac2=0;
  cin >>q; 
  for (int i=0; i < q; i++) {
    cin>> tmp;
    for (int i=2; i<MAX;) { 
      if (v[i] == 1) continue;
      cout<<i<<endl;
      if (tmp%i == 0) {
        if (fac1==0) { 
          fac1 = i;
        } else {
          fac2 = i;
          break;
        }
        continue;
      }
      i++;
    }
    if (fac2 == 0) cout<<-1<<endl;
    else cout<<tmp/(fac1*fac2)<<endl;
  }

}
