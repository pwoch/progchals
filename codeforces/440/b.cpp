#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >>n >>k;
  int tmp, res;
  if (k == 1) {
    res = (int) 2e9;
    for (int i=0; i<n; i++) {
      cin >>tmp;
      res = min(res,tmp);
    }
  } else {
    res = (int) -2e9;
    for (int i=0; i<n; i++) {
      cin >>tmp;
      res = max(res,tmp);
    }
  }
  cout<<res<<endl;
  
}
