#include <iostream>

int bois[110];
int girls[110];

using namespace std;

int main() {
  int n,m;
  cin >>n >>m;
  if (n%m == 0) n=m;
  if (m%n == 0) m=n;
  int b, g;
  int tmp;
  
  cin >>b;
  for (int i=0; i<b; i++) {
    cin >>tmp;
    if (bois[tmp]) continue;
    int rep = tmp%n;
    do {
      bois[rep] = 1;
      rep = (rep+m)%n;
    } while (rep != tmp%n);
  }
  cin >>g;
  for (int i=0; i<g; i++) {
    cin >>tmp;
    if (girls[tmp]) continue;

    int rep = tmp%n;
    do {
      girls[rep] = 1;
      rep = (rep+n)%m;
    } while (rep != tmp%n);
  }

  for (int i=0; i< min(n,m); i++) {
    if (!bois[i] && !girls[i]) {
      cout <<"No\n";
      return 0;
    }
  }
  cout<< "Yes\n";
}
