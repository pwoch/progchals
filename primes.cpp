#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 647

int a[MAX+1];

using namespace std;

int main() {

  long long i,j;
  for (i=0; i<MAX; i++) {
    a[i]=1;
  }
  for (i=2; i<MAX;i++) {
    if (a[i]) {
      for (j=i*i; j<MAX; j+=i) {
        a[j] = 0;
      }
    }
  }

  long long x = 0;
  for (i = 2; i < MAX; i++) {
    if (a[i]) {
      cout << i << endl;
      x++;
    }
  }
  cout<< "num: "<< x<<endl;

  return 0;
}
